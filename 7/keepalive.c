#include <stdio.h>
#include <sys/socket.h>


int main()
{
    int sock, cs, len = sizeof(int);

    sock = socket(2, 2, 0);
    //int res = 0;
    printf("%d\n",cs);

    getsockopt(sock, 1, SO_KEEPALIVE, &cs, &len);
    printf("%d\n",cs);
    cs = 1;
    printf("%d\n",cs);
    setsockopt(sock, 1, SO_KEEPALIVE, &cs, len);
    getsockopt(sock, 1, SO_KEEPALIVE, &cs, &len);
    printf("%d\n",cs);

    //printf("%d\n",SOL_SOCKET);


   
    return 0;  
}
