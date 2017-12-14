#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in client;
    int sock, len = sizeof(client);
    char buf[50],buf1[50];

    while(1)
    {
        sock = socket(2, 2, 0);
        client.sin_family      = 2;
        client.sin_addr.s_addr = 0x0100007f;
        client.sin_port        = 0x8813;

        connect(sock, &client, len);
        puts("UDP: Connected to server");
        recv(sock, buf, 50, 0);
        if(strcmp(buf,"LOCKED") == 0)
        {
            puts("Cannot enter CS. Sleeping");
            sleep(5);
        }else{
            puts("Entered CS. Enter message");
            scanf("%s",buf);
            send(sock, buf, 50, 0);
            recv(sock, buf1, 50, 0);
            printf("UDP: Message from Server: %s", buf1)
        }
        close(sock);
    }
    return 0;
}
