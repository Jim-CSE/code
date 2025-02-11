#include<stdio.h>
#include<stdbool.h>

typedef struct Process
{
    int id;
    int burst_time;
    int waiting_time;
} Process;

void RR(int n, Process process[], int quantum_time);

int main()
{

    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    Process process[n];
    printf("Enter the burst burst time of the process: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &process[i].burst_time);
        process[i].id = i+1;
    }

    int quantum_time;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum_time);

    RR(n, process, quantum_time);

    return 0;
}

void RR(int n, Process process[], int quantum_time)
{
    int remaining_burst_time[n];
    for(int i=0; i<n; i++)
    {
        remaining_burst_time[i] = process[i].burst_time;
    }

    int start_time, finish_time = 0;
    bool done = false;
    printf("\n\nProcess \t Remaining Burst Time \t TIme Slot (Start) \t Time Slot (END) \n");

    while(!done)
    {
        done = true;

        for(int i=0; i<n; i++)
        {
            start_time = finish_time;

            if(remaining_burst_time[i] > 0)
            {
                done = false;
                if(remaining_burst_time[i] > quantum_time)
                {
                    finish_time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                }
                else
                {
                    finish_time += remaining_burst_time[i];
                    process[i].waiting_time = finish_time - process[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
                printf("%d \t\t %d \t\t\t %d \t\t\t %d \n", process[i].id, remaining_burst_time[i], start_time, finish_time);

            }
        }
    }

    int total_waiting_time = 0;
    for(int i=0; i<n; i++)
    {
        total_waiting_time += process[i].waiting_time;
    }

    double average_waiting_time = (double)total_waiting_time / n;

    printf("\n\nProcess \t Burst Time \t Waiting Time \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t\t %d \t\t %d \n", process[i].id, process[i].burst_time, process[i].waiting_time);
    }

    printf("\nTotal waiting time: %d \n", total_waiting_time);
    printf("\nAverage waiting time: %2f \n", average_waiting_time);

}

