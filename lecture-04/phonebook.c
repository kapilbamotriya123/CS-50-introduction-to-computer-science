#include <stdio.h>
#include <cs50.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("name: ");
    char *number = get_string("number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);

}
