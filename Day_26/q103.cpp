#include<iostream>
#include<vector>
using namespace std;

void q103()
{
    vector<vector<int>> bank;  // stores {account_number, password, balance}
    int input;
    
    while (true)
    {
        cout << "\n===== ATM SIMULATION =====\n";
        cout << "Enter input: 1- Open Bank Account  2- Withdraw Cash  3- Deposit Cash  4- Check Balance  5- Exit\n";
        cin >> input;
        
        if (input == 1)
        {
            int acc;
            int pwd;
            int balance;
            
            cout << "Enter account number: ";
            cin >> acc;
            
            int i = 0;
            bool accountExists = false;
            while (i < bank.size())
            {
                if (bank[i][0] == acc)
                {
                    accountExists = true;
                    break;
                }
                i++;
            }
            
            if (accountExists)
            {
                cout << "Error! Account already exists. Choose another account number.\n";
            }
            else
            {
                cout << "Enter password: ";
                cin >> pwd;
                cout << "Enter initial deposit amount: ";
                cin >> balance;
                
                bank.push_back({acc, pwd, balance});
                cout << "Account created successfully!\n";
            }
        }
        else if (input == 2)
        {
            int acc;
            int pwd;
            
            cout << "Enter account number: ";
            cin >> acc;
            
            bool found = false;
            for (int i = 0; i < bank.size(); i++)
            {
                if (bank[i][0] == acc)
                {
                    found = true;
                    cout << "Enter password: ";
                    cin >> pwd;
                    
                    if (bank[i][1] == pwd)
                    {
                        int with;
                        cout << "Enter the amount you want to withdraw: ";
                        cin >> with;
                        
                        if ((bank[i][2] - with) < 0)
                        {
                            cout << "Error! Insufficient balance. Your balance: " << bank[i][2] << endl;
                        }
                        else
                        {
                            bank[i][2] = bank[i][2] - with;
                            cout << "Withdrawal successful!\n";
                            cout << "Remaining balance: " << bank[i][2] << endl;
                        }
                    }
                    else
                    {
                        cout << "Wrong password! Try again.\n";
                    }
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Account number not found!\n";
            }
        }
        else if (input == 3)
        {
            int acc;
            int pwd;
            
            cout << "Enter account number: ";
            cin >> acc;
            
            bool found = false;
            for (int i = 0; i < bank.size(); i++)
            {
                if (bank[i][0] == acc)
                {
                    found = true;
                    cout << "Enter password: ";
                    cin >> pwd;
                    
                    if (bank[i][1] == pwd)
                    {
                        int deposit;
                        cout << "Enter the amount you want to deposit: ";
                        cin >> deposit;
                        
                        bank[i][2] = bank[i][2] + deposit;
                        cout << "Deposit successful!\n";
                        cout << "New balance: " << bank[i][2] << endl;
                    }
                    else
                    {
                        cout << "Wrong password! Try again.\n";
                    }
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Account number not found!\n";
            }
        }
        else if (input == 4)
        {
            int acc;
            int pwd;
            
            cout << "Enter account number: ";
            cin >> acc;
            
            bool found = false;
            for (int i = 0; i < bank.size(); i++)
            {
                if (bank[i][0] == acc)
                {
                    found = true;
                    cout << "Enter password: ";
                    cin >> pwd;
                    
                    if (bank[i][1] == pwd)
                    {
                        cout << "Your balance is: " << bank[i][2] << endl;
                    }
                    else
                    {
                        cout << "Wrong password! Try again.\n";
                    }
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Account number not found!\n";
            }
        }
        else if (input == 5)
        {
            cout << "Thank you for using our ATM!\n";
            break;
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }
    }
}


int main(){
    q103();
}