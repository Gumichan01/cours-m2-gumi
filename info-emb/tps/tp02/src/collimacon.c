
/*
  TP 2 - JEAN-PIERRE Luxon
  collimacon.c
*/

#include <stdlib.h>

int32_t * allocate_array(int32_t width, int32_t height);
void generate_numbers(int32_t * array_2d, int32_t width, int32_t height);


int32_t * collimacon(int32_t width, int32_t height)
{
    int32_t * array_2d = NULL;
    array_2d = allocate_array(width, height);

    if(array_2d == NULL)
        return NULL;

    generate_numbers(array_2d, width, height);
    return array_2d;
}


int32_t * allocate_array(int32_t width, int32_t height)
{
    return (int32_t *) malloc(sizeof(int32_t) * width * height);
}


void generate_numbers(int32_t * array_2d, int32_t width, int32_t height)
{
    int32_t i = 0, j = 0;
    int32_t count = 1;
    int32_t current_w = width;
    int32_t current_h = height;

    while(count < width * height + 1)
    {
        // Vers la droite
        for(j = width - current_w; j < current_w; j++)
        {
            array_2d[i * width + j] = count++;
        }

        j = current_w - 1;

        if(count > width * height)
          break;

        // Vers le bas
        for(i = height - current_h + 1; i < current_h; i++)
        {
            array_2d[i * width + j] = count++;
        }

        i = current_h - 1;

        if(count > width * height)
          break;

        // Vers la gauche
        for(j = current_w - 2; j >= width - current_w; j--)
        {
            array_2d[i * width + j] = count++;
        }

        current_h--;
        j = width - current_w;

        if(count > width * height)
          break;

        for(i = current_h - 1; i >= height - current_h; i--)
        {
            array_2d[i * width + j] = count++;
        }

        current_w--;
        i = height - current_h;
    }
}
