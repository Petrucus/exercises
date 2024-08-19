#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct {
    int key;
    int value;
    int is_occupied;
} HashItem;

typedef struct {
    HashItem items[TABLE_SIZE];
} HashTable;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(HashTable* table, int key, int value) {
    int index = hash(key);
    while (table->items[index].is_occupied) {
        if (table->items[index].key == key) {
            table->items[index].value = value;
            return;
        }
        index = (index + 1) % TABLE_SIZE;  // Linear probing
    }
    table->items[index].key = key;
    table->items[index].value = value;
    table->items[index].is_occupied = 1;
}

int search(HashTable* table, int key) {
    int index = hash(key);
    while (table->items[index].is_occupied) {
        if (table->items[index].key == key) {
            return table->items[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;  // Key not found
}

int main() {
    HashTable table = {0};  // Initialize all elements to 0
    
    insert(&table, -5, 50);
    insert(&table, 1000000, 1000);
    insert(&table, 42, 420);

    printf("Value for key -5: %d\n", search(&table, -5));
    printf("Value for key 1000000: %d\n", search(&table, 1000000));

    return 0;
}