
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score(char c);
int SCORE(string s);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int s1 = SCORE(word1);
    int s2 = SCORE(word2);
    if (s1>s2) printf("Player 1 wins!\n");
    else if (s1<s2) printf("Player 2 wins!\n");
    else printf("Tie!\n");
}

int score(char c)
{
    char C = toupper(c);
    if (C == 'A' || C == 'E' ||C ==  'I'||C == 'L'||C == 'O'||C == 'R'||C == 'S'||C == 'T'||C == 'U'||C == 'N') return 1;
    else if (C == 'B' || C == 'C' ||C ==  'M'||C == 'P') return 3;
    else if (C == 'D' || C == 'G') return 2;
    else if (C == 'F' || C == 'H' ||C ==  'V'||C == 'W'||C == 'Y') return 4;
    else if (C ==  'X'||C == 'J') return 8;
    else if (C == 'K') return 5;
    else if (C ==  'Z'||C == 'Q') return 10;
    else return 0;
}


int point[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int SCORE(string s)
{

    int sum = 0;
    for (int i=0,x=strlen(s); i<x; i++)
    {
        if isupper(s[i])
            sum += point[s[i]-'A'];
        else if islower(s[i])
            sum += point[s[i]-'a'];
    }
    return sum;
}
