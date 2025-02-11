#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
}Process;

void FCFS_NONPRE(int n, Process process[]);

bool compare(Process a, Process b);

int main()
{
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    Process process[n];
    cout << "Enter the burst time of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].burst_time;
        process[i].id = i+1;
    }

    cout << "Enter the arrival time of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].arrival_time;
    }

    FCFS_NONPRE(n, process);

    return 0;
}

void FCFS_NONPRE(int n, Process process[])
{
    sort(process, process+n, compare);

    int start_time[n];
    int total_waiting_time = 0;

    process[0].waiting_time = 0;
    start_time[0] = process[0].arrival_time;
    for(int i=1; i<n; i++)
    {
        start_time[i] = process[i-1].burst_time + start_time[i-1];
        process[i].waiting_time = start_time[i] - process[i].arrival_time;
        total_waiting_time += process[i].waiting_time;
    }


    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\n\nProcess \t " << "Arrival Time \t" << "Burst Time \t" << "Waiting Time" << endl;
    for(int i=0; i<n; i++)
    {
        cout << process[i].id << " \t\t " << process[i].arrival_time << "\t\t" << process[i].burst_time << " \t\t" << process[i].waiting_time << endl;
    }

    cout << "\nAverage waiting time: " << average_waiting_time << endl;
}

bool compare(Process a, Process b)
{
    return a.arrival_time < b.arrival_time;
}
