#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
    int ret, pid,signum;

    printf("enter the signum: ");
    scanf("%d",&signum);
    printf("enter the pid");
    scanf("%d",&pid);
    ret=kill(pid,signum);
    printf("process is killed");




return 0;
}