
/*
    TP n°4 - Luxon JEAN-PIERRE
    benchmark changement de contexte entre processus
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define NB_TEST 10
#define NB_PROC 1000000
#define SNAME "/shmnsys"

unsigned long getCurrentTime()
{
    time_t s;
    struct timespec t;

    clock_gettime(CLOCK_MONOTONIC_RAW, &t);

    s = t.tv_sec;
    return (unsigned long) (s * 1000000000 + t.tv_nsec);
}

int main()
{
    pid_t p;
    unsigned long t0, t1, dt;
    unsigned long tmax = 0;
    unsigned long tmin = 1 << 31;   // Je veux le nombre maximal possible
    unsigned long tavg = 0;


    // semaphore
    sem_t *sem = sem_open(SNAME, O_CREAT, 0644, 0);

    if(sem == SEM_FAILED)
    {
        perror("sem_open");
        sem_close(sem);
        return -1;
    }

    printf("Benchmark context switch process\n");

    for(int i = 0; i < NB_TEST; ++i)
    {
        p = fork();

        if(p == -1)
            perror("fork");
        else if(p == 0)
        {
            for(int i = 0; i < NB_PROC; ++i)
            {
                sem_post(sem);
            }
            exit(0);
        }
        else
        {
            t0 = getCurrentTime();
            for(int j = 0; j < NB_PROC; ++j)
            {
                sem_wait(sem);
            }
            t1 = getCurrentTime();
            wait(NULL);
        }

        dt = t1 - t0;
        tmax = dt > tmax ? dt : tmax;
        tmin = dt < tmin ? dt : tmin;
        tavg += dt / NB_TEST;
    }

    printf("tmin: %lu ns  - 1 context switch: %lu ns\n", tmin, tmin / NB_PROC);
    printf("tmax: %lu ns  - 1 context switch: %lu ns\n", tmax, tmax / NB_PROC);
    printf("tavg: %lu ns  - 1 context switch: %lu ns\n", tavg, tavg / NB_PROC);

    sem_close(sem);
    return 0;
}
