#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int global_data = 5 ;

void *child_func(void *p) {
 printf ("Now the Child is here. Global data was %d.\n", global_data) ;
 global_data = 15 ;
 printf ("Its Child Again. Global data was now %d.\n", global_data) ;
}

int main ( ) {
  pthread_t child ;
  pthread_create (&child, NULL, child_func, NULL) ;
 printf ("The Parent is here. Global data = %d\n", global_data) ;
 global_data = 10 ;
 pthread_join (child, NULL) ;
 printf ("End of program. Global data = %d\n", global_data) ;
 return 0;
}

/*
iqbal@iqbal-F17 ~ $ nano thread2.c
iqbal@iqbal-F17 ~ $ gcc -o thread2 thread2.c -lpthread
iqbal@iqbal-F17 ~ $ ./thread2
The Parent is here. Global data = 5
Now the Child is here. Global data was 10.
Its Child Again. Global data was now 15.
End of program. Global data = 15
iqbal@iqbal-F17 ~ $ 
*/