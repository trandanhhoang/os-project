#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void writeFile(int count, char buf, FILE *out){
    for(int i =0; i< count;i++){
        fwrite(&buf, 1, 1 ,out);    
    }
}

int main(int argc, char *argv[]) {
    FILE *file_pointer;
    FILE *out = stdout;
    int count;
    char buf;

    if(argc <= 1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        if ((file_pointer = fopen(argv[i], "r")) == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while(fread(&count, 4, 1, file_pointer) != 0){
            if (fread(&buf, 1, 1, file_pointer) == 0){
                strerror(errno);
                exit(0);
            }
            writeFile(count, buf, out);
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

// int main(int argc, char *argv[]) {
//     FILE *file_pointer;
//     FILE *out = stdout;
//     char count[4];
//     char buf;

//     if(argc <= 1){
//         printf("wunzip: file1 [file2 ...]\n");
//         exit(1);
//     }

//     for(int i = 1; i < argc; i++){
//         if ((file_pointer = fopen(argv[i], "r")) == NULL) {
//             printf("wzip: cannot open file\n");
//             exit(1);
//         }

//         while(fread(count, 4, 1, file_pointer) != 0){
//             if (fread(&buf, 1, 1, file_pointer) == 0){
//                 strerror(errno);
//                 exit(0);
//             }
//             int value;
//             memcpy(&value, count, sizeof(value));
//             writeFile(value, buf, out);
//         }

//         // close file
//         if(fclose(file_pointer) != 0) {
//             printf("wcat: cannot close file\n");
//             strerror(errno);
//             exit(0);
//         }
//     }

//     return 0;
// }