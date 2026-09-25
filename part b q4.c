#include <stdio.h>

/* Function to calculate subtotal */
float calculateSubtotal(int q, float p)
{
    return q * p;
}

/* Function to calculate discounted amount */
float calculateDiscount(float s, float d)
{
    return s - (s * d / 100);
}

/* Function to calculate final bill */
float calculateFinalBill(float a, float t)
{
    return a + (a * t / 100);
}

int main()
{
    int q;
    float p, d, t;
    float subtotal, discountedAmount, finalBill;

    printf("Enter quantity of products: ");
    scanf("%d", &q);

    printf("Enter price per item: ");
    scanf("%f", &p);

    printf("Enter discount percentage: ");
    scanf("%f", &d);

    printf("Enter tax percentage: ");
    scanf("%f", &t);

    /* Validation */
    if (q <= 0)
    {
        printf("Invalid quantity!\n");
        return 0;
    }

    if (p <= 0)
    {
        printf("Invalid price!\n");
        return 0;
    }

    if (d < 0 || d > 100)
    {
        printf("Invalid discount percentage!\n");
        return 0;
    }

    if (t < 0 || t > 100)
    {
        printf("Invalid tax percentage!\n");
        return 0;
    }

    /* Calculations */
    subtotal = calculateSubtotal(q, p);

    discountedAmount = calculateDiscount(subtotal, d);

    finalBill = calculateFinalBill(discountedAmount, t);

    /* Bill Document */
    printf("\n==============================\n");
    printf("       ONLINE SHOPPING BILL\n");
    printf("==============================\n");

    printf("Quantity           : %d\n", q);
    printf("Price per item     : $%.2f\n", p);
    printf("Subtotal           : $%.2f\n", subtotal);
    printf("Discount           : %.2f%%\n", d);
    printf("Discounted Amount  : $%.2f\n", discountedAmount);
    printf("Tax                : %.2f%%\n", t);
    printf("Final Bill         : $%.2f\n", finalBill);

    printf("==============================\n");

    return 0;
}