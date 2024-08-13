#include <stdlib.h>

int len(char* e)
{
    int len;

    len = 0;
    while(e[len])
        len++;
    return (len);
}

char* word(int word_len, char* e)
{
    char* word = NULL;
    int index;

    index = 0;
    word = calloc(sizeof(char), word_len + 1);
    while(word_len)
        word[index++] = *(e - word_len--);
    word[index] = '\0';
    return (word);
}

char* reverse(char** list_of_words, int word_count, char* e)
{
    int index;
    int words;
    int word_len;

    words = 0;
    while(words < word_count)
    {
        index = 0;
        word_len = len(list_of_words[words]) - 1;
        while(list_of_words[words][index])
            *(--e) = list_of_words[words][word_len - index++];
        words++;
    }
    return (e);
}

int diff(char* e)
{
    return ((*e > 32 && *(e - 1) == 32) || (*e == 32 && *(e - 1) != 32));
}

void word_play(char* e)
{
    if(e[0] == '\0')
        return ;

    int word_count;
    int word_len;
    size_t mem_size;
    char** list_of_words = NULL;

    mem_size = 0;
    word_count = 0;
    while(*e)
    {
        word_len = 0;
        while(*e)
        {
            word_len++;
            e++;
            if (diff(e))
                break ;
        }
        mem_size += sizeof(char*) * word_len + 1;
        list_of_words = realloc(list_of_words,  mem_size);
        list_of_words[word_count] = word(word_len, e);
        word_count++;
    }
    reverse(list_of_words, word_count, e);
}

#include <stdio.h>
int main(void)
{
    char e[] = "A simple text to reverse";
    word_play(e);
    puts(e);
    return (0);
}