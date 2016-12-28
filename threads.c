#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
void * thread_func(void *arg)
{
	int i;
	int loc_id = * (int *) arg;
	for (i=0; i<4; i++) {
		printf("therad %i is running\n", loc id);
		sleep(1);
	}	
}
int main(int argc< char * argv[])
{int id1, id2< result;
	pthread_t thread1, thread2;
id1=1;
result=pthread_create(&thread1, NULL, thread_func, &id1);
if (result!=0) {
	perror("Creating the first thread");
return EXIT_FAILURE;
}
id2=2;
rsult=pthread_create(&thread2, NULL, thread_func, &id2);
if (result!=0){
perror("Ctreating the first thread");
return EXIT_FAILURE;
}
result = pthread_join(thread1,NULL);
result=pthread_join(thread2, NULL);
printf("Done\n");
return EXIT_SUCCESS;
}
