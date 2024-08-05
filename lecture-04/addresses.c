#include <stdio.h>

int main(void)
{
    int n =50;
    //this p is an another variable which store the addresses of n and this * is just syntax to store addresses
    //& gives me the addresses of asked vairables address
    int *p= &n;
    printf("%p\n", p);

    printf("%i\n", *p);
}
