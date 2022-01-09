#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter a maximum of 2 command-line arguments\n");
        return 1;
    }



    //CHECK IF EACH CHARACTER IS A DECIMAL DIGIT
    int len = strlen(argv[1]);
    char valid[len];

    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]))
        {
            valid[i] = argv[1][i];
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    int key = atoi(valid);                              // Convert key to an integer



    // ENCIPHER PLAINTEXT
    string plain = get_string("plaintext: ");           // Get plaintext from user

    int n = strlen(plain);
    char c[n];


    for (int i = 0; i < n; i++)                         // Iterate over plaintext and convert each character to ciphertext
    {

        if (isalpha(plain[i]) && islower(plain[i]))
        {
            c[i] = ((plain[i] - 'a' + key) % 26) + 'a';
        }

        else if (isalpha(plain[i]) && isupper(plain[i]))
        {
            c[i] = ((plain[i] - 'A' + key) % 26) + 'A';
        }

        else
        {
            c[i] = plain[i];
        }
    }

    printf("ciphertext: ");
    for  (int i = 0; i < n; i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
    return 0;
}
