#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char buffer[1024];

    // read a file as specified
    for (int i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        // print contents
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s hehe", buffer);
        }   

        // close file
        if(fclose(fp) != 0) {
            printf("wcat: cannot close file\n");
            strerror(errno);
            exit(1);
        }

    }

    return 0;
}