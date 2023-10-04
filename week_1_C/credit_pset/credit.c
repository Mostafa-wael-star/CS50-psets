#include <stdio.h>
#include "cs50.h"

long long Get_Card();
int get_card_length(long long card);
int sum_of_odd_index(long long card);
int sum_of_even_index(long long card);
int first_two_digits(long long card, int length);
string card_name(int length, int first_two_digits);

int main(int argc, char const *argv[])
{
    long long card = Get_Card();
    int card_length = get_card_length(card);
    int sum1 = sum_of_odd_index(card);
    int sum2 = sum_of_even_index(card);
    int first_two = first_two_digits(card, card_length);
    string card_validation = card_name(card_length, first_two);

    if ((sum1 + sum2) % 10 == 0)
    {
        printf("%s\n", card_validation);
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}

long long Get_Card()
{
    long long get_card = get_long_long("please enter your card : ");
    return get_card;
}

int get_card_length(long long card)
{
    int i = 0;
    while (card)
    {
        card /= 10;
        i++;
    }
    return i;
}

int sum_of_odd_index(long long card)
{
    int sum = 0;
    while (card != 0)
    {
        sum += card % 10;
        card /= 100;
    }
    return sum;
}
int sum_of_even_index(long long card)
{
    int sum = 0, doubled = 0;
    card /= 10;
    while (card != 0)
    {
        doubled = (card % 10) * 2;

        if (doubled < 10)
        {
            sum += doubled;
        }
        else
        {
            sum += 1 + (doubled % 10);
        }
        card /= 100;
    }
    return sum;
}
int first_two_digits(long long card, int length)
{
    for (int i = 0; i < length - 2; i++)
    {
        card /= 10;
    }
    return (int)card;
}

string card_name(int length, int first_two_digits)
{
    if ((length == 13 || length == 16) && first_two_digits / 10 == 4)
    {
        return "VISA\n";
    }
    else if (length == 16 && first_two_digits <= 55 && first_two_digits >= 51)
    {
        return "MASTER\n";
    }
    else if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX\n";
    }

    return "INVALID\n";
}