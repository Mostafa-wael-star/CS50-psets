#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int Height;
    do
    {
        Height = get_int("Enter the height of the pyramid : ");
    } while (Height < 1 || Height > 8);

    for (int i = 0; i < Height; i++)
    {
        for (int s = Height - 1 - i; s > 0; s--)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}