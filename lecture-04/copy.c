#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        t[i] = s[i];
    }
    t[strlen(s)] = '\0';

    t[0] = toupper(t[0]);
    printf("%p\n", t);
    printf("%p\n", s);
}
