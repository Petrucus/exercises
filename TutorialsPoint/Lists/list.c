// Create Linked List
// Display Linked List in Reverse

// Find size of Linked List

// Search an Item in Linked List

// Update an Item in Linked List

// Remove an Item from Linked List

// Combine Two Linked List

// Split Linked List into two

#define <stdlib.h>

struct link {
    int data;
    struct link* next;
    struct link* previous;
};

typdef struct link link;

link* create_link(int data, link* next, link* previous)
{
    link* new_link = calloc(1, sizeof(link));
    new_link->data = data;
    new_link->next = next;
    new_link->previous = previous;
    return (link);
}

link* chain_creator(int n)
{
    if (n == 0)
        return  ;
    create_link(n, create_link(n+1), create_link(n-1));
    
}

int main()
{
    
    return (0);    
}