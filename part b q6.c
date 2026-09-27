#include <stdio.h>

int main()
{
    char vehicleType;
    char membership;
    char disabled;
    char station;

    int battery;
    int requiredLevel;
    int duration;
    int time;

    int chargingUnits;
    float chargingCost = 0;
    float parkingCost = 0;
    float discount = 0;
    float finalAmount;

    int eligible = 1;

    char priority[50];
    char period[20];

    /* INPUT */

    printf("Enter vehicle type (E-Electric, H-Hybrid): ");
    scanf(" %c", &vehicleType);

    printf("Enter current battery level (%%): ");
    scanf("%d", &battery);

    printf("Enter required charging level (%%): ");
    scanf("%d", &requiredLevel);

    printf("Enter expected parking duration (hours): ");
    scanf("%d", &duration);

    printf("Enter current time (24-hour format): ");
    scanf("%d", &time);

    printf("Parking membership? (Y/N): ");
    scanf(" %c", &membership);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Is charging station available? (Y/N): ");
    scanf(" %c", &station);

    /* VALIDATION */

    if (vehicleType != 'E' && vehicleType != 'e' &&
        vehicleType != 'H' && vehicleType != 'h')
    {
        printf("Invalid vehicle type.\n");
        return 0;
    }

    if (battery < 0 || battery > 100)
    {
        printf("Invalid battery percentage.\n");
        return 0;
    }

    if (requiredLevel < 0 || requiredLevel > 100)
    {
        printf("Invalid required charging level.\n");
        return 0;
    }

    if (duration < 0)
    {
        printf("Invalid parking duration.\n");
        return 0;
    }

    if (time < 0 || time > 23)
    {
        printf("Invalid time.\n");
        return 0;
    }

    /* CHARGING STATION CHECK */

    if (station == 'N' || station == 'n')
    {
        if (vehicleType == 'H' || vehicleType == 'h')
        {
            printf("\nCharging unavailable - Parking only.\n");
        }
        else
        {
            printf("\nNo charging slot available.\n");
        }

        eligible = 0;
    }

    /* VEHICLE CHARGING ELIGIBILITY */

    if (eligible == 1)
    {
        if (vehicleType == 'H' || vehicleType == 'h')
        {
            if (battery >= 40)
            {
                printf("\nVehicle does not qualify for EV charging.\n");
                eligible = 0;
            }
        }
    }

    /* REQUIRED CHARGING */

    if (eligible == 1)
    {
        chargingUnits = requiredLevel - battery;

        if (chargingUnits <= 0)
        {
            printf("\nNo charging required.\n");
            eligible = 0;
        }
    }

    /* CHARGING PRIORITY */

    if (eligible == 1)
    {
        if (battery <= 15 && requiredLevel >= 80)
        {
            printf("\nPriority: Emergency Charging Priority\n");
            sprintf(priority, "Emergency Charging");
        }
        else if (disabled == 'Y' || disabled == 'y' ||
                 (membership == 'Y' || membership == 'y') && battery <= 30)
        {
            printf("\nPriority: Priority Charging\n");
            sprintf(priority, "Priority Charging");
        }
        else
        {
            printf("\nPriority: Normal Charging\n");
            sprintf(priority, "Normal Charging");
        }
    }
    else
    {
        sprintf(priority, "No Charging");
    }

    /* PEAK / OFF-PEAK */

    if (time < 17 || time >= 22)
    {
        sprintf(period, "Off-Peak");

        if (eligible == 1)
        {
            chargingCost = chargingUnits * 35;

            /* Membership gets 20% off during off-peak */
            if ((membership == 'Y' || membership == 'y') &&
                !(battery <= 15 && requiredLevel >= 80))
            {
                discount = chargingCost * 0.20;
            }
        }
    }
    else
    {
        sprintf(period, "Peak");

        if (eligible == 1)
        {
            chargingCost = chargingUnits * 50;

            /* 10% discount during peak hours */
            discount = chargingCost * 0.10;
        }
    }

    /* PARKING CHARGE */

    if (duration <= 2)
    {
        parkingCost = 200;
    }
    else if (duration <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    /* MEMBER PARKING DISCOUNT */

    if (disabled == 'Y' || disabled == 'y')
    {
        /* Disabled customers get free parking */
        parkingCost = 0;
    }
    else if (membership == 'Y' || membership == 'y')
    {
        /* Members receive 20% parking discount */
        parkingCost = parkingCost - (parkingCost * 0.20);
    }

    /* FINAL AMOUNT */

    finalAmount = chargingCost + parkingCost - discount;

    /* LONG-STAY WARNING */

    if (duration > 8)
    {
        printf("Warning: Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("Standard parking duration.\n");
    }

    /* FINAL OUTPUT */

    printf("\n====================================\n");
    printf("       SMART EV PARKING BILL\n");
    printf("====================================\n");

    printf("Vehicle type: %c\n", vehicleType);
    printf("Current battery: %d%%\n", battery);
    printf("Required battery: %d%%\n", requiredLevel);

    if (eligible == 1)
        printf("Charging units: %d%%\n", chargingUnits);
    else
        printf("Charging units: 0%%\n");

    printf("Charging priority: %s\n", priority);
    printf("Peak/Off-Peak: %s\n", period);

    printf("Charging cost: Rs. %.2f\n", chargingCost);
    printf("Parking cost: Rs. %.2f\n", parkingCost);
    printf("Discount: Rs. %.2f\n", discount);

    printf("Final payable amount: Rs. %.2f\n", finalAmount);

    printf("====================================\n");

    return 0;
}