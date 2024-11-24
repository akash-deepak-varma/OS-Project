#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/file.h>

#define LENGHT 1024

char * getPath(){
    FILE *file = fopen("/home/akash/IIITDM/5th Sem/OS/Project/Project2-UNIX-like-Utilities/bin/.env" ,"r");

    if(file == NULL){
        perror("File not found:");
        exit(1);
    }

    char line[LENGHT];

    while(fgets(line ,sizeof(line) ,file)){
        if(line[0] == '#' || line[0] == '\n'){
            continue;
        }

        char *test = strchr(line ,'=');

        printf("test-%s ,,line-%s\n" ,test ,line);
    }
}


int main(){
    getPath();
}