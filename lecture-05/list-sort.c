#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    for(int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        n -> number = number;
        n -> next = NULL;

        //if there is no element in list
        if(list == NULL)
        {
            list = n;

        }

        //if number is the shortest number
        else if (n -> number < list -> number)
        {
            n -> next = list;
            list = n;
        }

        //if number is to be inserted somewhere in the middle of the list or at the end of the list
        else
        {
            for(node *ptr = list; ptr != NULL; ptr = ptr -> next)
            {
                if(ptr -> next == NULL)
                {
                    ptr -> next = n;
                    break;
                }

                if(n -> number < ptr -> next -> number)
                {
                    n -> next = ptr -> next;
                    ptr -> next = n;
                    break;
                }
            }
        }
    }
    for(node *ptr = list; ptr != NULL; ptr = ptr -> next)
    {
        printf("%i\n", ptr -> number);
    }

}
