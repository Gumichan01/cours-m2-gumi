
/*
  TP 2 - JEAN-PIERRE Luxon
  Collimaçon - Test automatisé
*/

#include <stdio.h>
#include <stdlib.h>

#include "collimacon.h"

#define MAX_ARRAY_SIZE 10000

// Résultats attendus

#define ROW_SZ 9
#define COLUNM_SZ 9
#define SQUARE_DIM 3
#define RECT_W 2
#define RECT_H 3
#define RECT2_W 2
#define RECT2_H 4

int row_tab[ROW_SZ] = {1,2,3,4,5,6,7,8,9};
int colunm_tab[COLUNM_SZ] = {1,2,3,4,5,6,7,8,9};
int square_tab[SQUARE_DIM * SQUARE_DIM] = {1,2,3,8,9,4,7,6,5};
int rect1_tab[RECT_W * RECT_H] = {1,2,6,3,5,4};
int rect2_tab[RECT_W * RECT_H] = {1,2,3,6,5,4};
int rect3_tab[RECT2_W * RECT2_H] = {1,2,8,3,7,4,6,5};
int rect4_tab[RECT2_W * RECT2_H] = {1,2,3,4,8,7,6,5};

int equals(int32_t * array_2d, int32_t * expected_array, int32_t sz);

void test();
void test_row();
void test_column();
void test_square();
void test_rectangle1();
void test_rectangle2();
void test_rectangle3();
void test_rectangle4();

int main(int argc, char *argv[])
{
    printf("Start test\n");
    test();
    printf("End of test\n");
    return 0;
}

int equals(int32_t * array_2d, int32_t * expected_array, int32_t sz)
{
    if(array_2d == NULL || expected_array == NULL)
    {
      printf("Internal Error - null array\n");
    }

    int i = 0;
    while(i < sz && array_2d[i] == expected_array[i])
      i++;

    return i == sz;
}

void test()
{
    printf("- Row (%d line, %d colunm)... ", 1, ROW_SZ);
    test_row();
    printf("- Colunm (%d line, %d colunm)... ", ROW_SZ, 1);
    test_column();
    printf("- Square (%d line, %d colunm)... ", SQUARE_DIM, SQUARE_DIM);
    test_square();
    printf("- rectangle 1 (%d line, %d colunm)... ", RECT_H, RECT_W);
    test_rectangle1();
    printf("- rectangle 2 (%d line, %d colunm)... ", RECT_W, RECT_H);
    test_rectangle2();
    printf("- rectangle 3 (%d line, %d colunm)... ", RECT2_H, RECT2_W);
    test_rectangle3();
    printf("- rectangle 4 (%d line, %d colunm)... ", RECT2_W, RECT2_H);
    test_rectangle4();
}

void test_row()
{
    int32_t * array_2d = collimacon(1, ROW_SZ);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
        printf("%s\n", (equals(array_2d, row_tab, ROW_SZ) ? "OK" : "KO"));

    free(array_2d);
}

void test_column()
{
    int32_t * array_2d = collimacon(COLUNM_SZ, 1);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
        printf("%s\n", (equals(array_2d, colunm_tab, COLUNM_SZ) ? "OK" : "KO"));

    free(array_2d);
}

void test_square()
{
    int32_t * array_2d = collimacon(SQUARE_DIM, SQUARE_DIM);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
      printf("%s\n", (equals(array_2d, square_tab, SQUARE_DIM * SQUARE_DIM) ? "OK" : "KO"));

    free(array_2d);
}

void test_rectangle1()
{
    int32_t * array_2d = collimacon(RECT_W, RECT_H);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
      printf("%s\n", (equals(array_2d, rect1_tab, RECT_W * RECT_H) ? "OK" : "KO"));

    free(array_2d);
}

void test_rectangle2()
{
    int32_t * array_2d = collimacon(RECT_H, RECT_W);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
      printf("%s\n", (equals(array_2d, rect2_tab, RECT_W * RECT_H) ? "OK" : "KO"));

    free(array_2d);
}

void test_rectangle3()
{
    int32_t * array_2d = collimacon(RECT2_W, RECT2_H);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
      printf("%s\n", (equals(array_2d, rect3_tab, RECT2_W * RECT2_H) ? "OK" : "KO"));

    free(array_2d);
}

void test_rectangle4()
{
    int32_t * array_2d = collimacon(RECT2_H, RECT2_W);

    if(array_2d == NULL)
        printf("Internal Error\n");
    else
      printf("%s\n", (equals(array_2d, rect4_tab, RECT2_W * RECT2_H) ? "OK" : "KO"));

    free(array_2d);
}
