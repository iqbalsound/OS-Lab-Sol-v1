#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// Cearting external function to be called as a thread 

void *child_func(void *p) {
 printf ("The created Child ID is --->  %d\n", getpid( ));
}


main ( ) {
 pthread_t child ;									// Creating thread
 pthread_create (&child, NULL, child_func, NULL) ;	// Calling child_func()
 printf ("Parent ID is --->  %d\n", getpid( )) ;
 pthread_join (child, NULL) ;
 printf ("No more child process alive...!!!\n") ;
}

/*

iqbal@iqbal-F17 ~ $ nano thread1.c
iqbal@iqbal-F17 ~ $ gcc -o thread1 thread1.c -lpthread
iqbal@iqbal-F17 ~ $ ./thread1
Parent ID is --->  3019
The created Child ID is --->  3019
No more child process alive...!!!
iqbal@iqbal-F17 ~ $ 

*/