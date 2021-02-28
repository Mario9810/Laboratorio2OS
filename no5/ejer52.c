#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	pid_t f = fork();
	if (f==0) 
	{
		execl("Ejer5", "Ejer5", "157", "a", (char*)NULL);
	}else{
	
		usleep(1400);
		execl("Ejer5", "ejer5", "157", "b", (char*)NULL);
	}
	
	return 0;
}
