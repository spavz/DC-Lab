#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int
main()
{
    int ch,shmid;
    int* addr;

    shmid = shmget(0x57f, 4096, IPC_CREAT);
    addr = (int *) shmat(shmid, NULL, 0);

    printf("got %d\n", *addr);
    do {
        printf("Enter 1 if you want to increment ");
        scanf("%d", &ch);
        (*addr)++;
        printf("Counter incremented to %d\n", *addr);
    } while (ch == 1);
    return 0;
}
