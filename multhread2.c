#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5
void *PrintHello(void *threadid)
{
 printf("\n%d: Hello World!\n", threadid);
 pthread_exit(NULL);
}
int main( )
{
 pthread_t threads [NUM_THREADS];
 int rc, t;
  for(t=0; t < NUM_THREADS; t++) {
 printf ("Creating thread %d\n", t);
 rc = pthread_create (&threads[t], NULL, PrintHello, (void *) t );
 if (rc) {
 printf("ERROR; return code from pthread_create() is %d\n", rc);
 exit(-1);
 }
 }
   pthread_exit(NULL);
   return 0;
}

/*
iqbal@iqbal-F17 ~ $ nano multpleth.c
iqbal@iqbal-F17 ~ $ gcc -o multpleth  multpleth.c -lpthread
multpleth.c: In function ‘PrintHello’:
multpleth.c:9:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘void *’ [-Wformat=]
  printf("\n%d: Hello World!\n", threadid);
         ^
multpleth.c: In function ‘main’:
multpleth.c:18:54: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  rc = pthread_create (&threads[t], NULL, PrintHello, (void *) t );
                                                      ^
iqbal@iqbal-F17 ~ $ ./multpleth
Creating thread 0
Creating thread 1
Creating thread 2
Creating thread 3
Creating thread 4

4: Hello World!

3: Hello World!

2: Hello World!

1: Hello World!

0: Hello World!
iqbal@iqbal-F17 ~ $ 
*/
*/

