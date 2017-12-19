#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/mman.h>


//gcc server10.c -lrt -o server
int main()
{
    struct sockaddr_in server, client;
    int sock, cs, pid,len = sizeof(client);
    char buf[50];
    int* mutex = (int*) mmap(0, 4096, 3, 33, 0, 0);   // So that child process has access to the mutex too. This call allows forked process' pages read-write only.
    *mutex = 0;

    sock = socket(2, 1, 0);         //hardcoded constants (TCP)
    server.sin_family      = 2;
    server.sin_addr.s_addr = 0;
    server.sin_port        = 0x8813;   //hardcoded port 5000 in network byte order. 5001 is 0x8913, 5002 is 0x8A13 and so on.


    bind(sock, &server, len);
    listen(sock, 5);
    puts("Listening..");

    while (1) 
    {
        cs  = accept(sock, &client, &len);
        if(*mutex == 1){              // parent denies client-requests till the existing child returns
            char m[50] = "LOCKED";
            send(cs, m, 50, 0);
        }else
        {
            *mutex = 1;                // parent locks the mutex (once) 
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
                *mutex = 0;            // child unlocks the mutex and exits critical section.
                return 0;
            }
        }
        close(cs);
    }
    close(sock);
    return 0;  
}
