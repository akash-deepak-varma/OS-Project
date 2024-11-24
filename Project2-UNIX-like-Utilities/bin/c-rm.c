// custom_rm.c
#include <stdio.h>
#include <unistd.h>
#include "getpath.h"



int main(int argc, char *argv[]) {
    char *dir = getPath();
    if (argc < 2) {
        fprintf(stderr, "Usage: c-rm <file>\n");
        return 1;
    }

    char path[1024];
    snprintf(path ,sizeof(path) ,"%s/%s" ,dir ,argv[1]);

    if (remove(path) != 0) {
        perror("custom_rm: Could not delete file");
        return 1;
    }

    return 0;
}

