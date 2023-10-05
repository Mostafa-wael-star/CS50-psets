#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string substitute_text(string plainText);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 character");
        return 1;
    }

    string plainText = get_string("Enter Plain Text : ");

    string cipherText = substitute_text(plainText);
}

string substitute_text(string plainText)
{
}
