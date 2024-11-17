// custom_cp.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: custom_cp <source> <destination>\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");

    if (src == NULL || dest == NULL) {
        perror("custom_cp: Could not open file");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return 1;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

