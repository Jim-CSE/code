#include<stdio.h>
#include<stdbool.h>

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
    printf("Enter the number of process: ");
    scanf("%d", &total_process);                             // Input number of process

    int total_resource;
    printf("Enter the number of resources: ");
    scanf("%d", &total_resource);                           // Input number of resource

    int resource[total_resource];
    int resource_allocated[total_resource];
    printf("Enter the number of instance for each resources: ");
    for(int i=0; i<total_resource; i++)
    {
        scanf("%d", &resource[i]);                          // Input number of instances of resource
        resource_allocated[i] = 0;                          // Initializing resource allocated by process as 0
    }

    Process process[total_process];
    printf("Enter the allocation of resources for each process: \n");
    for(int i=0; i<total_process; i++)
    {
        for(int j=0; j<total_resource; j++)
        {
            scanf("%d", &process[i].allocation[j]);                         // Input allocation of resource for each process
            resource_allocated[j] += process[i].allocation[j];              // Calculating the resource allocated by the processes
        }
        process[i].id = i+1;                                                // Assigning process id
    }

    printf("Enter the max need of instances for each process: \n");
    for(int i=0; i<total_process; i++)
    {
        for(int j=0; j<total_resource; j++)
        {
            scanf("%d", &process[i].max_need[j]);                                           // Input max need of instances for each process

            process[i].need[j] = process[i].max_need[j] - process[i].allocation[j];         // Calculating need of instances for each process
        }
    }

    int available[total_resource];
    for(int i=0; i<total_resource; i++)
    {
        available[i] = resource[i] - resource_allocated[i];                                 // Calculating number of available resource instance
    }

     /* For printing the table -----> */
    printf("\n\nProcess \tAllocation \tMax \t\tNeed \t\tAvailable \tResource\n");
    for(int i=0; i<total_process; i++)
    {
        printf("%d\t\t",process[i].id);
        for(int j=0; j<total_resource; j++)
        {
            printf("%d ", process[i].allocation[j]);
        }
        printf("\t\t");

        for(int j=0; j<total_resource; j++)
        {
            printf("%d ", process[i].max_need[j]);
        }
        printf("\t\t");

        for(int j=0; j<total_resource; j++)
        {
            printf("%d ", process[i].need[j]);
        }
        printf("\t\t");

        if(i == 0)
        {
            for(int j=0; j<total_resource; j++)
            {
                printf("%d ",  available[j]);
            }
            printf("\t\t");
        }

        if(i == 0)
        {
            for(int j=0; j<total_resource; j++)
            {
                printf("%d ", resource[j]);
            }
        }
        printf("\n");
        /* End of printing ----->   */
    }

    bool safe[100000] = {false};
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
        printf("\nThe given sequence is not safe...\n");
    }
    else
    {
        printf("\nThe SAFE sequence is: ");
        for(int i=0; i<total_process-1; i++)
        {
            printf("%d -> ", ans[i]);
        }
        printf("%d \n", ans[total_process-1]);
    }

    return 0;
}

