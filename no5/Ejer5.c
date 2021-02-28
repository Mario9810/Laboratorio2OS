#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 50
#define READ_END 0
#define WRITE_END 1
#define NAME "/share"

int main (int argc, char *argv[]) 
{
	const int SIZE = 4096;
	
	int value = 0;
	int namedfd;
	int fin = -1;
	int sharedfd;
	char *format;
	int n;
	n = atoi(argv[1]);
	char x[sizeof(argv[2])];
	strcpy(x, argv[2]);

	sharedfd = shm_open(NAME, O_RDWR, 0);
	//----------------------
	if (sharedfd == -1)
	{

		sharedfd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
		printf("%c: Create new shared mem obj %d\n", x[0], sharedfd);
		ftruncate(sharedfd, SIZE);
		
	}
	
	else 
	{
		printf("%c: espacio de memoria ya existe \n", x[0]);
		printf("%c: Received shm fd: %d\n", x[0], value);
		ftruncate(sharedfd, SIZE);
	}
	//----------------------
	pid_t pid;
	int v = MAP_SHARED;
	int p = PROT_READ | PROT_WRITE;
	format = mmap(0, SIZE, p, v, sharedfd, 0);
	//----------------------
	char escribir[BUFFER_SIZE];
	char leer[BUFFER_SIZE];
	sprintf(escribir, "%s", x);
	int fd[2];
	pipe(fd);
	
 	pid = fork();
 	//----------------------
 	if (pid > 0 ) 
	{
	 	for (int i=0; i<SIZE; i++)
	 	{
			if (i%n == 0){
				close(fd[READ_END]);
	 			write(fd[WRITE_END], escribir, strlen(escribir)+1);
			 	close(fd[WRITE_END]);
	 		}
	 	}

		wait(NULL);
	 	printf("%c: shared memory has: %s\n", x[0], (char *)format);
	 	if (value == 0) 
	 	{
	 		
			shm_unlink(NAME);	
	 	}
	}
	else 
	{
		if (value < 0) 
		{
	 		format += 26;
	 	}	
		int s = 0;
		while(s < SIZE/n +1)
		{
			close(fd[WRITE_END]);
		 	read(fd[READ_END], leer, BUFFER_SIZE);
			close(fd[READ_END]);
			sprintf(format, "%s", (char *)leer);
			format += strlen(leer);
	 		
			++s;
		}
	}
	
	return 0;
	
	
}
