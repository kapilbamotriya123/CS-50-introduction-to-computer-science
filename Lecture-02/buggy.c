#include <stdio.h>

int main(void)
{
    for (int i=0; i<=3; i++)
    {
        printf("i is,%i\n",i);
        //this print is helping me identify why it is printing an extra #
        printf("#\n");
    }
}
