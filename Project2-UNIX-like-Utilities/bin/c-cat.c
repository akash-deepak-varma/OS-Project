#include <stdio.h>

int main(int argc, char *argv[]) {
    for(int i=0 ;argv[i] != NULL ;i++){
        printf("testcs-%s\n" ,argv[i]);
    }
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
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

