#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct mutalist {
    struct mutalist* next;
    struct mutalist* previous;
    char name[];
} token;

token* generator(char* name)
{
    token* gen = malloc(sizeof(token) + strlen(name) + 1);
    if (!gen)
        exit(1);
    strcpy(gen->name, name);
    gen->next = NULL;
    gen->previous = NULL;
    return (gen);
}

int main()
{
    token* name_list = NULL;
    char* names[] = {"Alice", "Bob", "WhyIsItAlwaysYouTwo", "TheActualThirdPerson", "Fifth", NULL};
    char** names_ptr = names;

    token* prev = NULL;
    while (*names_ptr)
    {
        token* current = generator(*names_ptr);
        current->previous = prev;
        if (prev)
            prev->next = current;
        else
            name_list = current;
        prev = current;
        names_ptr++;
    }
    token* current = name_list;
    while (current)
    {
        puts(current->name);
        current = current->next;
    }
    current = name_list->next->next->next->next;
    while(current->previous)
    {
        puts(current->name);
        current = current->previous;
    }
    puts(current->name);
    while (current)
    {
        token* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}