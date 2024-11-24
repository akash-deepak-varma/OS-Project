// custom_rm.c
#include <stdio.h>
#include <unistd.h>

char dir[128] = "/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities";

int main(int argc, char *argv[]) {
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

