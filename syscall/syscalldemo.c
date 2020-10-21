#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc,char const *argv[])
{
int fd;
fd=open("desd.txt",O_WRONLY |O_CREAT);
printf("%d\n",fd);
if(-1==fd)
{
    perror("error in open\n");
}
write(fd,"CDAC",4);
close(fd);
return 0;

}