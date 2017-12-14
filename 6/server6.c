#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int c,shmid;
    int* addr;

    shmid = shmget(0x57f, 4096, IPC_CREAT);
    addr = (int*) shmat(shmid, NULL, 0);
    
    printf("Enter the counter value\n");
    scanf("%d", addr);
    while (1) ;
    return 0;
}
