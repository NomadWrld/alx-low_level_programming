#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/* Task 0: Basic hash table node structure */
typedef struct hash_node_s {
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/* Task 1: Hash table structure */
typedef struct hash_table_s {
    size_t size;
    hash_node_t **array;
} hash_table_t;

/* Task 2: Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/* Task 3: Collision handling - chaining */
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/* Task 4: Resize the hash table */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
void hash_table_delete(hash_table_t *ht);

/* Task 5: Implement the djb2 hash function */
unsigned long int hash_djb2(const unsigned char *str);

/* Task 6: Create a sorted hash table */
typedef struct shash_node_s {
    char *key;
    char *value;
    struct shash_node_s *next;
    struct shash_node_s *sprev;
    struct shash_node_s *snext;
} shash_node_t;

typedef struct shash_table_s {
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/* Task 7: Implement the djb2 hash function for sorted hash table */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

#endif /* HASH_TABLES_H */
