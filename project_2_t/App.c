#include <stdio.h>
#include <stddlib.h>

void print(onst vhar *text) {
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
            print("grand child");
        } else {
            print("child");
        }
    } else {
        print("parent");
    }
    return 0;
}
