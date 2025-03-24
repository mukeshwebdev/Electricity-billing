#include <stdio.h>
#include <conio.h>
// Function prototype
void calculateBill(int units);

int main() {
    int units;

    // Input: Get units consumed from user
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    // Validate input
    if (units < 0) {
        printf("Invalid input! Units consumed cannot be negative.\n");
        return 1;
    }

    // Process and display the bill
    calculateBill(units);

    return 0;
}

void calculateBill(int units) {
    float energyCharge = 0.0, fixedCharge = 100.0, electricityDuty = 0.0, totalBill = 0.0;
    int slabUnits[] = {400, 100, 100, 200, 200, 999999}; // Slabs
    float slabRates[] = {4.80, 6.45, 8.55, 9.65, 10.70, 11.80}; // Rates per unit
    int i = 0, remainingUnits = units;

    printf("\n-------------------------------------\n");
    printf("      TAMIL NADU ELECTRICITY BILL    \n");
    printf("-------------------------------------\n");
    printf("Units Consumed      : %d units\n", units);
    
    // Slab-wise calculation
    while (remainingUnits > 0 && i < 6) {
        int usedUnits = (remainingUnits > slabUnits[i]) ? slabUnits[i] : remainingUnits;
        float charge = usedUnits * slabRates[i];
        energyCharge += charge;
        
        // Print each slab charge
        printf("Slab %d (%d units @ ₹%.2f/unit): ₹%.2f\n", i + 1, usedUnits, slabRates[i], charge);
        
        remainingUnits -= usedUnits;
        i++;
    }

    // Electricity Duty Calculation (5% of energy charge)
    electricityDuty = energyCharge * 0.05;

    // Total Bill Calculation
    totalBill = energyCharge + fixedCharge + electricityDuty;

    // Display Bill Breakdown
    printf("-------------------------------------\n");
    printf("Energy Charges      : ₹%.2f\n", energyCharge);
    printf("Fixed Charges       : ₹%.2f\n", fixedCharge);
    printf("Electricity Duty (5%%) : ₹%.2f\n", electricityDuty);
    printf("-------------------------------------\n");
    printf("Total Payable Amount: ₹%.2f\n", totalBill);
    printf("-------------------------------------\n");
}
