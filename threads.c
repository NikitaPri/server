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

int func(int argc)
{
	variable=42;
	char str[]="child thread is working";
	int len=strlen(str);
	write(1, str, len);
	
	int n;
	n=argc;
	//convert int to char
	char* c;
	c=(char *)malloc(10 * sizeof(char));
	int v=0;
	while (n > 9)
	{
		c[v++]=(n%10)+'0';
		n=n/10;
	}
	c[v++]=n+'0';
	c[v]='\0';
	char t;
	int i=0;
	for (i=0; i<v/2;i++)
	{
		t=c[i];
		c[i]=c[v-1-i];
		c[v-1-i]=t;
	}
	write(1, c, strlen(c));
	free(c);
	
	char str1[]="child thread number 2";
	write(1, str1, strlen(str1));
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
        
	clone(func, child_stack, CLONE_VM, 123);
	sleep(1);
	printf("variable is %d\n", variable);
	return 0;
}
