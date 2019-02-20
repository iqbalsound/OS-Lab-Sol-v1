#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 pid_t pid;
 pid = fork();
 if(pid == 0)
 {
 exit(0);
 }
 else
 sleep(3);
 system("ps -ax");
 return 0;
}