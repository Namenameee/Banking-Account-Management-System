// Base Class: Account
#include <iostream>
#include <string>

class Account {
protected:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            std::cout << "Error: Initial balance cannot be negative." << std::endl;
        }
    }

    void credit(double amount) {
        balance += amount;
    }

    bool debit(double amount) {
        if (amount > balance) {
            std::cout << "Debit amount exceeded account balance." << std::endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    double getBalance() const {
        return balance;
    }
};

// Derived Class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double interestRate)
    : Account(initialBalance), interestRate(interestRate) {}

    double calculateInterest() const {
        return balance * interestRate / 100;
    }
};


// Derived Class: CheckingAccount
class CheckingAccount : public Account {
private:
    double transactionFee;

    void chargeFee() {
        balance -= transactionFee;
    }

public:
    CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee) {}

    void credit(double amount) {
        Account::credit(amount);
        chargeFee();
    }

    bool debit(double amount) {
        bool isDebited = Account::debit(amount);
        if (isDebited) {
            chargeFee();
        }
        return isDebited;
    }
};


// Test Program
int main() {
    SavingsAccount savings(1000, 5); // Initial balance $1000, interest rate 5%
    CheckingAccount checking(500, 1); // Initial balance $500, transaction fee $1

    // Test SavingsAccount
    std::cout << "Savings account balance: $" << savings.getBalance() << std::endl;
    double interest = savings.calculateInterest();
    std::cout << "Interest earned: $" << interest << std::endl;
    savings.credit(interest);
    std::cout << "Updated savings account balance: $" << savings.getBalance() << std::endl;

    // Test CheckingAccount
    std::cout << "\nChecking account balance: $" << checking.getBalance() << std::endl;
    checking.credit(200); // Deposit $200
    std::cout << "Checking account balance after credit: $" << checking.getBalance() << std::endl;
    checking.debit(100); // Withdraw $100
    std::cout << "Checking account balance after debit: $" << checking.getBalance() << std::endl;

    return 0;
}

