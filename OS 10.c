#include <stdio.h>
#include <string.h>
char message_queue[5][100];  
int front = 0, rear = -1, count = 0;
void send_message(const char *message) {
    if (count == 5) {
        printf("Message Queue is full! Cannot send more messages.\n");
        return;
    }
    rear = (rear + 1) % 5;
    strcpy(message_queue[rear], message);
    count++;
    printf("Sender: Message \"%s\" sent to the queue.\n", message);
}
void receive_message() {
    if (count == 0) {
        printf("Receiver: No messages in the queue.\n");
        return;
    }
    printf("Receiver: Message received: \"%s\"\n", message_queue[front]);
    front = (front + 1) % 5;
    count--;
}

int main() {
    printf("=== Inter-Process Communication using Message Queue (Simulation) ===\n\n");
    send_message("Hello from Process 1!");
    send_message("How are you?");
    send_message("This is a message queue simulation.");
    
    printf("\n--- Receiver Process Reading Messages ---\n");
    receive_message();
    receive_message();
    receive_message();
    receive_message(); 

    printf("\nSimulation completed successfully.\n");

    return 0;
}

