#include <stdio.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 65536

void strip(char *s){
	char *p2=s;
	while(*s!='\0'){
		if (*s!='\n'){
			*p2++=*s++;
		}else{
			++s;
		}
	}
	*p2='\0';
}	
int main(int argc, char ** argv)
{
	int sock, newsock, port, clen;
	char buf[BUF_SIZE];
	struct sockaddr_in serv_addr, cli_addr;
	if (argc < 2)
	{
		fprintf(stderr,"usage^ %s <port_number>\n", argv[0]);
		return EXIT_FAILURE;
	}
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (socket < 0)
	{
		printf("socket() failed: %d\n", errno);
		return EXIT_FAILURE;
	}
	memset((char *) &serv_addr, 0, sizeof(serv_addr));
	port = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
	if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("bind() failed: %d\n", errno);
		return EXIT_FAILURE;
	}
	listen(sock, 10);
	clen = sizeof(cli_addr);
	newsock = accept(sock, (struct sockaddr *) &cli_addr, &clen);
	if (newsock < 0)
	{
		printf("accept() failde^ %d\n", errno);
		return EXIT_FAILURE;
	}
	memset(buf, 0, BUF_SIZE);
	read(newsock, buf, BUF_SIZE-1);
	buf[BUF_SIZE] = 0;
	printf("RECEIVED:\n%s\n", buf);
	char buff[4096];
	FILE *in;
	extern FILE *popen();
	int len;
	char command[65550];
	
	len=snprintf(command, sizeof(command), "./threads %s", buf);
	strip(command);//clear command from \n
	char replace=';';
	char replacewith=',';
	int counter=0;
	while(command[counter]!='\0')
	{
		if (command[counter]==replace)
		{
			command[counter]=replacewith;
		}
		counter++;
	}
	printf("command is %s\n",command);
	if(!(in=popen(command, "r""")))
	{
		exit(1);
	}
	while(fgets(buff,sizeof(buff),in)!=NULL)
	{
		printf("%s\n",buff);
	}
	pclose(in);
	write(newsock, buff, strlen(buff));
	close(newsock);
	close(sock);
}

