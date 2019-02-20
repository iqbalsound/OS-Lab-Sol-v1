#include <stdio.h>
#include <signal.h>
main ( )
{
 int (*oldHandler) ( ) ; /* holds old handler value */
 printf ("I can be Control-C'ed \n") ;
 sleep (5) ;
 oldHandler = signal(SIGINT, SIG_IGN) ; /* Ignore Ctrl-C */
 printf ("I am protected from Control-C now \n") ;
 sleep (5) ;
 signal (SIGINT, oldHandler) ; /* Restore old handler */
 printf ("I can be Control-C'ed again \n") ;
 sleep (5) ;
 printf ("Bye!!!!!!!\n") ;
}