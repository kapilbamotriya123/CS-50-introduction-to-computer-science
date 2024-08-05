//in this section we will how to make function in c without including every bit of detail I can search online wherever I will need that
#include <cs50.h>
#include <stdio.h>

void meow(void);
void kapil(int n);

int main(void)
{
    kapil(5);
}

void meow(void) //here the first void means there is no return value in the fucntion, and second void means there is no input required for the function to run
{
    for(int i = 0; i<3; i++)
    {
        printf("meow\n");
    }
}

//now instead of writing how many times to repeat we can give function a input value

void kapil(int n)
{
    for (int i=0; i < n; i++ )
    {
        printf("this is Kapil function operating\n");
    }
}
