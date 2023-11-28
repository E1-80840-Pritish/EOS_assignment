#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int count = 0;

    while (1) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            // Fork failed
            perror("fork");
            break;
        } else if (child_pid == 0) {
            // Child process
            exit(0);
        } else {
            // Parent process
            count++;
            printf("Child process created, count = %d\n", count);

            // Uncomment the following line to wait for each child process to exit
            // wait(NULL);
        }
    }

    printf("Maximum number of child processes created: %d\n", count);

    return 0;
}