
/**
    TP n°3 - Luxon JEAN-PIERRE
    Helo world!
*/

#include <stdio.h>
#include <unistd.h>

#define N 10

int main()
{
    int n = 0;

    while((n++) < N)
    {
        sleep(1);
        printf("Hello World!\n");
    }
    return 0;
}
