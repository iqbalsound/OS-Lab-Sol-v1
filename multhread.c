/* Multithreaded C Program Using the Pthread API */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int sum, inte;			/*This data is shared by the thread(s) */
void *runner(void *param); 	/* the thread */

int main(int argc, char *argv[]) {
pthread_t tid;			/* the thread identifier */
pthread_attr_t attr; 		/* set of thread attributes */
if(argc != 2)
	
{
fprintf(stderr," Executed without input integer..... \n Use it as: ./<executable> <input integer>\n");
exit(0);
}

if(atoi(argv[1]) < 0)
{
fprintf(stderr, "%d Must be > or = 0 \n", atoi(argv[1]));
exit(0);
}
					/* get the default attributes */
pthread_attr_init(&attr);
					/*create the thread */

pthread_create(&tid,&attr,runner,argv[1]);
					/* Now wait for the thread to exit */
pthread_join(tid,NULL);
printf("The sum of %d  =  %d\n",inte,sum);
}

			/*The thread will begin control in this function */
void *runner(void *param)
{
int upper = atoi(param);
int i;
inte = upper;
sum=0;
if(upper > 0)
{
for(i=1; i <= upper;i++)
sum += i;
}
pthread_exit(0);

return 0;
}

/*
iqbal@iqbal-F17 ~ $ nano multhread.c
iqbal@iqbal-F17 ~ $ gcc -o multhread multhread.c -lpthread
iqbal@iqbal-F17 ~ $ ./multhread
 Executed without input integer..... 
 Use it as: ./<executable> <input integer>
iqbal@iqbal-F17 ~ $ ./multhread 40
The sum of 40  =  820
iqbal@iqbal-F17 ~ $ 



