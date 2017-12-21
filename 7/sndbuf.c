#include <stdio.h>
#include <sys/socket.h>


int main()  
{
    int sock, cs, len = sizeof(int);
    sock = socket(2, 2, 0);

    getsockopt(sock, 1, SO_SNDBUF, &cs, &len);
    printf("initial get: %d\n",cs);

    while(1)
    {
        printf("set: ");
        scanf("%d",&cs);
        setsockopt(sock, 1, SO_SNDBUF, &cs, len);
        getsockopt(sock, 1, SO_SNDBUF, &cs, &len);
        printf("get: %d\n\n",cs);
    }
}