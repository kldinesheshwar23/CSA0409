#include <stdio.h>

struct Process {
    int pid;        
    int arrival;    
    int burst;      
    int completion; 
    int turnaround; 
    int waiting;    
    int done;       
};

int main() {
    int n, current_time = 0, completed = 0, shortest_index,i;
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
        p[i].done = 0;
    }
    while (completed != n) {
        shortest_index = -1;
        for (i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && p[i].done == 0) {
                if (shortest_index == -1 || p[i].burst < p[shortest_index].burst)
                    shortest_index = i;
            }
        }

        if (shortest_index == -1) {
            current_time++;
        } else {
            current_time += p[shortest_index].burst;
            p[shortest_index].completion = current_time;
            p[shortest_index].turnaround = p[shortest_index].completion - p[shortest_index].arrival;
            p[shortest_index].waiting = p[shortest_index].turnaround - p[shortest_index].burst;

            avg_wait += p[shortest_index].waiting;
            avg_turnaround += p[shortest_index].turnaround;

            p[shortest_index].done = 1;
            completed++;
        }
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

