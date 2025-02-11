#include<stdio.h>

int mutex = 1, full = 0, empty = 3, id = 0;

void producer();
void consumer();
int wait(int s);
int signal(int s);

int main()
{
    int n;

    printf("1. Producer. \n2. Consumer \n3. Exit \n");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        if(n == 1)
        {
            if(mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is full...!!!\n");
        }
        else if(n == 2)
        {
            if(mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is empty...!!!\n");
        }
        else if(n == 3)
        {
            break;
        }
        else
        {
            printf("Please give valid input...!!!\n");
        }
    }

    return 0;
}

int wait(int s)
{
    return --s;
}

int signal(int s)
{
    return ++s;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    id++;
    printf("\nProducer produces item -> %d", id);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    printf("\nConsumer consumes item -> %d", id);
    id--;
    mutex = signal(mutex);
}
