#include <stdio.h>

int main()
{
    int n;
    int i;

    char vehicleType;
    char category;
    char permit;
    char emergency;

    int zoneA = 0;
    int zoneB = 0;
    int zoneC = 0;

    int accepted = 0;
    int rejected = 0;

    int cars = 0;
    int bikes = 0;
    int vans = 0;

    int spacesNeeded;
    int assignedZone;
    int valid;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\n========== Vehicle %d ==========\n", i);

        valid = 0;

        /* Vehicle type validation */
        while (valid == 0)
        {
            printf("Enter vehicle type (C-Car, B-Bike, V-Van): ");
            scanf(" %c", &vehicleType);

            if (vehicleType == 'C' || vehicleType == 'c' ||
                vehicleType == 'B' || vehicleType == 'b' ||
                vehicleType == 'V' || vehicleType == 'v')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid vehicle type. Try again.\n");
            }
        }

        /* Category validation */
        valid = 0;

        while (valid == 0)
        {
            printf("Enter category (F-Faculty, S-Student, V-Visitor): ");
            scanf(" %c", &category);

            if (category == 'F' || category == 'f' ||
                category == 'S' || category == 's' ||
                category == 'V' || category == 'v')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid category. Try again.\n");
            }
        }

        /* Permit validation */
        valid = 0;

        while (valid == 0)
        {
            printf("Enter valid permit? (Y/N): ");
            scanf(" %c", &permit);

            if (permit == 'Y' || permit == 'y' ||
                permit == 'N' || permit == 'n')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid permit value. Try again.\n");
            }
        }

        /* Emergency vehicle */
        valid = 0;

        while (valid == 0)
        {
            printf("Is it an emergency vehicle? (Y/N): ");
            scanf(" %c", &emergency);

            if (emergency == 'Y' || emergency == 'y' ||
                emergency == 'N' || emergency == 'n')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid value. Try again.\n");
            }
        }

        /* Determine spaces required */
        if (vehicleType == 'V' || vehicleType == 'v')
            spacesNeeded = 2;
        else
            spacesNeeded = 1;

        assignedZone = 0;

        /*
           EMERGENCY VEHICLES
           They can enter regardless of permit.
           They are assigned according to category.
        */

        if (emergency == 'Y' || emergency == 'y')
        {
            if (category == 'F' || category == 'f')
            {
                if (zoneA + spacesNeeded <= 20)
                    assignedZone = 1;
            }
            else if (category == 'S' || category == 's')
            {
                if (zoneB + spacesNeeded <= 40)
                    assignedZone = 2;
            }
            else
            {
                if (zoneC + spacesNeeded <= 15)
                    assignedZone = 3;
            }
        }

        /*
           NON-EMERGENCY VEHICLES
           Must have a valid permit.
        */

        else if (permit == 'Y' || permit == 'y')
        {
            /* FACULTY */
            if (category == 'F' || category == 'f')
            {
                if (vehicleType == 'C' || vehicleType == 'c')
                {
                    if (zoneA + 1 <= 20)
                        assignedZone = 1;
                }
                else if (vehicleType == 'B' || vehicleType == 'b')
                {
                    if (zoneA + 1 <= 20)
                        assignedZone = 1;
                }
                else if (vehicleType == 'V' || vehicleType == 'v')
                {
                    if (zoneA + 2 <= 20)
                        assignedZone = 1;
                }
            }

            /* STUDENTS */
            else if (category == 'S' || category == 's')
            {
                if (vehicleType == 'C' || vehicleType == 'c')
                {
                    if (zoneB + 1 <= 40)
                        assignedZone = 2;
                }
                else if (vehicleType == 'B' || vehicleType == 'b')
                {
                    if (zoneB + 1 <= 40)
                        assignedZone = 2;
                }
                else if (vehicleType == 'V' || vehicleType == 'v')
                {
                    /* Student van can be redirected to Zone C */
                    if (zoneC + 2 <= 15)
                        assignedZone = 3;
                }
            }

            /* VISITORS */
            else if (category == 'V' || category == 'v')
            {
                if (vehicleType == 'C' || vehicleType == 'c')
                {
                    if (zoneC + 1 <= 15)
                        assignedZone = 3;
                }
                else if (vehicleType == 'B' || vehicleType == 'b')
                {
                    if (zoneC + 1 <= 15)
                        assignedZone = 3;
                }
                else if (vehicleType == 'V' || vehicleType == 'v')
                {
                    if (zoneC + 2 <= 15)
                        assignedZone = 3;
                }
            }
        }

        /*
           CHECK RESULT
        */

        if (assignedZone == 0)
        {
            rejected++;

            if (permit == 'N' || permit == 'n')
            {
                if (emergency == 'N' || emergency == 'n')
                    printf("Rejected: No valid permit.\n");
                else
                    printf("Rejected: No suitable zone/capacity.\n");
            }
            else
            {
                printf("Rejected: No suitable zone or available space.\n");
            }
        }
        else
        {
            accepted++;

            /* Update occupancy */
            if (assignedZone == 1)
            {
                zoneA = zoneA + spacesNeeded;
                printf("Vehicle assigned to Zone A.\n");
                printf("Remaining capacity: %d\n", 20 - zoneA);
            }
            else if (assignedZone == 2)
            {
                zoneB = zoneB + spacesNeeded;
                printf("Vehicle assigned to Zone B.\n");
                printf("Remaining capacity: %d\n", 40 - zoneB);
            }
            else
            {
                zoneC = zoneC + spacesNeeded;
                printf("Vehicle assigned to Zone C.\n");
                printf("Remaining capacity: %d\n", 15 - zoneC);
            }

            /* Counters */
            if (vehicleType == 'C' || vehicleType == 'c')
                cars++;
            else if (vehicleType == 'B' || vehicleType == 'b')
                bikes++;
            else
                vans++;
        }
    }

    /* FINAL SUMMARY */

    printf("\n\n========== PARKING SUMMARY ==========\n");

    printf("Total vehicles processed : %d\n", n);
    printf("Total accepted           : %d\n", accepted);
    printf("Total rejected           : %d\n", rejected);

    printf("Cars successfully parked : %d\n", cars);
    printf("Bikes successfully parked: %d\n", bikes);
    printf("Vans successfully parked : %d\n", vans);

    printf("\nZone A occupancy: %d / 20\n", zoneA);
    printf("Zone A remaining: %d\n", 20 - zoneA);

    printf("\nZone B occupancy: %d / 40\n", zoneB);
    printf("Zone B remaining: %d\n", 40 - zoneB);

    printf("\nZone C occupancy: %d / 15\n", zoneC);
    printf("Zone C remaining: %d\n", 15 - zoneC);

    /* Highest occupancy */
    if (zoneA >= zoneB && zoneA >= zoneC)
        printf("\nZone with highest occupancy: Zone A\n");
    else if (zoneB >= zoneA && zoneB >= zoneC)
        printf("\nZone with highest occupancy: Zone B\n");
    else
        printf("\nZone with highest occupancy: Zone C\n");

    /* Entire facility full */
    if (zoneA == 20 && zoneB == 40 && zoneC == 15)
        printf("Entire campus parking facility is FULL.\n");
    else
        printf("Entire campus parking facility is NOT full.\n");

    return 0;
}