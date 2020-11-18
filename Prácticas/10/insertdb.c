#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    unsigned index;
    Student myStudent;

    printf("index: ");
    scanf("%d", &index);
    printf("id: ");
    scanf("%d", &myStudent.id);
    printf("firstName: ");
    scanf("%s", myStudent.firstName);
    printf("lastName: ");
    scanf("%s", myStudent.lastName);
    printf("semester: ");
    scanf("\n%c", &myStudent.semester);

    int fd = open(dbName, O_WRONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd, offset, SEEK_SET);
    write(fd, &myStudent, sizeof(Student));
    close(fd);
    return 0;

}