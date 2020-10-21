#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,const char *argv[])
{
pid_t id;
printf("before fork\n");
id=fork();
if(0==id)
{

printf("In Child:%d\t PPID =%d\n",getpid(),getppid());

}
else
{
    printf("In prent :%d \t PPID=%d\n",getpid(),getppid());
}
return 0;
}