#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

extern int errno;

#define BUFFER_LENGTH 512


int main(void)
{	
char receive[BUFFER_LENGTH];
char string[BUFFER_LENGTH];

memset(string,0,sizeof (receive));
memset(receive,0,sizeof (string));

int fd,ret;

	fd = open("/dev/first_char_device", O_RDWR);

		if(fd == -1)
		{
			perror("Device failed to open");
			return errno;
		}

	printf("\n Enter string to write \n");
	fgets(string,BUFFER_LENGTH,stdin);
	printf("Writting message to device");

	ret = write(fd,string,strlen(string));

		if(ret < 0)
		{
			perror("failed to write message to the device");
			return errno;
		}

	printf("\nEnter any key to read from the device");
	getchar();

	printf("\n reading from the device");
	ret = read(fd,receive,strlen(string));

		if(ret<0)
		{
			perror("Failed to read the message");
			return errno;
		} 


	printf("\n received message is :\n [%s] \n",receive);
	printf("end of program");

return 0;

}
