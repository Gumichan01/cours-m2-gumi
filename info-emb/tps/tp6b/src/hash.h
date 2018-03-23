
/*
    TP n° 6 - Luxon JEAN-PIERRE

    Table de hachage - API
*/

#include "list.h"
#include <stdbool.h>

struct hash
{
    struct list_head ** hash_table;
    size_t size;
};


// Create the hash table
#define INIT_HASH_TABLE(htable) htable = htable_make();

// Destroy hash_table
#define DESTROY_HASH_TABLE(htable) free(htable->hash_table); free(htable);

// Create the hash table
struct hash * htable_make();

// Insert element in an hash table
bool htable_add(struct list_head * node, struct hash * htable);
// Remove an element from an hash table
bool htable_del(struct list_head * node, struct hash * htable);
// Find an element in an hash table
struct list_head * htable_find(size_t node_id, struct hash * htable);
