#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int str_length(string s);
void turn_to_bin(char c);

int main(void)
{
    string s = get_string("please enter the message : ");
    int length = str_length(s);
}

int str_length(string s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
        length++;
    return length;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void turn_to_bin(char c)
{
    char bits[8];
    int d = c;
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        if (d % 2 == 0)
            bits[i] = '0';
        else
            bits[i] = '1';
        d /= 2;
    }
    for (int i = BITS_IN_BYTE - 1; i >= 0; i--)
    {
        printf("%c", bits[i]);
    }
}
