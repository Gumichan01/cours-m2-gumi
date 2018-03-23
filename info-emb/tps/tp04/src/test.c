
/*
    TP n°4 - Luxon JEAN-PIERRE
    Commutation de contexte

    Ce programme mesure le temps de commutation de contexte entre deux processus.
    Pour cela, on utilise dans ce programme des tubes, avec lesquels on faire communiquer
    les deux processus (2 tubes). Il y a également un troisième tube qui sera utilisé pour
    transférer le temps mesuré vers le père.

    ATTENTION: Il faudra lancer le programme en tant que root

    NOTE:
    Ce code source est une version modifiée d'un code source rédigé par Sumit Gemini.
    Je l'ai modifié pour l'adapter aux besoins du TP
    source : https://stackoverflow.com/a/38344636
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <errno.h>

#define NB_LAUNCH 1

unsigned long t_start = 0;
unsigned long t_end   = 0;
unsigned long total   = 0;
void context_switch();

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
    printf("Context Switch\n");

    for(int i = 0; i < NB_LAUNCH; ++i)
    {
        t_start = 0;
        t_end   = 0;
        context_switch();
    }

    printf("total: %lu ns  - 1 process: %lu ns\n", total, total / NB_LAUNCH);

    return 0;
}

void context_switch()
{
/*********************************************************************************************
    To make sure context-switching processes are located on the same processor :
    1. Bind a process to a particular processor using sched_setaffinity.
    2. To get the maximum priority value (sched_get_priority_max) that can be used with
       the scheduling algorithm identified by policy (SCHED_FIFO).**
    **********************************************************************************************/

    cpu_set_t set;
    struct sched_param prio_param;
    int prio_max;

    CPU_ZERO(&set);
    CPU_SET(0, &set);
    memset(&prio_param,0,sizeof(struct sched_param));

    if (sched_setaffinity( getpid(), sizeof( cpu_set_t ), &set ))
    {
        perror("sched_setaffinity");
        exit(EXIT_FAILURE);
    }

    if( (prio_max = sched_get_priority_max(SCHED_FIFO)) < 0 )
    {
            perror("sched_get_priority_max");
    }

    prio_param.sched_priority = prio_max;
    if( sched_setscheduler(getpid(),SCHED_FIFO,&prio_param) < 0 )
    {
            perror("sched_setscheduler");
            exit(EXIT_FAILURE);
    }

    int     ret=-1;
    int     firstpipe[2];
    int     secondpipe[2];
    char    string[] = "Hello, world!\n";
    char    temp[] = "Sumit Gemini!\n";
    char    tempbuffer[80];
    char    readbuffer[80];

    // Create an unnamed first pipe
    if (pipe(firstpipe) == -1)
    {
        fprintf(stderr, "parent: Failed to create pipe\n");
        return;
    }

    // create an unnamed Second pipe
    if (pipe(secondpipe) == -1)
    {
        fprintf(stderr, "parent: Failed to create second pipe\n");
        return;
    }

    if((ret=fork())==-1)
        perror("fork");
    else if(ret == 0)
    {
        int n=-1;

        /*for(n=0;n<5;n++)
        {
            read(firstpipe[0], readbuffer, sizeof(readbuffer));
            write(secondpipe[1], temp, strlen(temp)+1);
        }*/

        t_start = getCurrentTime();
        n = sizeof(struct timeval);

        exit(0);
    }
    else
    {
        int n=-1;

        /* Read in a string from the pipe */
        /*for(n=0;n<5;n++)
        {
            write(firstpipe[1], string, strlen(string)+1);
            read(secondpipe[0], tempbuffer, sizeof(tempbuffer));
            //printf("Received temp: %s", tempbuffer);
        }*/

        wait(NULL);
        t_end = getCurrentTime();
        // context switch total
        printf("%ld %ld", t_start, t_end);
        total += (t_end - t_start);
    }
}
