#include <stdlib.h>

char* create(char* e, size_t len)
{
    e = calloc(sizeof(char), len + 1);
    if (!e)
        exit(1);
    e[len] = '\0';
    return (e);
}

size_t len(char* e)
{
    size_t len;

    len = 0;
    while(e[len])
        len++;
    return (len);
}

char* str_cpy(char *e, int action)
{
    size_t  iter;
    int     str_len;
    char*   retour = NULL;
    
    str_len = len(e);
    retour = create(retour, str_len);
    iter = 0;
    if (action)
        while(str_len - iter)
        {
            retour[iter] = e[str_len - iter - 1];
            iter++;
        }
    else
        while(*e)
        {
            retour[iter] = *e;
            iter++;
            e++;
        }
    return (retour);
}

#include <stdio.h>
int main(void)
{
    char* a = "Tomato is the best fruit; The only fruit that has a natural place in the salad and not the fruit salad!";
    char* b = str_cpy(a, 0);
    char* c = str_cpy(b, 1);

    puts(b);
    puts(c);
    printf("Pointer of a:\t%p\nPointer of b:\t%p\nPointer of c:\t%p\n", a, b, c);
}