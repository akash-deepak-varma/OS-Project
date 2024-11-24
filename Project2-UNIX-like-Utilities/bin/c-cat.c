#include <stdio.h>
#include"getpath.h"

int main(int argc, char *argv[]) {
    /*for(int i=0 ;argv[i] != NULL ;i++){
        printf("testcs-%s\n" ,argv[i]);
    }*/
    char dir[128] = getPath();
    char path[1024];
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    snprintf(path ,sizeof(path) ,"%s/%s" ,dir ,argv[1]);
    //printf("%s" ,path);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}

