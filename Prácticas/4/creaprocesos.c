#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int signum) {
    int status;
    wait(&status);
    printf("Mi hijo termino con status %d \n", status);
}

int main(int argc, char **argv) {
    signal(17, signalHandler);
    unsigned pid = fork();
    if(pid==0) {
        sleep(5);
        printf("Soy el proceso hijo \n");
        return 10;
    } else {
        printf("Soy el proceso padre y mi hijo es %u \n", pid);
        while (1) {
            sleep(2);
            printf("Trabajando \n");
        }
    }
    printf("Hola Mundo \n");
    return 0;
}