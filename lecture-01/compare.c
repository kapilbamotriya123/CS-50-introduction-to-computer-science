//this is about get_int in the CS50.h list which is also available on the website 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("what's X? ");
    int y = get_int("what's Y? ");
    if (x<y)
    {
        printf("X is less then Y\n");
    }
    else if (x > y)
    {
        printf("X is greater than Y\n");
    }
    else
    {
        printf("X is equal to Y\n");
    }
}
