#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include <semaphore.h>


int count =0;
sem_t count_sem;
void *inc_thread(void *arg)
{
    while(1)
    {
        sem_wait(&count_sem);
        count++;
    
printf(" inc Thread%d\n",count);
  sem_post(&count_sem);
}
}

void *dec_thread(void *arg)
{
while(1)
{
    sem_wait(&count_sem);
    count--;
    printf("dec thread %d\n",count);
 sem_post(&count_sem);
}

}


int main(int argc, char *argv[])
{
 pthread_t tid,tid_inc,tid_dec;
 sem_init(&count_sem,0,1);
 printf("Before thread creation\n");
 pthread_create(&tid_inc,NULL,inc_thread,NULL);
 pthread_create(&tid_dec,NULL,dec_thread,NULL);
 pthread_join(tid_inc,NULL);
 pthread_join(tid_dec,NULL);
 sem_destroy(&count_sem);
 return 0;

}