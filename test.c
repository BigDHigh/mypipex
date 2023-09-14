#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int i, status;
    int pipe_fd[argc - 4][2];
    pid_t pid;

    // Create pipes
    for (i = 0; i < argc - 4; i++) {
        // Create a pipe for each intermediate command
        if (pipe(pipe_fd[i]) == -1) {
            // Print an error message if pipe creation fails
            perror("pipe");
            exit(1);
        }
        // Print the file descriptors for the pipe (for debugging purposes)
        printf("pipe_fd[%i][0]: %i pipe_fd[%i][1]: %i\n", i, pipe_fd[i][0], i, pipe_fd[i][1]);
    }

    // Fork child processes
    for (i = 0; i < argc - 3; i++) {
        pid = fork();
        if (pid == -1) {
            // Print an error message if fork fails
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            if (i == 0) {
                // First child process: read from input file and write to pipe 0
                close(pipe_fd[0][0]);
                dup2(open(argv[1], O_RDONLY), STDIN_FILENO);
                dup2(pipe_fd[0][1], STDOUT_FILENO);
            } else if (i == argc - 4) {
                // Last child process: read from pipe i-1 and write to output file
                close(pipe_fd[i-1][1]);
                dup2(open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
                dup2(pipe_fd[i-1][0], STDIN_FILENO);
            } else {
                // Intermediate child process: read from pipe i-1 and write to pipe i
                close(pipe_fd[i-1][1]);
                close(pipe_fd[i][0]);
                dup2(pipe_fd[i-1][0], STDIN_FILENO);
                dup2(pipe_fd[i][1], STDOUT_FILENO);
            }
            // Execute the command
            execlp(argv[i+2], argv[i+2], NULL);
            // Print an error message if execlp fails
            perror("exec");
            exit(1);
        }
    }

    // Close all file descriptors and wait for child processes to finish
    for (i = 0; i < argc - 4; i++) {
        close(pipe_fd[i][0]);
        close(pipe_fd[i][1]);
    }
    for (i = 0; i < argc - 3; i++) {
        waitpid(-1, &status, 0);
    }

    return 0;
}