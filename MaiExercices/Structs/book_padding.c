#include <stdbool.h>
#include <stdlib.h>

struct book
{
    int pages;
    bool fiction;
    float price;
    const char *name;
};

char *btoa(bool e)
{
    if (e)
        return "true";
    return "false";
}

char *most_expensive(struct book *array)
{
    int max_price;
    char *most_expensive_book_name = NULL;
    struct book *ptr = NULL;

    max_price = 0;
    ptr = array;
    while (ptr->name != NULL)
    {
        if (ptr->price > max_price)
        {
            max_price = ptr->price;
            most_expensive_book_name = (char *)ptr->name;
        }
        ptr++;
    }

    return (most_expensive_book_name);
}

int main(void)
{
    struct book entry;

    entry.pages = 300;
    entry.fiction = true;
    entry.price = 3.57;
    entry.name = "The seagull";

    puts("Book 'entry'");
    printf("%d\n", entry.pages);
    puts(btoa(entry.fiction));
    printf("%.1f\n", entry.price);
    puts(entry.name);

    struct book copycat;
    copycat = entry;

    puts("\nBook 'copycat'");
    printf("%d\n", copycat.pages);
    puts(btoa(copycat.fiction));
    printf("%.1f\n", copycat.price);
    puts(copycat.name);

    puts("\n\nLet's see if I chance the pages in entry copycat will be affected:");

    entry.price = 50.40;
    printf("Price in entry:%f\nPrice in copycat:%f\n", entry.price, copycat.price);
    puts("Let's see their memory locations");
    printf("\nentry price: %p\ncopycat price: %p\n", &entry.price, &copycat.price);

    puts("\n]nSo 'copycat = entry' has some magic sauce that creates a new copy of all these values ?\n");
    puts("Let's see if this is true by getting the struct values as well:\n");
    printf("Memloc of entry is:\t%p\nMemloc of copycat is:\t%p\n", &entry, &copycat);

    puts("\nWe notice that the differences between memory locations is 32.");
    puts("That is because we have 4 components in our struct");
    puts("The largest, 'float price' having a size of 8 bytes");
    puts("So any struct with these components would have a size of multiples of 8");
    printf("\nActual size is:\n%lu for int\n+ %lu for char*\n+ %lu for float\n+ %lu for boolean\n",
           sizeof(int), sizeof(char *), sizeof(float), sizeof(bool));
    printf("The rest %lu is padding. Google it!\n", 32 - (sizeof(int) + sizeof(char *) + sizeof(float) + sizeof(bool)));

    puts("\nWhich begs the question if an other struct equal to 'entry' will be at an equal 'distance");
    struct book new_entry;
    printf("Memory location at declaration is:\t%p\n", &new_entry);
    new_entry = entry;
    printf("Now memory location at assignment is:\t%p\n", &new_entry);

    struct book end;

    end.fiction = false;
    end.name = NULL;
    end.pages = 0;
    end.price = 0.0;

    struct book array[4];

    array[0] = entry;
    array[1] = copycat;
    array[2] = new_entry;
    array[3] = end;

    char *most_expensive_book = most_expensive(array);
    puts(most_expensive_book);
}