#include <stdio.h>
#include <cs50.h>


void hasher(int a);


void hasher_line(int b)
{
    hasher(b);
    printf("  ");
    hasher(b);
    printf("\n");
}

void hasher(int a)
{

    for (int i=0; i<a; i++)
    {
        printf("#");
    }
}

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n>8 || n<1);
    for (int i=1; i <= n ; i++)
    {
        int z =n-i;
        while (z>0)
        {
            printf(" ");
            z--;
        }

        hasher_line(i);

    }
}
