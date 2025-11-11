#include <stdio.h>
char shared_memory[100];
void parent_process() {
    printf("Parent Process: Writing data to shared memory...\n");
    sprintf(shared_memory, "Hello from Parent Process!");
    printf("Parent Process: Data written successfully.\n\n");
}
void child_process() {
    printf("Child Process: Reading data from shared memory...\n");
    printf("Child Process: Data read: %s\n", shared_memory);
}

int main() {
    printf("=== Inter-Process Communication using Shared Memory (Simulation) ===\n\n");
    parent_process();  
    child_process();    

    printf("\nSimulation completed successfully.\n");

    return 0;
}

