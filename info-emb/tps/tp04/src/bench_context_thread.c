
/*
    TP n°4 - Luxon JEAN-PIERRE
    benchmark changement de contexte entre threads
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>

#define NB_TEST 10
#define NB_THREAD 1000000
#define SNAME "/shmnsys"

unsigned long getCurrentTime()
{
    time_t s;
    struct timespec t;

    clock_gettime(CLOCK_MONOTONIC_RAW, &t);

    s = t.tv_sec;
    return (unsigned long) (s * 1000000000 + t.tv_nsec);
}

void * send(void * data)
{
    sem_t *sem = (sem_t *) data;

    for(int i = 0; i < NB_THREAD; ++i)
    {
        sem_post(sem);
    }

    pthread_exit(NULL);
}


int main()
{
    pthread_t th;
    unsigned long t0, t1, dt;

    // semaphore
    sem_t *sem = sem_open(SNAME, O_CREAT, 0644, 0);

    if(sem == SEM_FAILED)
    {
        perror("sem_open");
        sem_close(sem);
        return -1;
    }

    unsigned long tmax = 0;
    unsigned long tmin = 1 << 31;   // Je veux le nombre maximal possible
    unsigned long tavg = 0;

    printf("Benchmark context switch thread\n");

    for(int i = 0; i < NB_TEST; ++i)
    {
        int err = pthread_create(&th, NULL, send, sem);

        if(err == -1)
        {
            perror("pthread_create");
            sem_close(sem);
            return -1;
        }

        t0 = getCurrentTime();
        for(int j = 0; j < NB_THREAD; ++j)
        {
            sem_wait(sem);
        }
        t1 = getCurrentTime();
        pthread_join(th, NULL);

        dt = t1 - t0;
        tmax = dt > tmax ? dt : tmax;
        tmin = dt < tmin ? dt : tmin;
        tavg += dt / NB_TEST;
    }

    printf("tmin: %lu ns  - 1 context switch: %lu ns\n", tmin, tmin / NB_THREAD);
    printf("tmax: %lu ns  - 1 context switch: %lu ns\n", tmax, tmax / NB_THREAD);
    printf("tavg: %lu ns  - 1 context switch: %lu ns\n", tavg, tavg / NB_THREAD);

    sem_close(sem);
    return 0;
}
