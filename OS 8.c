#include <stdio.h>

struct Process {
    int pid;        
    int arrival;   
    int burst;      
    int remaining;  
    int completion; 
    int turnaround; 
    int waiting;    
};

int main() {
    int n, quantum, time = 0, completed = 0,i;
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
        p[i].remaining = p[i].burst;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    int done;
    while (completed < n) {
        done = 1;

        for (i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                done = 0;

                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].completion = time;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    avg_wait += p[i].waiting;
                    avg_turnaround += p[i].turnaround;
                    completed++;
                }
            }
        }
        if (done)
            time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid,
               p[i].arrival, p[i].burst, p[i].completion,
               p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}

