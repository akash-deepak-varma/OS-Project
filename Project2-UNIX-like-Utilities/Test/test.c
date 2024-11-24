#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LENGTH 1024

char *getPath() {
    FILE *file = fopen("/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities/bin/.env", "r");

    char* default_dir = "/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities";

    if (file == NULL) {
        perror("File not found:");
        exit(1);
    }

    char line[LENGTH];

    while (fgets(line, sizeof(line), file)) {
        // Skip comments and empty lines
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

            if(strcmp(default_dir ,value) == 0){
                printf("hdjjdsajdhjsadhjsd\n");
            }
        }
    }

    fclose(file);
    return NULL;
}

int main() {
    getPath();
    return 0;
}
