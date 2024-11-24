#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "getpath.h"



int main(int argc, char *argv[]) {
    char *dir = getPath();
    if (argc != 4) {
        fprintf(stderr, "Usage: custom_mv <source> <destination>\n");
        return 1;
    }

    char src[1024] , dest[1024];

    if(strcmp(argv[2] ,".") != 0){
        snprintf(src ,sizeof(src) ,"%s/%s/%s" ,dir ,argv[2] ,argv[1]);
    }
    else{
        snprintf(src ,sizeof(src) ,"%s/%s" ,dir ,argv[1]);
    }
    snprintf(dest ,sizeof(dest) ,"%s/%s" ,dir ,argv[3]);

    /*for(int i=0 ;argv[i] != NULL ;i++){
        printf("argv-%s\n" ,argv[i]);
    }*/

    printf("%s\n" ,src);
    printf("%s\n" ,dest);

    FILE *src_file = fopen(src, "rb");
    if (!src_file) {
        perror("custom_mv: Could not open source file");
        return 1;
    }

    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        perror("custom_mv: Could not open destination file");
        fclose(src_file);
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        if (fwrite(buffer, 1, bytes, dest_file) != bytes) {
            perror("custom_mv: Error writing to destination file");
            fclose(src_file);
            fclose(dest_file);
            return 1;
        }
    }

    fclose(src_file);
    fclose(dest_file);

    if (remove(src) != 0) {
        perror("custom_mv: Could not delete source file");
        return 1;
    }

    return 0;
}
