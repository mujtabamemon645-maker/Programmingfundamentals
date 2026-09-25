#include <stdio.h>

int main()
{
    int accountNumber;
    char customerType;
    int basicConnections;
    int premiumChannels;

    float bill = 0;

    printf("Enter account number (an integer): ");
    scanf("%d", &accountNumber);

    printf("Enter customer type: R or r (Residential), B or b (Business): ");
    scanf(" %c", &customerType);

    printf("Enter the number of basic service connections: ");
    scanf("%d", &basicConnections);

    printf("Enter the number of premium channels: ");
    scanf("%d", &premiumChannels);

    if (customerType == 'R' || customerType == 'r')
    {
        bill = 4.50 + 20.50 + (premiumChannels * 7.50);
    }
    else if (customerType == 'B' || customerType == 'b')
    {
        bill = 15.00;

        if (basicConnections <= 10)
        {
            bill = bill + 75.00;
        }
        else
        {
            bill = bill + 75.00 + ((basicConnections - 10) * 5.00);
        }

        bill = bill + (premiumChannels * 50.00);
    }
    else
    {
        printf("Invalid customer type.\n");
        return 0;
    }

    printf("\nAccount number: %d\n", accountNumber);
    printf("Amount due: $%.2f\n", bill);

    return 0;
}