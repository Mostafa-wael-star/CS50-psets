#include <stdio.h>
#include "cs50.h"

int calculate_25s(int amount);
int calculate_10s(int amount);
int calculate_5s(int amount);
int calculate_1s(int amount);
int get_cents(void);

int main(int argc, char const *argv[])
{
    int cents = get_cents();
    int coins = 0;

    if (cents >= 25)
    {
        coins += calculate_25s(cents);
        cents -= calculate_25s(cents) * 25;
    }
    if (cents >= 10 && cents < 25)
    {
        coins += calculate_10s(cents);
        cents -= calculate_10s(cents) * 10;
    }
    if (cents >= 5 && cents < 10)
    {
        coins += calculate_5s(cents);
        cents -= calculate_5s(cents) * 5;
    }
    if (cents >= 0 && cents < 5)
    {
        coins += calculate_1s(cents);
        cents = 0;
    }
    printf("%i\n", coins);
    return 0;
}

int get_cents(void)
{
    int money;
    do
    {
        money = get_int("please enter the amount of money : ");
    } while (money < 0);
    return money;
}

int calculate_25s(int amount)
{
    return amount / 25;
}
int calculate_10s(int amount)
{
    return amount / 10;
}
int calculate_5s(int amount)
{
    return amount / 5;
}
int calculate_1s(int amount)
{
    return amount;
}