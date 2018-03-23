
/*
    TP n° 6 - Luxon JEAN-PIERRE

    Table de hachage - programme test
*/

#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

#define SZ 50

struct sample
{
    struct list_head list_all[SZ];
    int v;
};

int main()
{
    struct sample object, obj2;
    struct list_head **my_list = NULL;
    struct hash * htable = NULL;

    // Allocation
    INIT_HASH_TABLE(htable);

    my_list = malloc(sizeof(struct list_head **) * SZ);

    if(my_list == NULL)
    {
        perror("my_list - malloc");
        return -1;
    }

    for(int i = 0; i < SZ; i++)
    {
        my_list[i] = malloc(sizeof(struct list_head *));

        if(my_list[i] == NULL)
        {
            for(int j = 0; j < i; j++)
                free(my_list[j]);

            free(my_list);
            return -2;
        }

        INIT_LIST_HEAD(my_list[i]);
    }

    object.v = 42;
    obj2.v = 64;

    for(int i = 0; i < SZ; i++)
    {
        INIT_LIST_HEAD((&object.list_all[i]));
        INIT_LIST_HEAD((&obj2.list_all[i]));

        bool ok = htable_add((&object.list_all[i]), htable);

        if(!ok)
            printf("TEST - add %d KO\n", i);

        ok = htable_add((&obj2.list_all[i]), htable);

        if(!ok)
            printf("TEST - add %d KO\n", i);
    }

    printf("\nFind a node that does not exist.\n");
    struct list_head *h = htable_find(1024, htable);

    if(h == NULL)
        printf("TEST - NULL pointer: OK\n");
    else
        printf("TEST - Not NULL pointer: KO\n");

    printf("\nFind a valid node\n");
    h = htable_find(object.list_all[8].id, htable);

    if(h == NULL)
        printf("TEST - NULL pointer: KO\n");
    else
    {
        printf("TEST - Not NULL pointer: OK\n\n");
        printf("id: %u\n", h->id);
        struct sample * cur = container_of(h, struct sample, list_all[8]);
        if(cur != NULL)
            printf("value: %u\n", cur->v);
    }

    printf("Removed the node I found\n");
    bool res = htable_del(h, htable);

    if(res)
        printf("TEST - deletion OK\n");
    else
        printf("TEST - deletion failed\n");


    printf("\nRemove all nodes\n");
    for(int i = 0; i < SZ; i++)
    {
        h = htable_find(object.list_all[i].id, htable);

        if(h != NULL)
            htable_del(h, htable);
    }

    // Clean
    DESTROY_HASH_TABLE(htable);

    for(int j = 0; j < SZ; j++)
        free(my_list[j]);

    free(my_list);
    return 0;
}
