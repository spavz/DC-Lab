#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in server, client;
    int sock,pid,len = sizeof(client);
    char buf[50];

    sock = socket(2, 2, 0);
    server.sin_family      = 2;
    server.sin_addr.s_addr = 0;
    server.sin_port        = 0x8813;


    bind(sock, &server, len);
    listen(sock, 5);
    puts("Listening..");

    while (1) 
    {
        if (recvfrom(sock, buf, 50, 0, &client, &len) == -1) 
            continue;
        if ((pid = fork()) == 0) 
        {
            printf("UDP: Message from Client - %s",buf)
            sendto(sock, buf, 50, 0, &client, len);
            close(sock);
            return 0;
        }       
    }
    return 0;  
}
