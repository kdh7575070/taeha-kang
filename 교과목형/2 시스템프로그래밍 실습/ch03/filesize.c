/* filesize.c - prints size of passwd file */
#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
    struct stat infobuf;	/* place to store info */
    if( stat( "/etc/passwd", &infobuf) == -1 ) /* get info */
	perror( "/etc/passwd" );
    else
	printf( "The size of /etc/passwd is %d\n", (int)infobuf.st_size );

    return 0;
}
