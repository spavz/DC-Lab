#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main()
{
    struct sockaddr_in server, client;
    int sock, cs, pid,len = sizeof(client);
    char buf[50];
    int* mutex = (int*) shmat(shmget(0x57f,4096,IPC_CREAT),NULL,0);
    *mutex = 0;

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
        if(*mutex == 1){
            char m[50] = "LOCKED";
            send(cs, m, 50, 0);
        }else
        {
            *mutex = 1;
            char m1[50] = "UNLOCK";
            send(cs, m1, 50, 0);
            if ((pid = fork()) == 0)
            {
                close(sock);
                puts("TCP: Client connected");
                recv(cs, buf, 50, 0);
                printf("TCP: Message from Client - %s\n",buf);
                puts("Enter Message");
                scanf("%s",buf);
                send(cs, buf, 50, 0);
                close(cs);
                *mutex = 0;
                return 0;
            }
        }
        close(cs);
    }
    close(sock);
    return 0;  
}
