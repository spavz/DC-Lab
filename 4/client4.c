#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main()
{

    struct sockaddr_in client;
    int sock, len = sizeof(client);
    char buf[50],buf1[50];

    sock = socket(2, 1, 0);
    client.sin_family      = 2;
    client.sin_addr.s_addr = 0x0100007f;
    client.sin_port        = 0x8813;


    connect(sock, &client, len);
    double a = clock();
    recv(sock, buf, 50, 0);
    double b = clock();
    printf("The roundtrip time is %f micro second\n", (1000000*(b-a))/CLOCKS_PER_SEC);
    puts(buf);
    close(sock);

    return 0;
}
