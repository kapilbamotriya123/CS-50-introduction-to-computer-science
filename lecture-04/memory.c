#include <stdio.h>

void swap(int *a,int *b);

int main(void)
{
    int x;
    int y;

    x = 3;
    y = 4;

    printf("x is %i and y is %i\n", x , y );
    swap(&x , &y);
    printf("x is %i and y is %i\n", x , y );
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
