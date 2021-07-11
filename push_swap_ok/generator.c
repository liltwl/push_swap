#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

int     contains(int *tab, int key, int i)
{
    int j;

    j = 0;
    while (j <= i)
    {
        if (tab[j] == key)
            return (1);
        j++;
    }
    return (0);
}

void    print_array(int *tab, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf(">>%d ", tab[i]);
        i++;
    }
    printf("\n");
}

int     main(int argc, char **argv)
{
    int     size;
    int     *tab;
    int     add;
    int     i;
    int     n;

    i = 0;
    add = 0;
    size = atoi(argv[1]);
    srand(atoi(argv[2]) * time(NULL));
    tab = malloc(sizeof(int) * size);
    while (add != size)
    {
        n = rand() % 1000 + 1;
        if (!contains(tab, n, i))
        {
            printf ("%d ", n);
            tab[i] = n;
            i++;
            add++;
        }
    }
    printf("\n");
    return (0);
}
