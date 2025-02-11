#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
} Process;

void RR_PRE(int n, Process process[], int quantum_time);

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

    int quantum_time;
    cout << "Enter the time quantum: ";
    cin >> quantum_time;

    RR_PRE(n, process, quantum_time);

    return 0;
}

void RR_PRE(int n, Process process[], int quantum_time)
{
    sort(process, process+n, compare);

    int remaining_burst_time[n];
    for(int i=0; i<n; i++)
    {
        remaining_burst_time[i] = process[i].burst_time;
    }

    int start_time, finish_time = process[0].arrival_time;
    bool done = false;
    cout << "\n\nProcess \t" << "Remaining Burst Time \t" << "TIme Slot (Start) \t" << "Time Slot (END) \n";

    int complete = 0, i = 0;
    while(complete != n)
    {
        start_time = finish_time;
        if(process[i].arrival_time <= finish_time && remaining_burst_time[i] > 0)
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
                process[i].waiting_time = finish_time - process[i].burst_time - process[i].arrival_time;
                remaining_burst_time[i] = 0;
                complete++;
            }
        }
        cout << process[i].id << "\t\t" << remaining_burst_time[i] << "\t\t\t" << start_time << "\t\t\t" << finish_time << "\n";

        bool flag = false;
        for(int j=i+1; j<n; j++)
        {
            if(process[j].arrival_time <= finish_time && remaining_burst_time[j] > 0)
            {
                swap(process[j-1], process[j]);
                swap(remaining_burst_time[j-1], remaining_burst_time[j]);
            }
        }
    }

    sort(process, process+n, compare);

    int total_waiting_time = 0;
    for(int i=0; i<n; i++)
    {
        total_waiting_time += process[i].waiting_time;
    }

    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\n\nProcess \t " << "Arrival Time \t"<< "Burst Time \t" << "Waiting Time" << endl;
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


