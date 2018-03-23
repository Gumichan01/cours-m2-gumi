
/*
    TP n°5 - Luxon JEAN-PIERRE
    Inversion de priorité
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N1 50000
#define N2 50000

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int v  = 0;
static int pv = 0;

static void * th_a(void * data)
{
    int i;
    int j;

    pthread_mutex_lock(&mutex);

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j);

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

static void * th_b(void * data)
{
    int i;
    int j;

    pv = v;

    if(pv == 1)
        printf("Inversion de priorité\n");
    else
        printf("Pas d'inversion de priorité\n");

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j);

    pthread_exit(NULL);
}

static void * th_c(void * data)
{
    int i;
    int j;

    v  = 1;
    pthread_mutex_lock(&mutex);
    v  = 2;
    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j);

    pthread_mutex_unlock(&mutex);
    v  = 0;
    pthread_exit(NULL);
}

static void thread_run()
{
    pthread_t tha, thb, thc;
    pthread_attr_t attr_a, attr_b, attr_c;
    struct sched_param pa, pb, pc;
    int e = 0;

    pa.sched_priority = 5;
    pb.sched_priority = 32;
    pc.sched_priority = 80;

    pthread_attr_init(&attr_a);
    pthread_attr_init(&attr_b);
    pthread_attr_init(&attr_c);

    pthread_attr_setschedpolicy(&attr_a, SCHED_FIFO);
    pthread_attr_setschedpolicy(&attr_b, SCHED_FIFO);
    pthread_attr_setschedpolicy(&attr_c, SCHED_FIFO);

    pthread_attr_setschedparam(&attr_a, &pa);
    pthread_attr_setschedparam(&attr_b, &pb);
    pthread_attr_setschedparam(&attr_c, &pc);

    pthread_attr_setinheritsched(&attr_a, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr_b, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr_c, PTHREAD_EXPLICIT_SCHED);

    e = pthread_create(&tha, &attr_a, th_a, NULL);

    if(e != 0)
    {
        perror("pthread_create a:");
        return;
    }

    e = pthread_create(&thc, &attr_c, th_c, NULL);

    if(e != 0)
    {
        perror("pthread_create b:");
        pthread_join(tha,NULL);
        return;
    }

    e = pthread_create(&thb, &attr_b, th_b, NULL);

    if(e != 0)
    {
        perror("pthread_create b:");
        pthread_join(tha,NULL);
        pthread_join(thc,NULL);
        return;
    }
}


int main()
{
    thread_run();
    pthread_exit(NULL);
}
