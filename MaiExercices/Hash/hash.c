#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct { char* key; int value; } Entry;
typedef struct { Entry* entries[SIZE]; } HashTable;

unsigned int hash(char* key) {
    unsigned int hash = 0;
    while (*key) hash = 31 * hash + *key++;
    return hash % SIZE;
}

HashTable* create_table() {
    return calloc(1, sizeof(HashTable));
}

void insert(HashTable* table, char* key, int value) {
    unsigned int index = hash(key);
    while (table->entries[index]) {
        if (strcmp(table->entries[index]->key, key) == 0) {
            table->entries[index]->value = value;
            return;
        }
        index = (index + 1) % SIZE;
    }
    Entry* entry = malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    table->entries[index] = entry;
}

int get(HashTable* table, char* key) {
    unsigned int index = hash(key);
    while (table->entries[index]) {
        if (strcmp(table->entries[index]->key, key) == 0)
            return table->entries[index]->value;
        index = (index + 1) % SIZE;
    }
    return -1;
}

int main() {
    HashTable* table = create_table();
    insert(table, "bob", 3);
    insert(table, "mary", 4);
    printf("%d\n", get(table, "bob"));
    return 0;
}