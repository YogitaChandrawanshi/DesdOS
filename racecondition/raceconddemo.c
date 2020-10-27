#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int count =0;

void *inc_thread(void *arg)
{
    while(1)
    {
        count++;
    
printf("Thread\n");
}
}

void *dec_thread(void *arg)
{
while(1)
{
    count--;
    printf("dec thread %d\n",count);
}

}


int main(int argc, char *argv[])
{
 pthread_t tid,tid_inc,tid_dec;
 printf("Before thread creation\n");
 pthread_create(&tid_inc,NULL,inc_thread,NULL);
 pthread_create(&tid_dec,NULL,dec_thread,NULL);
 pthread_join(tid_inc,NULL);
 pthread_join(tid_dec,NULL);
 return 0;

}