#include <stdio.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h>  /* defines S_IREAD & S_IWRITE */
 int main( )
 {
 int fd;
 fd = creat("Lab04-1.os", S_IREAD | S_IWRITE);
 if (fd == -1)
 printf("Error in creating Lab04-1.os17\n");
 else
 {
 printf("Lab04-1.os17 created for read/write access\n");
 printf("Lab04-1.os17 is currently empty open it in a text editor...\n");
 }
 close(fd);
 exit (0);  // Comment it if gcc shows warning as below
 
 /*  ========== WARNING =========================
 
root@Iqbal-Quad:~# gcc -o 41 41.c
41.c: In function ‘main’:
41.c:17:2: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
  exit (0); /*exit() terminates the calling process , exit(0) for successful &
  ^
root@Iqbal-Quad:~#
================================================= */
 
 /*exit() terminates the calling process , exit(0) for successful &
 exit(1) for error, exit() is defined in #include<stdlib.h> */
 }
// type ls -la to check file permissions 