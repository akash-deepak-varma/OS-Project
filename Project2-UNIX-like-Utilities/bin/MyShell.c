#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_CMD_LEN 100
#define MAX_ARGS 10

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    int i = 0;
    args[i] = strtok(cmd, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        args[++i] = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(cmd, "clear") == 0) {
        // Clear the screen and move the cursor to the top-left corner
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
    char cmd[MAX_CMD_LEN];
    printf("\033[1;34mWelcome to my_shell! Type 'exit' to quit.\033[0m\n");
    while (1) {
        printf("\e[1;44m MyShell>\e[0m ");
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
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
