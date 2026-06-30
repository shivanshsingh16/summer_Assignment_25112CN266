#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Transaction {
    string date;
    string type;
    double amount;
};

struct Account {
    int accountNo;
    string accountHolder;
    double balance;
    string accountType;
    vector<Transaction> transactions;
};

void addTransaction(Account &acc, string type, double amount, string date) {
    Transaction t;
    t.type = type;
    t.amount = amount;
    t.date = date;
    acc.transactions.push_back(t);
}

void displayAccount(Account &acc) {
    cout << "\n--- Account Details ---\n";
    cout << "Account No: " << acc.accountNo << "\n";
    cout << "Account Holder: " << acc.accountHolder << "\n";
    cout << "Account Type: " << acc.accountType << "\n";
    cout << "Balance: Rs. " << fixed << setprecision(2) << acc.balance << "\n";
}

void displayTransactions(Account &acc) {
    if(acc.transactions.empty()) {
        cout << "No transactions found!\n";
        return;
    }
    cout << "\n--- Transaction History ---\n";
    for(int i = 0; i < acc.transactions.size(); i++) {
        cout << "Date: " << acc.transactions[i].date << " | ";
        cout << "Type: " << acc.transactions[i].type << " | ";
        cout << "Amount: Rs. " << fixed << setprecision(2) << acc.transactions[i].amount << "\n";
    }
}

int main() {
    vector<Account> bank;
    int choice;
    string date = "01/01/2024";

    while(true) {
        cout << "\n===== Bank Management System =====\n";
        cout << "1. Create New Account\n";
        cout << "2. View Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Transfer Money\n";
        cout << "6. View Transaction History\n";
        cout << "7. View All Accounts\n";
        cout << "8. Delete Account\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Account acc;
            cout << "Enter Account Number: ";
            cin >> acc.accountNo;
            cin.ignore();
            cout << "Enter Account Holder Name: ";
            getline(cin, acc.accountHolder);
            cout << "Enter Account Type (Savings/Current): ";
            getline(cin, acc.accountType);
            cout << "Enter Initial Balance: ";
            cin >> acc.balance;
            bank.push_back(acc);
            cout << "Account created successfully!\n";
        }
        else if(choice == 2) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            bool found = false;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == accNo) {
                    displayAccount(bank[i]);
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Account not found!\n";
            }
        }
        else if(choice == 3) {
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bool found = false;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == accNo) {
                    if(amount > 0) {
                        bank[i].balance += amount;
                        addTransaction(bank[i], "Deposit", amount, date);
                        cout << "Amount deposited successfully!\n";
                        cout << "New Balance: Rs. " << fixed << setprecision(2) << bank[i].balance << "\n";
                    }
                    else {
                        cout << "Invalid amount!\n";
                    }
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Account not found!\n";
            }
        }
        else if(choice == 4) {
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bool found = false;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == accNo) {
                    if(amount > 0 && amount <= bank[i].balance) {
                        bank[i].balance -= amount;
                        addTransaction(bank[i], "Withdrawal", amount, date);
                        cout << "Amount withdrawn successfully!\n";
                        cout << "Remaining Balance: Rs. " << fixed << setprecision(2) << bank[i].balance << "\n";
                    }
                    else if(amount > bank[i].balance) {
                        cout << "Insufficient balance!\n";
                    }
                    else {
                        cout << "Invalid amount!\n";
                    }
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Account not found!\n";
            }
        }
        else if(choice == 5) {
            int fromAcc, toAcc;
            double amount;
            cout << "Enter Your Account Number: ";
            cin >> fromAcc;
            cout << "Enter Recipient Account Number: ";
            cin >> toAcc;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;
            
            int fromIdx = -1, toIdx = -1;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == fromAcc) fromIdx = i;
                if(bank[i].accountNo == toAcc) toIdx = i;
            }
            
            if(fromIdx == -1 || toIdx == -1) {
                cout << "Invalid account number!\n";
            }
            else if(fromAcc == toAcc) {
                cout << "Cannot transfer to same account!\n";
            }
            else if(amount > 0 && amount <= bank[fromIdx].balance) {
                bank[fromIdx].balance -= amount;
                bank[toIdx].balance += amount;
                addTransaction(bank[fromIdx], "Transfer Out", amount, date);
                addTransaction(bank[toIdx], "Transfer In", amount, date);
                cout << "Transfer completed successfully!\n";
                cout << "Your New Balance: Rs. " << fixed << setprecision(2) << bank[fromIdx].balance << "\n";
            }
            else if(amount > bank[fromIdx].balance) {
                cout << "Insufficient balance!\n";
            }
            else {
                cout << "Invalid amount!\n";
            }
        }
        else if(choice == 6) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            bool found = false;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == accNo) {
                    displayTransactions(bank[i]);
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Account not found!\n";
            }
        }
        else if(choice == 7) {
            if(bank.empty()) {
                cout << "No accounts found!\n";
            }
            else {
                cout << "\n--- All Accounts ---\n";
                for(int i = 0; i < bank.size(); i++) {
                    displayAccount(bank[i]);
                    cout << "\n";
                }
            }
        }
        else if(choice == 8) {
            int accNo;
            cout << "Enter Account Number to delete: ";
            cin >> accNo;
            bool found = false;
            for(int i = 0; i < bank.size(); i++) {
                if(bank[i].accountNo == accNo) {
                    bank.erase(bank.begin() + i);
                    cout << "Account deleted successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Account not found!\n";
            }
        }
        else if(choice == 9) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    cout << "Thank you for using Bank Management System!\n";
    return 0;
}