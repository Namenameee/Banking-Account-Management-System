# Bank Account Management Program

## Overview
This Bank Account Management Program is designed to simulate basic operations of a bank's financial system. It implements an inheritance hierarchy with a base class `Account` and two derived classes `SavingsAccount` and `CheckingAccount`. This structure allows the simulation of common banking transactions like deposits, withdrawals, and interest accumulation.

## Features
- **Account Class**: Represents a general bank account. Supports deposit (credit) and withdrawal (debit) operations.
- **SavingsAccount Class**: Inherits from `Account`. Adds interest-earning capabilities.
- **CheckingAccount Class**: Inherits from `Account`. Incorporates transaction fees for both deposits and withdrawals.

## Installation
No installation is required. This program is written in C++ and can be compiled and run using any standard C++ compiler.

## Usage
To use the program:
1. Compile the source code using a C++ compiler.
2. Run the executable.
3. Follow on-screen instructions to perform transactions on savings and checking accounts.

## Example
```cpp
// Create a savings account with an initial balance and interest rate
SavingsAccount savings(1000, 5);

// Create a checking account with an initial balance and transaction fee
CheckingAccount checking(500, 2);

// Perform various operations like deposit, withdrawal, and interest calculation
```

## Testing
The program includes an extensive test suite demonstrating various scenarios, including:

- Adding interest to savings accounts.
- Handling deposits and withdrawals in checking accounts.
- Ensuring transaction fees are applied correctly.
- Preventing overdrafts and handling error messages.
