#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define CMD 100
#define MAX 10

void execute_command(char *cmd) {
    char *args[MAX];
    int i = 0;
    args[i] = strtok(cmd, " ");
    while (args[i] != NULL && i < MAX - 1) {
        args[++i] = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(cmd, "clear") == 0) {
        printf("\033[2J\033[H");
        return;
    }

    if (fork() == 0) {
        char cmd_path[100];
        snprintf(cmd_path, sizeof(cmd_path), "./%s", args[0]);
        if (execvp(cmd_path, args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else {
        wait(NULL);
    }
}

int main() {
    char cmd[CMD];
    const char* GREEN_TEXT = "\033[1;32m";  
    const char* BLUE_BG = "\033[1;44m";     
    const char* RESET = "\033[0m"; 
    const char* GREEN_BG = "\033[48;5;22m";

    fputs(GREEN_TEXT, stdout);

    printf(" _____                                                                            _____ \n");
    printf("( ___ )                                                                          ( ___ )\n");
    printf(" |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf(" |   | ▄▄▄█████▓▓█████  ██▀███   ███▄ ▄███▓ ██▓ ███▄    █  ▄▄▄       ██▓     ▐██▌ |   | \n");
    printf(" |   | ▓  ██▒ ▓▒▓█   ▀ ▓██ ▒ ██▒▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▒████▄    ▓██▒     ▐██▌ |   | \n");
    printf(" |   | ▒ ▓██░ ▒░▒███   ▓██ ░▄█ ▒▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██  ▀█▄  ▒██░     ▐██▌ |   | \n");
    printf(" |   | ░ ▓██▓ ░ ▒▓█  ▄ ▒██▀▀█▄  ▒██    ▒██ ░██░▓██▒  ▐▌██▒░██▄▄▄▄██ ▒██░     ▓██▒ |   | \n");
    printf(" |   |   ▒██▒ ░ ░▒████▒░██▓ ▒██▒▒██▒   ░██▒░██░▒██░   ▓██░ ▓█   ▓██▒░██████▒ ▒▄▄  |   | \n");
    printf(" |   |   ▒ ░░   ░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░▓  ░ ░▀▀▒ |   | \n");
    printf(" |   |     ░     ░ ░  ░  ░▒ ░ ▒░░  ░      ░ ▒ ░░ ░░   ░ ░░  ▒   ▒▒ ░░ ░ ▒  ░ ░  ░ |   | \n");
    printf(" |   |   ░         ░     ░░   ░ ░      ░    ▒ ░   ░   ░ ░   ░   ▒     ░ ░       ░ |   | \n");
    printf(" |   |             ░  ░   ░            ░    ░           ░       ░  ░    ░  ░ ░    |   | \n");
    printf(" |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n");
    printf("(_____)                                                                          (_____) \n");

    fputs(RESET, stdout);
    printf("\n");
    printf("%s Welcome to my_shell! Type 'exit' to quit.%s\n", GREEN_BG, RESET);
    printf("\n");
    while (1) {
        printf("%s MyShell>%s ", GREEN_BG, RESET);
        if (fgets(cmd, CMD, stdin) == NULL) {
            break;
        }
        
        cmd[strcspn(cmd, "\n")] = '\0';
        
        if (strcmp(cmd, "exit") == 0) {
            break;  
        }
        
        execute_command(cmd);
    }
    return 0;
}

