#include <stdio.h>

struct Process {
    int pid;          
    int arrival;       
    int burst;         
    int priority;      
    int remaining;    
    int completion;    
    int turnaround;    
    int waiting;
	int i;       
};

int main() {
    int n, completed = 0, current_time = 0, highest_priority,i;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter details for Process %d:\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
    }
    while (completed != n) {
        highest_priority = -1;
        int index = -1;
        for (i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && p[i].remaining > 0) {
                if (highest_priority == -1 || p[i].priority < highest_priority ||
                   (p[i].priority == highest_priority && p[i].arrival < p[index].arrival)) {
                    highest_priority = p[i].priority;
                    index = i;
                }
            }
        }

        if (index != -1) {
        
            p[index].remaining--;
            current_time++;
            if (p[index].remaining == 0) {
                p[index].completion = current_time;
                p[index].turnaround = p[index].completion - p[index].arrival;
                p[index].waiting = p[index].turnaround - p[index].burst;
                avg_wait += p[index].waiting;
                avg_turnaround += p[index].turnaround;
                completed++;
            }
        } else {
            current_time++;
        }
    }
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}

