#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int variable, fd;

int func()
{
	variable=42;
	char str[]="child thread is working";
	int len=strlen(str);
	write(1, str, len);
	_exit(0);
}

int main(int argc, char *argv[])
{
	//void **child_stack;
	char tempch;
	
	variable=9;
	char* child_stack=(char *) malloc(16384);
	child_stack += 16384 -1;
	printf("The variable was %d\n", variable);
	char str[]="main thread is working";
        write(1, str, strlen(str));
	clone(func, child_stack, CLONE_VM, NULL);
	sleep(1);
	printf("variable is %d\n", variable);
	return 0;
}
