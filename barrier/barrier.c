#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_barrier_t barr;

void* serial(void *arg)
{
printf("serial:initialization started\n");
sleep(2);
printf("serial:initialized completed\n");
pthread_barrier_wait(&barr);
printf("serial:started\n");
}

void* ethernet(void *arg)
{
printf("ethernet:initialization started\n");
sleep(10);
printf("ethernet:initialized completed\n");
pthread_barrier_wait(&barr);
printf("ethernet:started\n");
}

void* lcd(void *arg)
{
printf("lcd:initialization started\n");
sleep(7);
printf("lcd:initialized completed\n");
pthread_barrier_wait(&barr);
printf("lcd:started\n");
}

void* adc(void *arg)
{
printf("adc:initialization started\n");
sleep(4);
printf("adc:initialized completed\n");
pthread_barrier_wait(&barr);
printf("adc:started\n");
}


int main(int argc,const char *argv[])
{
 pthread_t s,e,l,a;
 pthread_barrier_init(&barr,NULL,4);
 pthread_create(&s,NULL,serial,NULL);
 pthread_create(&e,NULL,ethernet,NULL);
 pthread_create(&l,NULL,lcd,NULL);
 pthread_create(&a,NULL,adc,NULL);

 pthread_join(s,NULL);
 pthread_join(e,NULL);
 pthread_join(l,NULL);
 pthread_join(a,NULL);

 pthread_barrier_destroy(&barr);
 return 0;

}