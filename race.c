#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
static void charatatime(char *);
int main(void)
{
pid_t pid;
 if ((pid = fork()) < 0)
 {
 printf("Forking Error!!!!! \n");
 }
 else if (pid == 0)
 {
 charatatime("\n Responce from Child Process.....\n");
 }
 else
 {
 charatatime("\n Responce from Praent Process.....\n");
 }
 return 0;
 }
 static void charatatime(char *str)
 {
 char *ptr;
 int c;
 setbuf(stdout, NULL); 				/* set unbuffered */
 for (ptr = str; (c = *ptr++) != 0; )
 putc(c, stdout);
 }