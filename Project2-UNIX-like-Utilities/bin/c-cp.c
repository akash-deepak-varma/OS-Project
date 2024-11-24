// custom_cp.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: custom_cp <source> <destination>\n");
        return 1;
    }

    char* default_dir = "/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities";
    char path1[1024];
    char path2[1024];

    snprintf(path1 ,sizeof(path1) ,"%s/%s" ,default_dir ,argv[1]);
    snprintf(path2 , sizeof(path2) ,"%s/%s" ,default_dir ,argv[2]);

    FILE *src = fopen(path1, "r");
    FILE *dest = fopen(path2, "w");

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

