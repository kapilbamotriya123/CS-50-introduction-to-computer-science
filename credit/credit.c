#include <stdio.h>
#include <cs50.h>

//to get the units place we have to get reminder of 10
long card_number(void);
int count(long card_num);
int checksum(long card_num);
int mastercard(long card_num);
int visa(long card_num);
int American(long card_num);

int main(void)
{
    long CN = card_number();
    if (checksum(CN)==1)
    {
        long cou = count(CN);
        if (visa(CN)==1) printf("VISA\n");
        else
        {
            if (CN ==15)
            {
                if (mastercard(CN)==1) printf("MASTERCARD\n");
            }
            else if (CN ==16)
            {
                if (American(CN)==1) printf("AMEX\n");
            }
            else printf("INVALID\n");
        }
    }
    else printf("INVALID\n");

}

long card_number(void)
{
    long card_num = get_long("what is card number: ");
    return card_num;
}

int count(long card_num)
{
    if (card_num == 0)
    return 1;

    int count = 0;
    while (card_num != 0)
    {
        card_num = card_num/10;
        count++;
    }
    return count;
}

int checksum(long card_numb)
{
    long card_num = card_numb;
    int n;
    int c =count(card_num);

    if (c%2 == 1)
    n = (c+1)/2;
    else
    n= c/2;

    //doing for second digit sum

    int sd=0;
    for(int i=0; i<n; i++)
    {
        //every single digit can count up two digit so for that we have to sum every digit for moment call every digit as x
        int x;
        card_num /= 10;
        x = 2*(card_num%10);
        if (count(x)==2)
        {
            sd = sd + x%10;
            x = x/10;
            sd = sd + x;
        }
        else sd = sd + x;
        card_num /= 10;
    }

    //doing for first digit sum
    int fd=0;
    for(int i=0; i<n; i++)
    {
        fd = fd + card_numb%10;
        card_numb /= 100;
    }


    if ((fd + sd)%10==0) return 1;
    else return 2;

}

int mastercard(long card_num)
{
    if (card_num/100000000000000==51 ||card_num/100000000000000==52 ||card_num/100000000000000==53 ||card_num/100000000000000==54 ||card_num/100000000000000==55 ) return 1;
    else return 2;
}

int visa(long card_num)
{
    long cou = count(card_num);
    if (cou ==13)
    {
        if (card_num/1000000000000==4) return 1;
    }
    else if (cou == 16)
    {
        if (card_num/1000000000000000==4)return 1;
    }
    else return 2;
}

int American(long card_num)
{
    if (card_num/10000000000000==34 || card_num/10000000000000==37) return 1;
    else return 2;
}
