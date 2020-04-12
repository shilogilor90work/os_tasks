#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 5
char child_stack[STACK_SIZE + 1];

void print(const char *text) {
    int i;
    for (i=0;i<CYCLES;i++) {
        printf("hi %s\n", text);
        usleep(1000000);
    }
}
int child(void *parmas)
{
    print("child_thread");
}

int main() {
    // int result =clone(child,child_stack+STACK_SIZE,0,0);

    int result =clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result2 =clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
    print("parent_thread");
    return 0;
}
