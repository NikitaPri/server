#include <sys/socket.h>

struct sockaddr_in addr;
struct sockaddr_un local;
int main()
{
	int err,len;
	if (-1 == ( ls = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP ) )) 
	{
		perror( "Socket can not be created!\n");
		return 1;
	}
}
