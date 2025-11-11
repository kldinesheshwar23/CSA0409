#include <stdio.h>
int main(){
    int parent_pid = 1001;  // Simulated parent process ID
    int child_pid = 1002;   // Simulated child process ID

    printf("Simulating process creation using only stdio.h\n\n");

    printf("Parent Process:\n");
    printf("  Process ID (PID): %d\n", parent_pid);

    printf("\nCreating a new process...\n\n");

    printf("Child Process:\n");
    printf("  Process ID (PID): %d\n", child_pid);
    printf("  Parent Process ID (PPID): %d\n", parent_pid);

    return 0;
}

