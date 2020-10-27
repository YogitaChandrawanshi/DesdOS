#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *serial_config_thread(void *arg)
{
printf("Thread\n");
}
struct serial_config
{

};

int main(int argc, char *argv[])
{
    struct serial_config s1,s2,s3;
 pthread_t tid;
 printf("Before thread creation\n");
 pthread_create(&tid,NULL,serial_config_thread,s1);
 pthread_create(&tid,NULL,serial_config_thread,s2);
 pthread_create(&tid,NULL,serial_config_thread,s3);
 pthread_create(&tid,NULL,serial_config_thread,NULL);
 //printf("After thread creation\n");
 //sleep(1);
 //printf("After sleep creation");
 return 0;

}