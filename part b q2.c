#include <stdio.h>

int main()
{
    int userType;
    int option;
    int pin, correctPin = 1234;
    int balance = 50000;
    int amount;
    int attempts = 0;
    int authenticated = 0;

    printf("Insert Card...\n");

    printf("Enter user type:\n");
    printf("1. FASTian\n");
    printf("2. Outsider\n");
    scanf("%d", &userType);

    if (userType == 1)
    {
        printf("\nFASTian detected.\n");
        printf("Choose authentication method:\n");
        printf("1. Card + PIN\n");
        printf("2. Card + Biometric\n");
        scanf("%d", &option);

        if (option == 2)
        {
            printf("Place finger on biometric scanner...\n");
            printf("Fingerprint verified successfully!\n");
            authenticated = 1;
        }
        else if (option == 1)
        {
            printf("Enter PIN: ");
            scanf("%d", &pin);

            if (pin == correctPin)
            {
                authenticated = 1;
            }
            else
            {
                attempts++;

                printf("Incorrect PIN.\n");

                printf("Enter PIN (Attempt 2): ");
                scanf("%d", &pin);

                if (pin == correctPin)
                {
                    authenticated = 1;
                }
                else
                {
                    attempts++;

                    printf("Incorrect PIN.\n");

                    printf("Enter PIN (Attempt 3): ");
                    scanf("%d", &pin);

                    if (pin == correctPin)
                    {
                        authenticated = 1;
                    }
                    else
                    {
                        attempts++;
                        printf("Incorrect PIN 3 times.\n");
                        printf("Card captured by ATM.\n");
                    }
                }
            }
        }
    }
    else if (userType == 2)
    {
        printf("\nOutsider detected.\n");
        printf("Outsiders can only use Card + PIN.\n");

        printf("Enter PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin)
        {
            authenticated = 1;
        }
        else
        {
            printf("Incorrect PIN.\n");

            printf("Enter PIN (Attempt 2): ");
            scanf("%d", &pin);

            if (pin == correctPin)
            {
                authenticated = 1;
            }
            else
            {
                printf("Incorrect PIN.\n");

                printf("Enter PIN (Attempt 3): ");
                scanf("%d", &pin);

                if (pin == correctPin)
                {
                    authenticated = 1;
                }
                else
                {
                    printf("Incorrect PIN 3 times.\n");
                    printf("Card captured by ATM.\n");
                }
            }
        }
    }
    else
    {
        printf("Invalid user type.\n");
    }

    /* ATM operations after successful authentication */

    if (authenticated == 1)
    {
        printf("\nAuthentication successful!\n");

        printf("Current balance: Rs. %d\n", balance);

        printf("Enter amount to withdraw: ");
        scanf("%d", &amount);

        if (amount <= balance)
        {
            balance = balance - amount;
            printf("Please collect your cash.\n");
            printf("Remaining balance: Rs. %d\n", balance);
        }
        else
        {
            printf("Insufficient balance.\n");
        }
    }

    return 0;
}