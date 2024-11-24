#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 1024

char *getPath() {
    FILE *file = fopen(".env", "r");

    if (file == NULL) {
        perror("File not found:");
        exit(1);
    }

    static char path[LENGTH];
    char line[LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        char *equal_sign = strchr(line, '=');
        if (equal_sign != NULL) {
            char *value = equal_sign + 1;
            value[strcspn(value, "\n")] = 0;

            if(value[0] == '"'){
                memmove(value ,value+1 ,strlen(value));
            }

            value[strlen(value)-1] = '\0';

            return value;
        }
    }

    fclose(file);
    return NULL;
}

