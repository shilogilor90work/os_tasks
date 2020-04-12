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
        print("process2");
    return 0;
}
