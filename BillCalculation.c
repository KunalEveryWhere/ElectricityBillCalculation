#include <stdio.h>

float calculateElectricityBill(int units, int month, float discount) {
    float totalCost = 0.0;

    if (month >= 6 && month <= 9) {
        if (units <= 240) {
            totalCost = units * 1.63;
        } else if (units <= 660) {
            totalCost = 240 * 1.63;
            units -= 240;
            totalCost += units * 2.38;
        } else if (units <= 1000) {
            totalCost = 240 * 1.63 + 420 * 2.38;
            units -= 660;
            totalCost += units * 3.52;
        } else if (units <= 1400) {
            totalCost = 240 * 1.63 + 420 * 2.38 + 340 * 3.52;
            units -= 1000;
            totalCost += units * 4.80;
        } else if (units <= 2000) {
            totalCost = 240 * 1.63 + 420 * 2.38 + 340 * 3.52 + 400 * 4.80;
            units -= 1400;
            totalCost += units * 5.83;
        } else {
            totalCost = 240 * 1.63 + 420 * 2.38 + 340 * 3.52 + 400 * 4.80 + 600 * 5.83;
            units -= 2000;
            totalCost += units * 7.69;
        }
    } else {
        if (units <= 240) {
            totalCost = units * 1.63;
        } else if (units <= 660) {
            totalCost = 240 * 1.63;
            units -= 240;
            totalCost += units * 2.10;
        } else if (units <= 1000) {
            totalCost = 240 * 1.63 + 420 * 2.10;
            units -= 660;
            totalCost += units * 2.89;
        } else if (units <= 1400) {
            totalCost = 240 * 1.63 + 420 * 2.10 + 340 * 2.89;
            units -= 1000;
            totalCost += units * 3.94;
        } else if (units <= 2000) {
            totalCost = 240 * 1.63 + 420 * 2.10 + 340 * 2.89 + 400 * 3.94;
            units -= 1400;
            totalCost += units * 4.74;
        } else {
            totalCost = 240 * 1.63 + 420 * 2.10 + 340 * 2.89 + 400 * 3.94 + 600 * 4.74;
            units -= 2000;
            totalCost += units * 6.03;
        }
    }

    // Apply the discount
    totalCost -= discount;

    return totalCost;
}


void calculateSplitElectricityBill(float totalUnits, float unitsA, float discount, int month) {
    // Calculate Party B's consumed units based on total units and Party A's consumed units
    float unitsB = totalUnits - unitsA;

    // Calculate individual bills
    float billA = calculateElectricityBill(unitsA, month, 0.0);
    float billB = calculateElectricityBill(unitsB, month, 0.0);

    // Calculate the total bill
    float totalBill = calculateElectricityBill(totalUnits, month, 0.0);

    // Calculate the remaining amount after applying the discount
    float payableBill = totalBill - discount;

    if (payableBill < 0) {
        printf("Discount exceeds the total bill. No further splitting is necessary.\n");
        return;
    }

    // Calculate the consumption ratios for Party A and Party B
    float consumptionRatioA = unitsA / totalUnits;
    float consumptionRatioB = unitsB / totalUnits;

    // Calculate the remaining amount to be paid
    float remainingAmount = payableBill - (billA + billB);

    // Calculate Party A and Party B's shares of the remaining amount based on consumption ratios
    float shareA = consumptionRatioA * remainingAmount;
    float shareB = consumptionRatioB * remainingAmount;

    printf("____________________________________________\n\n");

    // Display the total bill to be paid
    printf("Total Bill: \t\t\t\t\tNT$%.2f\n", payableBill);

    // Display the base bill and remaining amounts to be paid
    printf("\nBase Bill (Party A): \t\t\tNT$%.2f\n", billA);
    printf("Base Bill (Party B): \t\t\tNT$%.2f\n", billB);

    // Display the remaining bills
    printf("\nRemaining Bill (Party A): \t\tNT$%.2f\n", shareA);
    printf("Remaining Bill (Party B): \t\tNT$%.2f\n", shareB);

    // Display the final payments
    printf("\nParty A's Final Payment: \t\tNT$%.2f\n", billA + shareA);
    printf("Party B's Final Payment: \t\tNT$%.2f\n", billB + shareB);
}

int main() {
    int month;
    float totalUnits, unitsA, discount;

    printf("Enter the total units consumed: ");
    scanf("%f", &totalUnits);

    printf("Enter Party A's units consumed: ");
    scanf("%f", &unitsA);

    printf("Party B's units consumed: %.0f\n", (totalUnits - unitsA));

    printf("Enter the discount amount: NT$");
    scanf("%f", &discount);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    if (totalUnits < 0 || unitsA < 0 || discount < 0 || month < 1 || month > 12) {
        printf("Invalid input. Please enter valid values.\n");
    } else {
        calculateSplitElectricityBill(totalUnits, unitsA, discount, month);
    }

    return 0;
}