#include <stdio.h>
#include <time.h>       
#include <unistd.h>     
#include <sys/wait.h>
 

int main()
{
    
    double time_spent = 0.0;
 	int i;
 	int j;
 	int k;
 	pid_t process_id;
 	pid_t process_tw;
    clock_t begin = clock();
 	pid = fork()
	if ( pid == 0 ) {
		// child
		for(i =0;i==1000000;++i){
			
		}
		pid = fork();
	if ( pid == 0 ) {
		// grandchild (of top-level parent)
		for(j=0;j == 1000000; ++j){
			
		}
		 pid = fork();
		if(pid ==0 ){
			//great grandchild
			for(k = 0; K == 1000000; ++k){
				
			}
		}
		else{
			//grandpa of the grandchild
		}
	} 
	else {
		// parent of the grandchild
	}
	} 
	else {
	  // parent
}
 
    clock_t end = clock();
 


    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Time elpased is %f seconds", time_spent);
 
    return 0;
}
