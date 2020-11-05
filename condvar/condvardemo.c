#include<stdio.h>
#include<pthread.h>
int flag=0;
pthread_mutex_t m1;
pthread_cond_t cv1;
void* thread1(void *data)
{
 printf("T1:grabbing mutex\n");
 pthread_mutex_lock(&m1);
 printf("before busy loop\n");
 while(flag!=1)
 {
     printf("entering conditional wait\n");
   pthread_cond_wait(&cv1,&m1);
printf("after wait\n");
 }
 
 printf("T1:after busy loop\n");
 pthread_mutex_unlock(&m1);
 printf("T1:realeasing mutex\n");
}
void* thread2(void *data){
    printf("T2:grabbing mutex\n");
    pthread_mutex_lock(&m1);
    flag=1;
    printf("after setting flag\n");
    pthread_mutex_unlock(&m1);
    printf("T2:realising mutex\n");
}

int main(int argc,const char *argv[])
{
 pthread_t t1,t2;
 pthread_mutex_init(&m1,NULL);
 pthread_cond_init(&cv1,NULL);
 pthread_create(&t1,NULL,thread1,NULL);
 pthread_create(&t2,NULL,thread2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 pthread_mutex_destroy(&m1);
 pthread_cond_destroy(&cv1);
}