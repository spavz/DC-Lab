#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>


int main()
{
    struct sockaddr_in server, client;
    int sock, cs, pid, len = sizeof(client);
    char buf[50];
    int t;

    sock = socket(2, 1, 0);
    server.sin_family      = 2;
    server.sin_addr.s_addr = 0;
    server.sin_port        = 0x8813;


    bind(sock, &server, len);
    listen(sock, 5);
    puts("Listening..");

    while (1) 
    {
        cs  = accept(sock, &client, &len);
        if ((pid = fork()) == 0)
        {
            close(sock);
            puts("TCP: Client connected");

            sleep(5);
            time(&t);
            send(cs, ctime(&t), 50, 0);

            close(cs);
            return 0;
        }
        close(cs);
    }
    return 0;  
}
