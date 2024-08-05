#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");
    int z = add(x,y);
    printf("%i\n",z);
}

int add(int a, int b)
{
    return a + b;
}
