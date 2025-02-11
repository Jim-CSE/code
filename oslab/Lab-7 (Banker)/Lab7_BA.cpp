#include<bits/stdc++.h>
using namespace std;

typedef struct Process
{
    int id;
    int allocation[1000];
    int max_need[1000];
    int need[1000];
} Process;

int main()
{
    int total_process;
    cout << "Enter the number of process: ";
    cin >> total_process;                           // Input number of process

    int total_resource;
    cout << "Enter the number of resources: ";
    cin >> total_resource;                          // Input number of resource

    int resource[total_resource];
    int resource_allocated[total_resource];
    cout << "Enter the number of instance for each resources: ";
    for(int i=0; i<total_resource; i++)
    {
        cin >> resource[i];                                     // Input number of instances of resource
        resource_allocated[i] = 0;                              // Initializing resource allocated by process as 0
    }

    Process process[total_process];
    cout << "Enter the allocation of resources for each process: \n";
    for(int i=0; i<total_process; i++)
    {
        for(int j=0; j<total_resource; j++)
        {
            cin >> process[i].allocation[j];                            // Input allocation of resource for each process
            resource_allocated[j] += process[i].allocation[j];          // Calculating the resource allocated by the processes
        }
        process[i].id = i+1;                                            // Assigning process id
    }

    cout << "Enter the max need of instances for each process: \n";
    for(int i=0; i<total_process; i++)
    {
        for(int j=0; j<total_resource; j++)
        {
            cin >> process[i].max_need[j];                                              // Input max need of instances for each process

            process[i].need[j] = process[i].max_need[j] - process[i].allocation[j];     // Calculating need of instances for each process
        }
    }

    int available[total_resource];
    for(int i=0; i<total_resource; i++)
    {
        available[i] = resource[i] - resource_allocated[i];                             // Calculating number of available resource instance
    }

    /* For printing the table -----> */
    cout << "\n\nProcess \t" << "Allocation \t" << "Max \t\t" << "Need \t\t" << "Available \t" << "Resource\n";
    for(int i=0; i<total_process; i++)
    {
        cout << process[i].id << "\t\t";
        for(int j=0; j<total_resource; j++)
        {
            cout << process[i].allocation[j] << " ";
        }
        cout << "\t\t";

        for(int j=0; j<total_resource; j++)
        {
            cout << process[i].max_need[j] << " ";
        }
        cout << "\t\t";

        for(int j=0; j<total_resource; j++)
        {
            cout << process[i].need[j] << " ";
        }
        cout << "\t\t";

        if(i == 0)
        {
            for(int j=0; j<total_resource; j++)
            {
                cout << available[j] << " ";                    // Printing available resource only once
            }
            cout << "\t\t";
        }

        if(i == 0)
        {
            for(int j=0; j<total_resource; j++)
            {
                cout << resource[j] << " ";                     // Printing instances of resource only once
            }
        }
        cout << "\n";
    }
    /* End of printing ----->   */

    bool safe[total_process] = {false};
    int ans[total_process], cnt = 0;
    for(int k=0; k<total_process; k++)
    {
        for(int i=0; i<total_process; i++)
        {
            if(safe[i] == false)
            {
                bool ok = true;
                for(int j=0; j<total_resource; j++)
                {
                    if(process[i].need[j] > available[j])
                    {
                        ok = false;
                        break;
                    }
                }

                if(ok == true)
                {
                    ans[cnt] = i+1;
                    cnt++;

                    for(int x=0; x<total_resource; x++)
                    {
                        available[x] += process[i].allocation[x];
                    }
                    safe[i] = true;
                }
            }
        }
    }

    bool flag = true;
    for(int i=0; i<total_process; i++)
    {
        if(safe[i] == false)
        {
            flag = false;
            break;
        }
    }

    if(flag == false)
    {
        cout << "\nThe given sequence is not safe...\n";
    }
    else
    {
        cout << "\nThe SAFE sequence is: ";
        for(int i=0; i<total_process-1; i++)
        {
            cout << ans[i] << " -> ";
        }
        cout << ans[total_process-1] << "\n";
    }

    return 0;
}
