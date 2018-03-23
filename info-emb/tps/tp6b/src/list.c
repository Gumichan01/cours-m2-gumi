
/*
    TP n°6 - Luxon JEAN-PIERRE

    Liste doublement chainée - Implémentation
*/

#include "list.h"

#include <stdio.h>

// Just un petit compteur, pour avoir des identifiants uniques
size_t counter()
{
    static size_t v = 0;
    return (++v);
}

void list_add(struct list_head *node, struct list_head *head)
{
    head->next->prev = node;
    node->next = head->next;
    node->prev = head;
    head->next = node;
}

void list_del(struct list_head *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->prev = node->next = node;
}
