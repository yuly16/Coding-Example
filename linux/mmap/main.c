#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char filepath[] = "hello.txt";
    int fd = open(filepath, O_RDONLY);
    if(fd < 0) {
        printf("%s couldn't open. \n", filepath);
        exit(1);
    }
    struct stat statbuf;
    int err = fstat(fd, &statbuf);
    if(err < 0) {
        printf("%s couldn't open. \n", filepath);
        exit(1);
    }
    printf("The size of file is: %ld\n", statbuf.st_size);

    char *ptr = mmap(NULL,statbuf.st_size,
        PROT_READ|PROT_WRITE, MAP_PRIVATE,
        fd, 0);
    if(ptr == MAP_FAILED){
        printf("Mapping Failed\n");
        exit(1);
    }
    close(fd);

    for(int i = 0; i < statbuf.st_size; i++) {
        printf("%c", *(ptr + i));
    }
    printf("\n");

}