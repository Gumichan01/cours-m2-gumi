
/*
  TP 2 - JEAN-PIERRE Luxon
  Collimaçon - Version améliorée
*/

#include <stdio.h>
#include <stdlib.h>

#include "collimacon.h"

#define NB_PARAM 3

void print_error(char * exe);
void print_array(int32_t * array_2d, int32_t width, int32_t height);

int main(int argc, char *argv[])
{
    int32_t width  = 0;
    int32_t height = 0;

    if(argc != NB_PARAM)
    {
        print_error(argv[0]);
        return -1;
    }

    width  = atoi(argv[2]);
    height = atoi(argv[1]);

    if(width <= 0 || height <= 0)
    {
        fprintf(stderr, "Invalid dimension\n");
        print_error(argv[0]);
        return -1;
    }

    int32_t * array_2d = collimacon(width, height);

    if(array_2d == NULL)
    {
        perror("malloc");
        return -1;
    }

    print_array(array_2d, width, height);
    free(array_2d);
    return 0;
}

void print_error(char * exe)
{
    fprintf(stderr, "Usage: %s <nb_lines> <nb_column>\n", exe);
}

void print_array(int32_t * array_2d, int32_t width, int32_t height)
{
    for(int32_t i = 0; i < height; i++)
    {
        for(int32_t j= 0; j < width; j++)
        {
            printf("%d ", array_2d[i * width + j]);
        }
        printf("\n");
    }
}
