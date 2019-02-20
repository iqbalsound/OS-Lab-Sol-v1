#include <stdio.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
static char message[] = "Operating System lab - 04 \n ";
int main( )
{
int fd;
char buffer[80];
 
 /* open Lab04-2.os17 for read/write access (O_RDWR)
 create Lab04-2.os17 if it does not exist (O_CREAT)
 return error if datafile already exists (O_EXCL)
 permit read/write access to file (S_IWRITE | S_IREAD)
 */
 
fd = open("Lab04-2.os17",O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
if (fd != -1)
{
 printf("Lab04-2.os17 opened for read/write access\n");
 write(fd, message, sizeof(message));
 
 lseek(fd, 0, 0); /* go back to the beginning of the file */
 
 if (read(fd, buffer, sizeof(message)) == sizeof(message))
 printf("\"%s\" was written to Lab04-2.os17\n", buffer);
 else
 printf("*** error reading Lab04-2.os17 ***\n");
 close (fd);
 }
 else
 printf("*** Lab04-2.os17 already exists ***\n");
 //exit (0);
 }
 // type ls -la to check file permissions 