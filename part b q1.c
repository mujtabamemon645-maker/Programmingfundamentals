#include <stdio.h>

int main()
{
    char season, room;
    int nights;
    float rate, total, discount;

    printf("Enter season (P for Peak, O for Off-Peak): ");
    scanf(" %c", &season);

    printf("Enter room type (S for Standard, D for Deluxe, U for Suite): ");
    scanf(" %c", &room);

    printf("Enter number of nights: ");
    scanf("%d", &nights);

    if (season == 'P')
    {
        if (room == 'S')
            rate = 5000;
        else if (room == 'D')
            rate = 8000;
        else
            rate = 12000;
    }
    else
    {
        if (room == 'S')
            rate = 3000;
        else if (room == 'D')
            rate = 5000;
        else
            rate = 8000;
    }

    total = rate * nights;

    if (nights > 7)
    {
        discount = total * 0.15;
        total = total - discount;
    }

    printf("Final Price = Rs. %.2f", total);

    return 0;
}