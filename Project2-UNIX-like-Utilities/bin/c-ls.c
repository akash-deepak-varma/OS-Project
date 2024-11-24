// custom_ls.c
#include <stdio.h>
#include <dirent.h>
#include "getpath.h"

int main(int argc, char *argv[]) {
    char* default_dir = "/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities";
    if(strcmp(getPath() ,default_dir)==0){
        printf("yes yesy yej\n");
    }

    printf("defaultx-%s\n" ,getPath());
    const char *dir_name = argc > 1 ? argv[1] : default_dir;  // Use provided directory or current directory by default
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

