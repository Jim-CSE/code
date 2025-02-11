#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BufferSize  5                           //Maximum Buffer Capability defined

sem_t empty;                                //semaphore type variable empty declared [How much buffer is empty]
sem_t full;                                     //semaphore type variable full declared [How much buffer is full]
int in = 0, out = 0, buffer_pos = 0, buffer[BufferSize], flag[5] = {0};
pthread_mutex_t mutex;                      //pthread-mutex type variable mutex delcared [Which process holds the lock]

void *producer(void *id);                   //function for producer-consumer [void pointer return and void pointer parameter]
void *consumer(void *id);

int main()
{
    pthread_t pro_thread[5], con_thread[5];     //creating 5 threads for producers and 5 threads for consumers
    pthread_mutex_init(&mutex, NULL);               //mutex lock initialize [no process is holding the lock for mutex]
    sem_init(&empty, 0, BufferSize);                    //empty semaphore initialize [emtpy->5: The entire buffer is empty]
    sem_init(&full, 0, 0);                                  //full semaphore initialize [full->0: No space is full]

    int id[5] = {1, 2, 3, 4, 5};                   //id no. for producers and consumers
    for(int i=0; i<BufferSize; i++)
    {
        pthread_create(&pro_thread[i], NULL, (void *)producer, (void *) &id[i]);        //creating concurrent running process/thread that will run producer function
    }

    for(int i=0; i<BufferSize; i++)
    {
        pthread_create(&con_thread[i], NULL, (void *)consumer, (void *) &id[i]);        //creating concurrent running process/thread that will run consumer function
    }

    for(int i=0; i<BufferSize; i++)
    {
        pthread_join(pro_thread[i], NULL);                          //joining the producer threads with the main function
    }

    for(int i=0; i<BufferSize; i++)
    {
        pthread_join(con_thread[i], NULL);                          //joining the consumer threads with the main function
    }

    return 0;
}

void *producer(void *id)
{
    int p_id = *(int *) id;             //converting the void pointer parameter to int
    for(int i=0; i<BufferSize; i++)
    {
        int item = rand()%100 + 1;          //generating a random number as item

        sem_wait(&empty);                   //if empty=0, i.e. no empty cell, then this producer will wait
        pthread_mutex_lock(&mutex);             //else, it will lock the mutex, so others can't get in the critical section

        /*--------Critical Section------------*/
        buffer[in] = item;                  //inserting the item into the buffer
        printf("Producer %d: \tProduces Item %d at %d\n", p_id, item, in+1);
        flag[in] = 1;                       //denoting that an item exists in this cell

        in = (in + 1) % BufferSize;         //increasing in value (circular)
        buffer_pos++;


        printf("\t\tCurrent Buffer Length: %d\n", buffer_pos);
        printf("\t\tBuffer: ");
        for(int j=0; j<BufferSize; j++)
        {
            if(flag[j] == 1)
            {
                printf("%d ", buffer[j]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");
        /*--------End of Critical Section------------*/

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *id)
{
    int c_id = *(int *) id;
    for(int i=0; i<BufferSize; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer %d: \tConsumes Item %d at %d\n", c_id, buffer[out], out+1);
        flag[out] = 0;
        out = (out + 1) % BufferSize;

        buffer_pos--;
        printf("\t\tCurrent Buffer Length: %d\n", buffer_pos);

        printf("\t\tBuffer: ");
        for(int j=0; j<BufferSize; j++)
        {
            if(flag[j] == 1)
            {
                printf("%d ", buffer[j]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
