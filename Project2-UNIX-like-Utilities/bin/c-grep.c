// custom_grep.c
#include <stdio.h>
#include <string.h>

#include "getpath.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: custom_grep <pattern> <file>\n");
        return 1;
    }

    char* default_dir = getPath();
    char path[1024];

    snprintf(path ,sizeof(path) ,"%s/%s" ,default_dir ,argv[2]);

    const char *pattern = argv[1];
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        perror("custom_grep: Could not open file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}

