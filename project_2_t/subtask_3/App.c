
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


int main() {
    pid_t pid = fork();
    if (pid==0) {
        chdir("/");
        setsid();
        printf("starting daemon");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("daemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "started");
        usleep(3000000);
        syslog(LOG_NOTICE, "doing....");
        usleep(3000000);
        syslog(LOG_NOTICE, "finished");

    } else {
        printf("Daemon PID %d\n", pid);
    }
    return 0;
}
