#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    unsigned pid = fork();
    if(pid==0) {
        printf("Soy el proceso hijo \n");
        execv(argv[1], &argv[1]);
        return 10;
    } else {
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        wait(&status);
        printf("Terminando después del hijo y estatus %d\n", status);
    }
    printf("Hola Mundo \n");
    return 0;
}