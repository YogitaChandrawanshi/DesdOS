#include<stdio.h>
#include<unistd.h>


int main(int argc, const char *argv[])
{

    pid_t id;
    id=fork();
    if(0==id)
    {
        printf("child starting\n");
        sleep(12);
        printf("child exiting\n");
    }
    else
    {
      printf("parent starting\n");
      sleep(2);
      printf("parent exiting\n");

    }
}