// struct book analyzer(const struct book* ptr)
// {
//     size_t  size;
//     const unsigned char* byte_ptr;

//     byte_ptr = (const unsigned char*) ptr;
//     size = sizeof(*ptr);
//     while(size)
//     {

//     }

// }

struct compact
{
    /*Allocating 4 bits in the variable allows it to index a hexadecimal base*/
    unsigned char hex : 4;
    /*Allocating 4 bits on this variable allows it to produce any octal*/
    unsigned char oct : 3;
    /*Allocating a single bit is enough to create a flag for gate-control*/
    unsigned char flag : 1;
};

int main()
{
    struct compact nums;

    nums.flag = 1;
    nums.hex = 15;
    nums.oct = 7;

    printf("Size of struct 'compact' is:\t%lu\n", sizeof(nums));
    puts("FYI:'operand of sizeof may not be a bit field'\n");
}
