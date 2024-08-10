#include <stdlib.h>
void ifnot_space(char e, int* word_count, char** list_of_words, int* word_len)
{
    if(e != 32)
    {
        *word_count++;
        list_of_words = realloc(sizeof(char*),  mem++);
        *word_len = 0;
    }
}

void if_space(char e, int* word_count, char** list_of_words, int* word_len)
{
    if(e == 32)
    {
        *word_count++;
        list_of_words = realloc(sizeof(char*),  mem++);
        *word_len = 0;
    }
}

void while_space(char** e, int* word_len)
{
    while(*e == 32)
    {
        *word_len++;
        (*e)++;
        e++;
    }
}

void while_not_space(char** e, int* word_len)
{
    while(*e != 32)
    {
        *word_len++;
        (*e)++;
        e++;
    }
}

char* word(int word_len, char* e)
{
    char* word;
    int index;

    word = calloc(sizeof(char), word_len + 1);
    index = 0;
    while(word_len)
        word[index] = *(e - word_len--);
}

char* reverse(char** list_of_words, word_count)
{
    int iter;
    
    iter = 0;
    while(word_count > 0)
    {
        while(list_of_words[word_count][iter])
        {
            *(--e) = list_of_words[word_count][iter];
            iter++;
        }
        word_count--;
    }
}


size_t word_play(char* e)
{
    int word_count;
    int word_len;
    int index;
    int mem;
    int iter;
    char* word = NULL;
    char** list_of_words = NULL;

    word_count = 0;
    mem = 0;
    while(*e)
    {
        ifspace(e, &word_count, list_of_words, &word_len);
            while_space(&e, word_len);
                list_of_words[word_count] = word(word_len, e);
        ifnot_space(e, &word_count, list_of_words, &word_len);
            while_not_space(&e, word_len);
                list_of_words[word_count] = word(word_len, e);
        e++;
    }
    return (reverse(list_of_words, word_count));
}

#include <stdio.h>
int main(void)
{
    char* e = "A simple text to reverse";
    reverse(e);
    puts(e);
    return (0);
}