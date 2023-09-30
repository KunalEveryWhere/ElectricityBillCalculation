## Electricity Bill Calculation Algorithm

This algorithm outlines how the code calculates electricity bills for two parties, Party A and Party B, based on their consumption, applies a discount, and displays the results.

### Part 1: `calculateElectricityBill` Function

1. Initialize `totalCost` to 0.0, which will store the final electricity bill for a given set of inputs.

2. Check if the `month` falls within the summer months (June to September):
   - If true, use a specific rate structure for summer months; otherwise, use a different rate structure for other months.

3. Determine the electricity consumption rate based on different usage slabs:
   - If `units` are less than or equal to 240, calculate the cost using a fixed rate.
   - If `units` are between 241 and 660, calculate the cost for the first 240 units at a fixed rate and the remaining units at a different rate.
   - Repeat this process for additional usage slabs (1000, 1400, 2000) with corresponding rates.
   - If `units` exceed 2000, calculate the cost for the first 2000 units and the remaining units separately.

4. Apply the provided `discount` to the calculated `totalCost`.

5. Return the final `totalCost` as the electricity bill.

### Part 2: `calculateSplitElectricityBill` Function

1. Calculate `unitsB` (Party B's consumed units) by subtracting `unitsA` (Party A's consumed units) from `totalUnits` (total consumed units).

2. Calculate individual electricity bills for Party A (`billA`) and Party B (`billB`) using the `calculateElectricityBill` function, setting the discount to 0.0.

3. Calculate the total electricity bill (`totalBill`) for both parties combined using the `calculateElectricityBill` function with a discount of 0.0.

4. Calculate the remaining amount to be paid (`remainingAmount`) after applying the discount to the total bill.

5. Check if the `payableBill` (total bill after discount) is less than 0. If so, print a message indicating that the discount exceeds the total bill, and no further splitting is necessary.

6. Calculate the consumption ratios for Party A (`consumptionRatioA`) and Party B (`consumptionRatioB`) based on their consumed units and the total consumed units.

7. Calculate the remaining bills for both parties:
   - Party A's remaining bill (`shareA`) is the proportion of the remaining amount based on `consumptionRatioA`.
   - Party B's remaining bill (`shareB`) is the proportion of the remaining amount based on `consumptionRatioB`.

8. Display the calculated values:
   - Total bill to be paid (`payableBill`).
   - Base bill for Party A (`billA`).
   - Base bill for Party B (`billB`).
   - Remaining bills for Party A and Party B (`shareA` and `shareB`).
   - Final payment amounts for Party A and Party B.

### Part 3: `main` Function

1. Prompt the user to input the following information:
   - Total units consumed (`totalUnits`).
   - Party A's units consumed (`unitsA`).
   - Discount amount (`discount`).
   - Month of consumption (`month`).

2. Validate the input to ensure that all values are non-negative, and the month falls within the valid range (1-12).

3. If the input is valid, call the `calculateSplitElectricityBill` function to calculate and display the electricity bill split between Party A and Party B.

4. Terminate the program.

This algorithm summarizes the step-by-step process by which the code calculates and splits electricity bills based on different rate structures and user-provided input values.