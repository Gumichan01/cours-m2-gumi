
/**
    TP n°4 - Luxon JEAN-PIERRE
    Benchmark changement de contexte explicite
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NB_TEST 10
#define NB_PROC 100000

unsigned long getCurrentTime()
{
    time_t s;
    struct timespec t;

    clock_gettime(CLOCK_REALTIME, &t);

    s = t.tv_sec;
    return (unsigned long) (s * 1000000000 + t.tv_nsec);
}

void process_stat()
{
    pid_t p = 0;

    for(int i = 0; i < NB_PROC; ++i)
    {
        p = fork();

        if(p == 0)
            exit(0);
        else
            wait(NULL);
    }
}

int main()
{
    //unsigned long tmax = 0;
    //unsigned long tmin = 1 << 31;   // Je veux le nombre maximal possible
    //unsigned long tavg = 0;

    for(int i = 0; i < 3; ++i)
    {
        //unsigned long t = getCurrentTime();
        process_stat();
        //unsigned long t2 = getCurrentTime() - t;
        //printf("total: %lu ns  - 1 process: %lu ns\n", t2, t2 / NB_PROC);

        //tmax = t2 > tmax ? t2 : tmax;
        //tmin = t2 < tmin ? t2 : tmin;
        //tavg += t2 / NB_TEST;
    }

    //printf("tmin: %lu ns  - 1 process: %lu ns\n", tmin, tmin / NB_PROC);
    //printf("tmax: %lu ns  - 1 process: %lu ns\n", tmax, tmax / NB_PROC);
    //printf("tavg: %lu ns  - 1 process: %lu ns\n", tavg, tavg / NB_PROC);

    return 0;
}
