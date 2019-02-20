#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define PERMS 0644 		/* Permission for open with O_CREAT */

char *filename = "Lab04-2.os17";

main()
{
int fd;
if((fd=open(filename, O_RDWR | O_CREAT, PERMS)) == -1)
{
 printf("Couldn't create %s\n",filename);
 exit(1); /*error, so exit */
}
printf(“The file is opened and ready for read and write operation \n“);
/* rest of program follows */
exit(0); /*normal successful exit */
}
// type ls -la to check file permissions 