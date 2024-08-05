#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[]= {1,10,15,534,4363,234,123};
    int n = get_int("whats the number: ");

    for(int i=0; i<7; i++)
    {
        if (numbers[i]==n)
        {
            printf("Found!\n");
            //here we need to return a value to function so that it do not proceed with the rest of the code
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;

}
