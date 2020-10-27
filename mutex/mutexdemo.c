#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int count =0;
pthread_mutex_t count_mutex;
pthread_mutexattr_t count_mutex_attr;

void *inc_thread(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&count_mutex);
        count++;
printf(" inc Thread%d\n",count);
    pthread_mutex_unlock(&count_mutex);
}
}

void *dec_thread(void *arg)
{
while(1)
{
    pthread_mutex_lock(&count_mutex);
    count--;
    printf("dec thread %d\n",count);
    pthread_mutex_unlock(&count_mutex);
}

}


int main(int argc, char *argv[])
{
 pthread_t tid,tid_inc,tid_dec;
 pthread_mutexattr_init(&count_mutex_attr);
 pthread_mutex_init(&count_mutex,&count_mutex_attr);
 printf("Before thread creation\n");
 pthread_create(&tid_inc,NULL,inc_thread,NULL);
 pthread_create(&tid_dec,NULL,dec_thread,NULL);
 pthread_join(tid_inc,NULL);
 pthread_join(tid_dec,NULL);
 pthread_mutex_destroy(&count_mutex);
 pthread_mutexattr_destroy(&count_mutex_attr);
 return 0;

}