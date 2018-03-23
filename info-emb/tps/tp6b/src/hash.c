
/*
    TP n° 6 - Luxon JEAN-PIERRE

    Table de hachage - Implémentation
*/

#include "hash.h"

#include <string.h>
#include <stdlib.h>

#define DEFAULT_SZ 10

struct hash * htable_make()
{
    struct hash * htable = malloc(sizeof(struct hash));

    if(htable != NULL)
    {
        htable->hash_table = malloc(DEFAULT_SZ * sizeof(struct list_head **) );
        if(htable->hash_table == NULL)
        {
            free(htable);
            htable = NULL;
        }
        else
        {
            htable->size = DEFAULT_SZ;
            memset(htable->hash_table, (int) NULL, htable->size);
        }
    }

    return htable;
}

bool htable_add(struct list_head * node, struct hash * htable)
{
    if(node == NULL || htable == NULL)
        return false;

    // Fonction de hachage
    size_t index = node->id % htable->size;

    // S'il n'y a pas déjà une liste existante -> on peut juste mettre node
    // Sinon, on ajoute les node dans la liste
    if(htable->hash_table[index] == NULL)
        htable->hash_table[index] = node;
    else
        list_add(node, htable->hash_table[index]);

    return true;
}

bool htable_del(struct list_head * node, struct hash * htable)
{
    if(htable_find(node->id, htable) == NULL)
        return false;

    list_del(node);
    return true;
}

struct list_head * htable_find(size_t node_id, struct hash * htable)
{
    if(htable == NULL)
        return NULL;

    size_t index = node_id % htable->size;   // Fonction de hachage

    if(htable->hash_table[index] == NULL)
        return NULL;
    else
    {
        struct list_head *head = htable->hash_table[index];
        struct list_head *cur  = htable->hash_table[index]->next;

        if(head == NULL || cur == NULL)
            return NULL;

        // Si le noeud que je cherche est la tête de la liste -> OK
        if(head->id == node_id)
            return head;

        // Sinon on le cherche ailleurs dans la liste
        while(cur != head && cur->id != node_id)
        {
            cur = cur->next;
        }

        return cur->id == node_id ? cur : NULL;
    }
}
