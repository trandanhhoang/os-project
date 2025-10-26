#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void writeFile(int count, char buf, FILE *out){
    // int net_count = htonl(count);
    // int host_count = htonl(count);
    // printf("Original count     : %d (0x%x)\n", count, count);
    // printf("Network byte order : %d (0x%x)\n", net_count, net_count);
    // printf("Back to host order : %d (0x%x)\n", host_count, host_count);
    
    // Original count     : 637534208 (0x26000000)
    // Network byte order : 38 (0x26)
    // Back to host order : 38 (0x26)

    fwrite(&count, 4, 1 ,out);
    fwrite(&buf, 1, 1 ,out);
}

int main(int argc, char *argv[]) {
    FILE *file_pointer;
    FILE *out = stdout;

    char buf, old_buf = '\0';
    int count = 1;

    if(argc <= 1){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        if ((file_pointer = fopen(argv[i], "r")) == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while(fread(&buf, 1, 1, file_pointer) != 0){
            if(buf == old_buf){
                count++;
            }else{
                if (old_buf != '\0'){
                    writeFile(count, old_buf, out);
                }
                count = 1;
                old_buf = buf;
            }
        }

        // close file
        if(fclose(file_pointer) != 0) {
            printf("wcat: cannot close file\n");
            strerror(errno);
            exit(0);
        }
    }

    if (count > 0){
        writeFile(count, buf, out);
    }

    return 0;
}