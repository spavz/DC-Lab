#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <time.h>

main()
{
    struct sockaddr_in server, client;
    int sock, cs, pid, len = sizeof(client);
    char buf[50];
    time_t t;

    
    sock = socket(2, 1, 0);
    server.sin_family      = 2;
    server.sin_addr.s_addr = 0;
    server.sin_port        = 0x8813;

    bind(sock, (struct sockaddr *) &server, len);
    listen(sock, 5);
    while(1)
    {
        cs  = accept(sock, (struct sockaddr *) &client, &len);
        puts("TCP: Client connected");
        sleep(5);
        time(&t);
        send(cs, ctime(&t), 50, 0);
        close(cs);
    }
    close(sock);
}
