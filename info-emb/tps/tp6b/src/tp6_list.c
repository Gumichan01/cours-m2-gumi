
/*
    TP n° 6 - Luxon JEAN-PIERRE

    Liste doublement chainée - programme test
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define N 2

struct sample
{
    // Mon objet doit avoir plusieurs nodes pour pouvoir être dans plusieurs listes.
    // Chaque node sera integré dans une liste chainée différente.
    struct list_head list_all[N];
    int v;
};


int main()
{
    struct sample object, s1;
    struct list_head *my_list = NULL, *another_list = NULL;
    struct sample *cur = NULL;                  // Pour l'itération

    // Allocation
    my_list = malloc(sizeof(struct list_head));

    if(my_list == NULL)
    {
        perror("my_list - malloc");
        return -1;
    }

    another_list = malloc(sizeof(struct list_head));

    if(another_list == NULL)
    {
        perror("my_list - malloc");
        free(my_list);
        return -1;
    }

    INIT_LIST_HEAD(my_list);
    INIT_LIST_HEAD(another_list);

    for(int i = 0; i < N; i++)
    {
        INIT_LIST_HEAD((&object.list_all[i]));
        INIT_LIST_HEAD((&s1.list_all[i]));
    }

    // Valeurs
    object.v = 42;
    s1.v  = 64;

    list_add(&(object.list_all[0]), my_list);
    list_add(&(object.list_all[1]), another_list);
    list_add(&(s1.list_all[1]), another_list);

    printf("In my_list\n");
    list_for_each_entry(cur, my_list, list_all[0])
    {
        printf("%d ", cur->v);
    }
    printf("\n");

    printf("In another_list\n");
    list_for_each_entry(cur, another_list, list_all[1])
    {
        printf("%d ", cur->v);
    }
    printf("\n");

    list_del(&(s1.list_all[1]));

    for(int i = 0; i < N; i++)
        list_del(&object.list_all[i]);

    // clean
    free(my_list);
    free(another_list);
    return 0;
}
