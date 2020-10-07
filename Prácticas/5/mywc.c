#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char c,
         buffer[250];
    unsigned i=0,
             total=0,
             chars=0,
             words=0,
             lines=0;
    while(read(STDIN_FILENO,&c,1)!=0) {
        if(c!=' ' && c!='\n') {
            buffer[i]=c;
            i++;
            chars++;
        } else if(c==' ') {
            buffer[i]='\0';
            words++; 
            i=0;
        } else if(c=='\n') {
            buffer[i]='\0';
            lines++;
            chars+=2;
            i=0;
        }
    }
    if(i!=0) {
        words++;
    }
    buffer[i]='\0';
    printf("* Tus carácteres son: %d \n", chars);
    printf("* Tus palabras son: %d \n", words);
    printf("* Tus líneas son: %d \n", lines);
    return 0;
}