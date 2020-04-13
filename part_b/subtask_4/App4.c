#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#define STACK_SIZE 10000
#define CYCLES 5
char child_stack[STACK_SIZE + 1];

void print(const char *text) {
    int i;
    for (i=0;i<25;i++) {
        printf("hi %s\n", text);
        usleep(1000000);
    }
}
int task_1(void *parmas)
{
    char* args[2] = {"./App1", NULL};
    execvp(args[0], args);
}

int task_2(void *parmas)
{
    char* args[2] = {"./App2", NULL};
    execvp(args[0], args);
    return 0;
}

int task_3(void *parmas)
{
    char* args[2] = {"./App3", NULL};
    execvp(args[0], args);
    return 0;
}

int main() {
    int result =clone(task_1,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result2 =clone(task_2,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result3 =clone(task_3,child_stack+STACK_SIZE,CLONE_PARENT,0);
    print("parent");
}


// #define _GNU_SOURCE
// #include <sched.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <syslog.h>
//
// #define STACK_SIZE 10000
// #define CYCLES 5
// char child_stack[STACK_SIZE + 1];
//
// void print(const char *text) {
//     int i;
//     for (i=0;i<25;i++) {
//         printf("hi %s\n", text);
//         usleep(1000000);
//     }
// }
// int child(void *parmas)
// {
//     print("child_thread");
// }
// int task_1(void *parmas)
// {
//     pid_t pid = fork();
//     if (pid==0) {
//         pid_t pid = fork();
//         if (pid==0) {
//             char* args[2] = {"./process2", NULL};
//             execvp(args[0], args);
//         } else {
//             char* args[2] = {"./process1", NULL};
//             execvp(args[0], args);
//         }
//     } else {
//         char* args[2] = {"./subtask_1", NULL};
//         execvp(args[0], args);
//         print("App");
//     }
//     return 0;
// }
//
// int task_2(void *parmas)
// {
//     char* args[2] = {"./subtask_2", NULL};
//     execvp(args[0], args);
//     int result =clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     int result2 =clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     print("parent_thread");
//     return 0;
// }
//
// int task_3(void *parmas)
// {
//     char* args[2] = {"./subtask_3", NULL};
//     execvp(args[0], args);
//     pid_t pid3 = fork();
//     if (pid3==0) {
//         chdir("/");
//         setsid();
//         printf("starting daemon");
//
//         close(stdout);
//         close(stdin);
//         close(stderr);
//
//         openlog("daemon", LOG_PID, LOG_DAEMON);
//         syslog(LOG_NOTICE, "started");
//         usleep(3000000);
//         syslog(LOG_NOTICE, "doing....");
//         usleep(3000000);
//         syslog(LOG_NOTICE, "finished");
//
//     } else {
//         print(pid3);
//     }
//     return 0;
// }
//
// int main() {
//     int result =clone(task_1,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     int result2 =clone(task_2,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     int result3 =clone(task_3,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     char* args[2] = {"./subtask_4", NULL};
//     execvp(args[0], args);
//     print("parent");
// }
