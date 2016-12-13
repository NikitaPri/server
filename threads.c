#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
int N;

int func(int argc, int agrv)
{
	//variable=42;
	char str[]="child thread with id ";
	char newline[]="\n";	
	int n;
	n=argc;
	

	//Multiply matrix
	



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
	int j=0;
	
		for (i=0; i<v/2;i++)
		{
			t=c[i];
			c[i]=c[v-1-i];
			c[v-1-i]=t;
		}
		j++;
	write(1, str, strlen(str));
	write(1, c, strlen(c));
	write(1, newline, 2);
	free(c);

	_exit(0);
}

int main(int argc, char *argv[]));
        free(B);
        free(C);







        //char* child_stack=(char *) malloc(16384);
        //        //child_stack += 16384 -1;
        //
        //                long stacksize=1024;
        //                        void *stack;
        //                                //stack=malloc(stacksize);
        //
        //                                        printf("The variable was %d\n");
        //                                                char str[]="main thread is working";
        //
        //                                                        for (i=1; i<=n_threads; i++)
        //                                                                {
        //                                                                                stack=malloc(stacksize*i);
        //                                                                                                pid=clone(func, stack+stacksize, CLONE_VM | SIGCHLD, i, stacksize);
        //
        //                                                                                                                printf("Created child thread with id %d\n", i);
        //
        //                                                                                                                        }
        //
        //                                                                                                                                for (i=1; i<=n_threads; i++)
        //                                                                                                                                        {
        //                                                                                                                                                        wait(NULL);
        //                                                                                                                                                                }
        //
        //                                                                                                                                                                        printf("variable is %d\n");
        //                                                                                                                                                                                return 0;
        //                                                                                                                                                                                }
        //
{
	//void **child_stack;
	char tempch;
	pid_t pid;	
	int n_threads=10;
	//Matrix
	int i=0;
	int j=0;
	N=3;
	int k=0;
	int **A=(int**)malloc(N * sizeof(int*));
	int **B=(int**)malloc(N * sizeof(int*));
	int **C=(int**)malloc(N * sizeof(int*));
	for (i=0; i<N; i++)
	{
		A[i]=(int*)malloc(N * sizeof(int));
		B[i]=(int*)malloc(N * sizeof(int));
		C[i]=(int*)malloc(N * sizeof(int));
	}
	for (i=0; i<N; i++)
	{
		for (j=0;j<N; j++)
		{
			A[i][j]=i+j;
			B[i][j]=(i+j)*2;
		}
	}
	
	//Multiply Matrix
	for(i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			C[i][j]=0;
			for (k=0; k<N; k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	printf("matrix A\n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}
	printf("matrix B\n");
	for (i=0; i<N; i++)
        {
                for (j=0; j<N; j++)
                {
                        printf("%d   ", B[i][j]);
                }
                printf("\n");
        }	
	printf("matrix C\n");
	        for (i=0; i<N; i++)
        {
                for (j=0; j<N; j++)
                {
                        printf("%d    ", C[i][j]);
                }
                printf("\n");
        }
	int elem;
	int stroka;
	int stolbec;
	elem=8;
	stroka=elem/N;
	stolbec=elem-stroka*N;
	int element=0;
	element=C[stroka][stolbec];
	
	printf("element is %d\n", element);
	for (i=0; i<N; i++)
	{
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);






	
	//char* child_stack=(char *) malloc(16384);
	//child_stack += 16384 -1;
	
	long stacksize=1024;
	void *stack;
	//stack=malloc(stacksize);

	printf("The variable was %d\n");
	char str[]="main thread is working";
        
	for (i=1; i<=n_threads; i++)
	{
		stack=malloc(stacksize*i);
		pid=clone(func, stack+stacksize, CLONE_VM | SIGCHLD, i, stacksize);
		
		printf("Created child thread with id %d\n", i);
		
	}

	for (i=1; i<=n_threads; i++)
	{
		wait(NULL);
	}
	
	printf("variable is %d\n");
	return 0;
}
