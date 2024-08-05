//this is introduction to data type and have syntax for the same 
#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];
    people[0].name = "Kapil";
    people[0].number = "+91-83053-87299";

    people[1].name = "Shubham";
    people[1].number = "+91-83053-79874";

    people[2].name = "Tanker";
    people[2].number = "+91-83053-53456";


    string name = get_string("What the name: ");
    for (int i=0; i<3; i++)
    {
        if (strcmp(name,people[i].name)==0)
        {
            printf("Found, %s\n",people[i].number);
            return 0;
        }
    }
    printf("Not Found!\n");
    return 1;
}
