#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dlfcn.h>


void (*hello_ariel)();

bool read_lib()
{
    void *myso = dlopen("./libhello.so", RTLD_LAZY);
    if (myso == NULL) {
        return false;
    }
    hello_ariel = (void(*)())dlsym(myso, "hello_ariel");
    if (hello_ariel == NULL) {
        return false;
    }
    return true;
}
int main() {
    if (read_lib()) {
        hello_ariel();
    }
    else {
        printf("lib not created yet!\n");
    }
    return 0;
}
