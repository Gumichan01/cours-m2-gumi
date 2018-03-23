
/*
    TP n°4 - Luxon JEAN-PIERRE
    benchmark thread
    Calcul le temps de création et de terminaison d'un thread
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NB_TEST 10
#define NB_THREAD 100000

unsigned long getCurrentTime()
{
    time_t s;
    struct timespec t;

    clock_gettime(CLOCK_MONOTONIC_RAW, &t);

    s = t.tv_sec;
    return (unsigned long) (s * 1000000000 + t.tv_nsec);
}


void * th_task(void * data)
{
    pthread_exit(NULL);
}

void thread_stat()
{
    pthread_t th;
    int p = 0;

    for(int i = 0; i < NB_THREAD; ++i)
    {
        p = pthread_create(&th, NULL, th_task, NULL);

        if(p != 0)
            perror("pthread_create:");
        else
          pthread_join(th,NULL);
    }
}


int main()
{
    unsigned long tmax = 0;
    unsigned long tmin = 1 << 31;   // Je veux le nombre maximal possible
    unsigned long tavg = 0;

    printf("Benchmark thread\n");

    for(int i = 0; i < NB_TEST; ++i)
    {
        unsigned long t = getCurrentTime();
        thread_stat();
        unsigned long t2 = getCurrentTime() - t;
        printf("total: %lu ns  - 1 process: %lu ns\n", t2, t2 / NB_THREAD);

        tmax = t2 > tmax ? t2 : tmax;
        tmin = t2 < tmin ? t2 : tmin;
        tavg += t2 / NB_TEST;
    }

    printf("tmin: %lu ns  - 1 process: %lu ns\n", tmin, tmin / NB_THREAD);
    printf("tmax: %lu ns  - 1 process: %lu ns\n", tmax, tmax / NB_THREAD);
    printf("tavg: %lu ns  - 1 process: %lu ns\n", tavg, tavg / NB_THREAD);
    return 0;
}
