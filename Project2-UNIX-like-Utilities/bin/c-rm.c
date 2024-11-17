// custom_rm.c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: custom_rm <file>\n");
        return 1;
    }

    if (unlink(argv[1]) != 0) {
        perror("custom_rm: Could not delete file");
        return 1;
    }

    return 0;
}

