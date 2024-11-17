// custom_ls.c
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *dir_name = argc > 1 ? argv[1] : ".";  // Use provided directory or current directory by default
    DIR *dir = opendir(dir_name);

    if (dir == NULL) {
        perror("custom_ls: Could not open directory");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}

