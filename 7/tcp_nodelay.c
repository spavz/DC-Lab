#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
int main()  
{
    int sock, cs, len = sizeof(int);
    sock = socket(2, 1, 0);

    while(1)
    {
        printf("set: ");
        scanf("%d",&cs);
        setsockopt(sock, SOL_TCP, TCP_NODELAY, &cs, len);
        getsockopt(sock, SOL_TCP, TCP_NODELAY, &cs, &len);
        printf("get: %d\n\n",cs);
    }
}