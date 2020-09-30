#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signum) {
    printf("Jaja no me matas :D \n");
}

int main() {
    signal(2, signalHandler);
    while (1) {
        sleep(2);
        printf("Trabajando \n");
    }
    return 0;
}