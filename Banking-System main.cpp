#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string holder, int accountNum) {
        accountHolder = holder;
        accountNumber = accountNum;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    double getBalance() {
        return balance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void displayAccountInfo() {
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }
};

class BankingSystem {
private:
    vector<BankAccount> accounts;
    int nextAccountNumber;

public:
    BankingSystem() {
        nextAccountNumber = 1001;
    }

    void createAccount(string holderName) {
        BankAccount newAccount(holderName, nextAccountNumber++);
        accounts.push_back(newAccount);
        cout << "Account created successfully for " << holderName << " with account number: " << nextAccountNumber - 1 << "\n";
    }

    BankAccount* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (accountNumber == account.getAccountNumber()) {
                return &account;
            }
        }
        return nullptr;
    }

    void depositMoney(int accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawMoney(int accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void checkBalance(int accountNumber) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            cout << "Balance for account number " << accountNumber << ": $" << account->getBalance() << "\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayAccountInfo(int accountNumber) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->displayAccountInfo();
        } else {
            cout << "Account not found.\n";
        }
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- Banking System ---\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Check Balance\n";
            cout << "5. Display Account Info\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            string holderName;
            int accountNum;
            double amount;

            switch (choice) {
                case 1:
                    cout << "Enter account holder name: ";
                    cin.ignore();
                    getline(cin, holderName);
                    createAccount(holderName);
                    break;
                case 2:
                    cout << "Enter account number: ";
                    cin >> accountNum;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    depositMoney(accountNum, amount);
                    break;
                case 3:
                    cout << "Enter account number: ";
                    cin >> accountNum;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    withdrawMoney(accountNum, amount);
                    break;
                case 4:
                    cout << "Enter account number: ";
                    cin >> accountNum;
                    checkBalance(accountNum);
                    break;
                case 5:
                    cout << "Enter account number: ";
                    cin >> accountNum;
                    displayAccountInfo(accountNum);
                    break;
                case 6:
                    cout << "Exiting the banking system...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    BankingSystem bank;
    bank.showMenu();
    return 0;
}
