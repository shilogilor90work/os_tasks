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
