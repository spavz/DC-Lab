#include <stdio.h>
#include <sys/socket.h>

int main()  
{
    struct linger 
    {
        int l_onoff;    
        int l_linger;  
    } cs;

    int sock, len = sizeof(cs);
    sock = socket(2, 2, 0);

    while(1)
    {
        printf("set: ");
        scanf("%d%d",&cs.l_onoff, &cs.l_linger);
        setsockopt(sock, SOL_SOCKET, SO_LINGER, &cs, len);
        getsockopt(sock, SOL_SOCKET, SO_LINGER, &cs, &len);
        printf("get: %d  %d\n\n",cs.l_onoff, cs.l_linger);
    }
}