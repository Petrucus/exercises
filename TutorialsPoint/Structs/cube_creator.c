#include <stdio.h>
#include <stdlib.h>

typedef struct dimensions
{
    float height;
    float width;
    float length;
} dimensions;

typedef float volume;

dimensions *cube_creator(volume x)
{
    printf("\nCreating a cube of total volume:\t%.4f\n", x);

    float j;
    float sum;

    j = 0;
    /*Until I understand a more advanced algo...*/
    while (sum < x)
    {
        j += 0.000001;
        sum = j * j * j;
    }
    if (sum == x || sum < x + 0.001)
    {
        struct dimensions *cube_ptr;
        cube_ptr = malloc(sizeof(struct dimensions));
        cube_ptr->height = j;
        cube_ptr->length = j;
        cube_ptr->width = j;
        printf("\nFinal cube is of total volume:\t%f\n", sum);
        return (cube_ptr);
    }
    return (NULL);
}

void set_cube(dimensions *cube, volume x)
{
    cube->height = x;
    cube->length = x;
    cube->width = x;
}

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1] != NULL)
    {
        puts("\nLet's create a cube !");
        struct dimensions my_cube;
        struct dimensions *my_cube_ptr = NULL;
        volume cube_volume = atof(argv[1]);

        my_cube_ptr = cube_creator(cube_volume);
        if (my_cube_ptr != NULL)
        {
            puts("My cube has:");
            printf("height of\t%f\n", my_cube_ptr->height);
            printf("width of:\t%f\n", my_cube_ptr->width);
            printf("length of:\t%f\n", my_cube_ptr->length);
            printf("located\t@%p\n", my_cube_ptr);
        }
        else
            puts("Cube calculations failed");

        my_cube = *my_cube_ptr;
        free(my_cube_ptr);
        printf("\nCube is %f x %f x %f located @%p\n",
               my_cube.height,
               my_cube.length,
               my_cube.width,
               &my_cube);
        set_cube(&my_cube, 10.5);
        printf("Now the cube is %f x %f x %f\n",
               my_cube.height,
               my_cube.length,
               my_cube.width);
    }
    else
    {
        puts("Cube volume needed");
        return (1);
    }
    return (0);
}