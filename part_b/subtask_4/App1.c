#include <stdio.h>
#include <stdlib.h>

void print(const char *text) {
    int i;
    for (i=0;i<3;i++) {
        printf("hi %s\n", text);
        usleep(1000000);
    }
}
int main() {
    pid_t pid = fork();
    if (pid==0) {
        pid_t pid = fork();
        if (pid==0) {
            char* args[2] = {"./process2", NULL};
            execvp(args[0], args);
        } else {
            char* args[2] = {"./process1", NULL};
            execvp(args[0], args);
        }
    } else {
        print("App");
    }
    return 0;
}
