#include <stdio.h>
#include <sys/socket.h>


int main()  
{
    int sock, cs, len = sizeof(int);
    sock = socket(2, 2, 0);

    while(1)
    {
        printf("set: ");
        scanf("%d",&cs);
        setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &cs, len);
        getsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &cs, &len);
        printf("get: %d\n\n",cs);
    }
}