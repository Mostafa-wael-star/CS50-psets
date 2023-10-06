#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string substitute_text(string plainText, string key);
bool check_valid_args(int argc, string argv);
bool check_for_duplicates(string argv);
bool check_for_specials(string argv);

int main(int argc, string argv[])
{
    // converting the the key to upper case for vaildation and substitution

    string key = argv[1];
    if (key != NULL)
    {
        for (int i = 0; i < strlen(key); i++)
            key[i] = toupper(key[i]);
    }

    if (check_valid_args(argc, key) == false)
        return 1;

    string plainText = get_string("plaintext:");

    string cipherText = substitute_text(plainText, key);
    printf("ciphertext:%s", cipherText);
}

string substitute_text(string plainText, string key)
{
}

bool check_valid_args(int argc, string argv)
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    if (strlen(argv) != 26)
    {
        printf("Key must contain 26 character\n");
        return false;
    }

    if (check_for_specials(argv) == true || check_for_duplicates(argv) == true)
    {
        return false;
    }

    return true;
}

bool check_for_duplicates(string argv)

{

    for (int i = 0; i < strlen(argv); i++)
    {
        for (int j = i + 1; j < strlen(argv); j++)
        {
            if (argv[i] == argv[j])
            {
                printf("Key must contain 26 distinguish character\n");
                return true;
            }
        }
    }
    return false;
}

bool check_for_specials(string argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        if (isalpha(argv[i]) == false)
        {
            printf("Enter alphabets only\n");
            return true;
        }
    }
    return false;
}