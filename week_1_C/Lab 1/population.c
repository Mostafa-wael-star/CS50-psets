#include "cs50.h"
#include <stdio.h>
int years(int, int);
int main(void)
{
    // TODO: Prompt for start size
    int starting_size;
    do
    {
        starting_size = get_int("please enter a starting size for the population : ");
    } while (starting_size < 9);
    // TODO: Prompt for end size
    int ending_size;
    do
    {
        ending_size = get_int("please enter an ending size for the population : ");
    } while (ending_size < starting_size);
    // TODO: Calculate number of years until we reach threshold
    int answer = years(starting_size, ending_size);
    // TODO: Print number of years
    printf("Years: %i\n", answer);
}

int years(int start, int end)
{
    int years = 0;
    int borns;
    int deaths;
    do
    {
        if (start >= end)
            return years;
        borns = start / 3;
        deaths = start / 4;
        start = start + borns - deaths;
        years++;
    } while (start <= end);
    return years;
}