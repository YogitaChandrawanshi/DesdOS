#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int a,b,sum;
sem_t inp2proc,proc2inp;

void* input_thread(void * data)
{
while(1)
{
    printf("got signal\n");
 sem_wait(&proc2inp);
 printf("T1:getting new input\n");
 scanf("%d",&a);
 scanf("%d",&b);
 printf("T1:got new input\n");
 sem_post(&inp2proc);
 printf("sending signal\n");
}


}
void * processing_thread(void *data)
{
    while(1)
    {
        printf("got signal input\n");
        sem_wait(&inp2proc);
        printf("T2:starting processing\n");
        sum=a+b;
        printf("T2:processing done sum:%d\n",sum);
        sem_post(&proc2inp);
        printf("sending signal to input");
    }
}

int main(int argc,char* argv[])
{
pthread_t input_id,processing_id;
sem_init(&inp2proc,0,0);
sem_init(&proc2inp,0,1);
pthread_create(&input_id,NULL,input_thread,NULL);
pthread_create(&processing_id,NULL,processing_thread,NULL);

pthread_join(input_id,NULL);
pthread_join(processing_id,NULL);
return 0;

}