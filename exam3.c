#include <stdio.h>
#include <signal.h>
int alarmFlag = 0 ;
void alarmHandler ( ) ;
main ( )
{
 signal(SIGALRM, alarmHandler) ; /*Install signal Handler*/
 alarm (5) ;
 printf ("Looping ...\n") ;
 while (!alarmFlag)
 {
 pause ( ) ; /* wait for a signal */
 }
 printf ("Loop ends due to alarm signal\n") ;
}
void alarmHandler ( )
{
 printf ("An ALARM clock signal was received\n") ;
 alarmFlag = 1 ;
}