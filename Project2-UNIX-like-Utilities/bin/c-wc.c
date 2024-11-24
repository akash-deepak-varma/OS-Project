// custom_wc.c
#include <stdio.h>

char dir[128] = "/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities";

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: custom_wc <file>\n");
        return 1;
    }

    char path[1024];
    snprintf(path ,sizeof(path) ,"%s/%s" ,dir ,argv[1]);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("custom_wc: Could not open file");
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') lines++;
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(file);
    printf("Lines: %d Words: %d Characters: %d\n", lines, words, characters);
    return 0;
}

