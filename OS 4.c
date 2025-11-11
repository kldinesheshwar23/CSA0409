#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n], process[n], waiting_time[n], turnaround_time[n];
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[pos])
                pos = j;
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_wait += waiting_time[i];
        avg_turnaround += turnaround_time[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_wait /= n;
    avg_turnaround /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);

    return 0;
}

