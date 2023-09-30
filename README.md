# Electricity Bill Calculator

This C program calculates and splits electricity bills between two parties, Party A and Party B, based on their respective electricity consumption, a discount, and the month of consumption.

## Table of Contents

- [Electricity Bill Calculator](#electricity-bill-calculator)
  - [Table of Contents](#table-of-contents)
  - [Prerequisites](#prerequisites)
  - [Usage](#usage)
    - [Compilation](#compilation)
    - [Execution](#execution)
  - [Input Validation](#input-validation)
  - [Output](#output)
  - [Example Usage](#example-usage)
  - [Contributing](#contributing)
  - [License](#license)

## Prerequisites

Before using this program, ensure that you have the following prerequisites:

- C Compiler (GCC recommended)
- Terminal or Command Prompt (for execution)

## Usage

### Compilation

To compile the program, follow these steps:

1. Open your terminal or command prompt.

2. Navigate to the directory where the `electricity_bill.c` file is located using the `cd` command. For example:

   ```shell
   cd /path/to/electricity_bill/
   ```

3. Compile the program using the GCC compiler. You can use the following command:

   ```shell
   gcc electricity_bill.c -o electricity_bill
   ```

   This will generate an executable file named `electricity_bill` in the same directory.

### Execution

To execute the program, follow these steps:

1. In the same terminal window, run the following command:

   ```shell
   ./electricity_bill
   ```

2. The program will prompt you to enter the following information:

   - Total units consumed.
   - Party A's units consumed.
   - Discount amount (in NT$).
   - Month of consumption (1-12).

3. Enter the required information as prompted.

4. The program will then calculate and display the electricity bill split between Party A and Party B based on the provided information.

## Input Validation

The program performs input validation to ensure that all input values are valid:

- All input values (total units consumed, Party A's units consumed, discount amount, and month) must be non-negative.
- The month must be within the valid range (1-12).

If any input is invalid, the program will display an error message and terminate without performing calculations.

## Output

The program displays the following information:

- Total bill amount (after applying the discount).
- Base bill for Party A.
- Base bill for Party B.
- Remaining bill for Party A.
- Remaining bill for Party B.
- Final payment amount for Party A.
- Final payment amount for Party B.

## Example Usage

Here's an example of how to use the program:

```shell
Enter the total units consumed: 800
Enter Party A's units consumed: 400
Party B's units consumed: 400
Enter the discount amount: NT$100
Enter the month (1-12): 7
```

Output:

```
____________________________________________

Total Bill:                              NT$1033.76

Base Bill (Party A):                     NT$652.00
Base Bill (Party B):                     NT$381.76

Remaining Bill (Party A):                NT$61.00
Remaining Bill (Party B):                NT$39.76

Party A's Final Payment:                 NT$713.00
Party B's Final Payment:                 NT$421.52
```

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Your contributions are welcome and appreciated.

## License

This project is licensed under the [MIT License](LICENSE).

---

Enjoy using the Electricity Bill Calculator! If you have any questions or encounter any issues, please don't hesitate to reach out.