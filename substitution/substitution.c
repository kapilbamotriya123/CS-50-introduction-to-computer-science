#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc , string argv[])
{
    if (argc != 2)
    {
         printf("Usage: ./substitution key\n");
         return 1;

    }
    string key =argv[1];
    //check for the key, if key is valid or invalid
    if (strlen(key)==26)
    {
        for (int i = 0; i<26; i++)
        {
            if (isalpha(key[i]))
            {
                for (int j=i+1; j<26; j++)
                {
                    if (key[i]==key[j])
                    {
                        printf("key contains repeated character\n");
                        //returning 1 for repeated type error
                        return 1;
                    }
                }
            }
            else
            {
                printf("Key contains non alphabatic characters\n");
                //return 1 for non alphabatic character
                return 1;
            }
        }
    }
    else
    {
        printf("key does not contain 26 words\n");
        //return 1 for short key
        return 1;
    }

    //introducing the cipher text array
    string word = get_string("plaintext: ");
    string cipher = word;

    for (int i=0, len = strlen(word); i<len; i++)
    {
        if (isupper(word[i]))
        {
            cipher[i] = toupper(key[word[i] - 'A']);
        }
        else if (islower(word[i]))
        {
            cipher[i] = tolower(key[word[i] -'a']);
        }
        else cipher[i] = word[i];
    }
    printf("ciphertext: %s\n", cipher);
    printf("ciphertext: %s\n", word);
    return 0;
}
