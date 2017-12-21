#include <stdio.h>
#include <sys/mman.h>
    
//gcc server6.c -lrt -o server
int main()
{
 
    int shm = shm_open("OS", 66, 0666);
    ftruncate(shm, 4096); 
    int* addr = (int*) mmap(0, 4096, 3, 1, shm, 0);

    scanf("%d",addr);

    puts("Enter some value to write and exit");
    scanf("%d",addr);
    return 0;
}