#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *file_pointer = NULL;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;

    char *word = argv[1];

    if( argc <= 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    
    // handle grep from stdin
    if(argc == 2){
        // infinite handle until get sig
        file_pointer = stdin;

        while ((linelen = getline(&line, &linecap, file_pointer)) > 0){
            if(strstr(line,word) != NULL){
                printf("%s", line);
            }
        }

        return 0;
    }
    // handle grep from file
    for (int i = 2; i < argc; i++) {
        file_pointer = fopen(argv[2], "r");

        if (file_pointer == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }

        while ((linelen = getline(&line, &linecap, file_pointer)) > 0){
            if(strstr(line,word) != NULL){
                printf("%s", line);
            }
        }

        // close file
        if(fclose(file_pointer) != 0) {
            printf("wcat: cannot close file\n");
            strerror(errno);
            exit(0);
        }
    }

    return 0;
}