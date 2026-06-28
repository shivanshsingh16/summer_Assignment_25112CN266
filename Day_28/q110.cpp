#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct Account {
    int accountNo;
    char name[50];
    double balance;
    char accountType[20];
};

vector<Account> accounts;

void createAccount() {
    Account a;
    cout << "Enter Account Number: ";
    cin >> a.accountNo;
    
    for (auto& acc : accounts) {
        if (acc.accountNo == a.accountNo) {
            cout << "Account already exists!\n";
            return;
        }
    }
    
    cin.ignore();
    cout << "Enter Account Holder Name: ";
    cin.getline(a.name, 50);
    cout << "Enter Account Type (Saving/Current): ";
    cin.getline(a.accountType, 20);
    cout << "Enter Initial Balance: ";
    cin >> a.balance;
    
    accounts.push_back(a);
    cout << "Account created successfully!\n";
}

void viewAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found.\n";
        return;
    }
    
    cout << "\n" << setw(12) << "Account No" << setw(20) << "Name" 
         << setw(15) << "Type" << setw(15) << "Balance\n";
    cout << string(62, '-') << "\n";
    
    for (auto& a : accounts) {
        cout << setw(12) << a.accountNo << setw(20) << a.name 
             << setw(15) << a.accountType << setw(15) << fixed << setprecision(2) << a.balance << "\n";
    }
    cout << "\n";
}

void viewAccount() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    
    for (auto& a : accounts) {
        if (a.accountNo == accNo) {
            cout << "\nAccount Number: " << a.accountNo << "\n";
            cout << "Name: " << a.name << "\n";
            cout << "Type: " << a.accountType << "\n";
            cout << "Balance: " << fixed << setprecision(2) << a.balance << "\n\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

void deposit() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }
    
    for (auto& a : accounts) {
        if (a.accountNo == accNo) {
            a.balance += amount;
            cout << "Amount " << amount << " deposited successfully!\n";
            cout << "New Balance: " << fixed << setprecision(2) << a.balance << "\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdraw() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }
    
    for (auto& a : accounts) {
        if (a.accountNo == accNo) {
            if (a.balance >= amount) {
                a.balance -= amount;
                cout << "Amount " << amount << " withdrawn successfully!\n";
                cout << "New Balance: " << fixed << setprecision(2) << a.balance << "\n";
            } else {
                cout << "Insufficient balance!\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

void deleteAccount() {
    int accNo;
    cout << "Enter Account Number to delete: ";
    cin >> accNo;
    
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNo == accNo) {
            accounts.erase(accounts.begin() + i);
            cout << "Account deleted successfully!\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

int main() {
    int choice;
    
    while (true) {
        cout << "\n===== BANK ACCOUNT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. View All Accounts\n";
        cout << "3. View Account Details\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAllAccounts(); break;
            case 3: viewAccount(); break;
            case 4: deposit(); break;
            case 5: withdraw(); break;
            case 6: deleteAccount(); break;
            case 7: cout << "Thank you!\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}