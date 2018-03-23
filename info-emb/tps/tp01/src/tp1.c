
/**
  TP 1 - JEAN-PIERRE Luxon
  Collimaçon
*/

#include <stdio.h>
#include <stdlib.h>

#define NB_PARAM 3

int32_t * allocate_array(int32_t width, int32_t height);
void generate_numbers(int32_t * array_2d, int32_t width, int32_t height);
void print_array(int32_t * array_2d, int32_t width, int32_t height);

int main(int argc, char *argv[])
{
    int32_t width      = 0;
    int32_t height     = 0;
    int32_t * array_2d = NULL;

    if(argc != NB_PARAM)
    {
        fprintf(stderr, "Usage: %s <nb_lines> <nb_column>\n", argv[0]);
        return -1;
    }

    width  = atoi(argv[2]);
    height = atoi(argv[1]);

    if(width == 0 || height == 0)
    {
        fprintf(stderr, "Invalid dimension\n");
        // Oui je sais, c'est redondant (-_-)
        fprintf(stderr, "Usage: %s <nb_lines> <nb_column>\n", argv[0]);
        return -1;
    }

    array_2d = allocate_array(width, height);

    generate_numbers(array_2d, width, height);
    print_array(array_2d, width, height);

    free(array_2d);
    return 0;
}

int32_t * allocate_array(int32_t width, int32_t height)
{
    return (int32_t *) malloc(sizeof(int32_t) * width * height);
}


void generate_numbers(int32_t * array_2d, int32_t width, int32_t height)
{
    int32_t i, j;
    int32_t count = 1;
    int32_t current_w = width;
    int32_t current_h = height;

    if(height == 1)
    {
        for(int32_t j= 0; j < width; j++)
        {
            array_2d[j] = j + 1;
        }
    }
    else if(width == 1)
    {
        for(int32_t i = 0; i < height; i++)
        {
            array_2d[i] = i + 1;
        }
    }
    else
    {
        i = 0;
        j = 0;

        while(count < width * height + 1)
        {
            // Vers la droite
            for(j = width - current_w; j < current_w; j++)
            {
                array_2d[i * width + j] = count++;
            }

            j = current_w - 1;

            // Vers le bas
            for(i = height - current_h + 1; i < current_h; i++)
            {
                array_2d[i * width + j] = count++;
            }

            i = current_h - 1;

            // Bon, j'avoue, c'est un peu du bricolage
            if(count > width * height)
              break;

            // Vers la gauche
            for(j = current_w - 2; j >= width - current_w; j--)
            {
                array_2d[i * width + j] = count++;
            }

            current_h--;
            j = width - current_w;

            for(i = current_h - 1; i >= height - current_h; i--)
            {
                array_2d[i * width + j] = count++;
            }

            current_w--;
            i = height - current_h;
        }
    }
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
