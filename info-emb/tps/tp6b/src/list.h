
/*
    TP n°6 - Luxon JEAN-PIERRE

    Liste doublement chainée - API
*/

#include <stddef.h>

struct list_head
{
    struct list_head *next, *prev;
    size_t id;
};

size_t counter();

/* init an element */
#define INIT_LIST_HEAD(head)    \
head->next = head->prev = head; \
head->id   = counter();


void list_add(struct list_head *node, struct list_head *head);
/* remove element "node" from a list */
void list_del(struct list_head *node);

/* iterate over a list starting at head */
#define container_of(ptr, type, member) ({                      \
const typeof( ((type *)0)->member ) *__mptr = (ptr);            \
(type *)( (char *)__mptr - offsetof(type, member) );})

#define list_for_each_entry(cur, head, member)                  \
for (cur = container_of((head)->next, typeof(*cur), member);    \
     &cur->member !=(head);                                     \
     cur = container_of(cur->member.next, typeof(*cur), member))
