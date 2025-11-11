#include <stdio.h>

int main() {
    int n, i;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int j;
    int burst_time[n], waiting_time[n], turnaround_time[n];
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
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
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    avg_wait /= n;
    avg_turnaround /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);

    return 0;
}

