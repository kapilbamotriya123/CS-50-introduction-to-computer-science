#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    //i order to run a loop forever type while(true) which is always true and it will run indefinitely
    {
        printf("meow\n");
        i = i + 1;
    }



    for (i=0 ; i < 3; i++)
    //see there are three things here, i=0 opening condition, then it will check for second one if thats true it will run the code inside and then it will look for third condition and then come back to second and so on
    {
        printf("demo for for loop\n");
    }
}
