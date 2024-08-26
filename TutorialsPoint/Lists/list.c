// Create Linked List
// Display Linked List in Reverse

// Find size of Linked List

// Search an Item in Linked List

// Update an Item in Linked List

// Remove an Item from Linked List

// Combine Two Linked List

// Split Linked List into two
#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link* next;
    struct link* previous;
};

typedef struct link link;

link* create_link(int data, link* next, link* previous)
{
    link* new_link = calloc(1, sizeof(link));
    if(new_link)
    {
        new_link->data = data;
        new_link->next = next;
        new_link->previous = previous;
    }
    return (new_link);
}

link* chain_creator(int n, link* previous)
{   
    if (n < 1)
        return (NULL);
    link* next = chain_creator(n-1, NULL);
    link* new_link = create_link(n, next, previous);

    if (next)
        next->previous = new_link;
    return (new_link);
}

int main()
{
    link* mylink = chain_creator(4, NULL);
    while(mylink->next != NULL)
    {
        printf("%d\n", mylink->data);
        printf("%p\n", (void*)mylink->previous);
        mylink = mylink->next;
        free(mylink->previous);
    }
    printf("%d\n", mylink->data);
    printf("%p\n", (void*)mylink->previous);
    free(mylink);
    return (0);    
}
