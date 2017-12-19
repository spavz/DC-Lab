#include <stdio.h>
#include <sys/mman.h>

//gcc server6.c -lrt -o client
int main()
{
    int ch;

    int shm = shm_open("OS", 66, 0666); 
    int* addr = (int*) mmap(0, 4096, 3, 1, shm, 0);

    printf("got %d\n", *addr);
    printf("%d\n", MAP_ANONYMOUS );

    while(1) {
        printf("Enter 1 if you want to increment ");
        scanf("%d", &ch);
        if(ch != 1)
            return 0;
        (*addr)++;
        printf("Counter incremented to %d\n", *addr);
    }
    shm_unlink("OS");
    return 0;
}