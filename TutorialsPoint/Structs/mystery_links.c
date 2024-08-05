#include <stdlib.h>
#include <stdio.h>

typedef struct mystery
{
    char* clue_text;
    struct mystery* next;
} clue;

int main()
{
    clue dead_body;
    clue knife_cut;
    clue bloodied_knife;
    clue fingerprints;
    clue butler;

    dead_body.clue_text = "You found a dead body. Wondering how they died?";
    dead_body.next = &knife_cut;

    knife_cut.clue_text = "A deep knife cut at back has probably something to do with it. We need to look for the murder weapon!";
    knife_cut.next = &bloodied_knife;

    bloodied_knife.clue_text = "You found a bloodied knife! The boffins at the lab can check for fingerprints!";
    bloodied_knife.next = &fingerprints;

    fingerprints.clue_text = "You ID the fingerprints on the knife to some bloke called Guilty McKiller.";
    fingerprints.next = &butler;

    butler.clue_text = "It's the butler!";
    butler.next = NULL;

    clue* iter;
    iter = &dead_body;
    while(iter->next)
    {
        puts(iter->clue_text);
        iter = iter->next;
    }
    puts(iter->clue_text);
}