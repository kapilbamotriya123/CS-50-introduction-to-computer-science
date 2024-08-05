#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int words(string s);

int main(void)
{
    string text =get_string("text: ");
    //words count
    int wc = words(text);
    //printf("word count %i\n",wc);
    //letter count iterate through every word and add only alphabatic text
    int lc =0;
    for (int i=0,len = strlen(text); i<len; i++)
    {
        if (isalpha(text[i]))
        {
            lc++;
        }
    }

    //printf("letters count %i\n",lc);
    //for sentence count I will use , . ! this indicator
    int sc = 0;
    for (int i=0; i< (strlen(text)) ;i++)
    {
        if (text[i]== '?'|| text[i]=='!'|| text[i]=='.')
        sc += 1;
    }
    if (sc==0) sc=1;

    

    //L and S
    float L =((float) lc/(float)wc)*100.00;

    //printf("L %f\n",L);
    float S =((float)sc/(float)wc)*100.00;

    //printf("S %f\n",S);
    float index = 0.0588*L - 0.296*S - 15.8;

    //printf("index %i\n",(int) round(index));
    if (index < 1) printf("Before Grade 1\n");

    else if (index >= 1 && index <= 16) printf("Grade %i\n",(int) round(index));

    else printf("Grade 16+\n");
}


int words(string s)
{
    int words_count = 0;
    for (int i=0,x = strlen(s); i<x; i++)
    {
        if (s[i]==' ')
        {
            words_count += 1;
        }
    }
    //total number of letters
    return words_count +1;
}
