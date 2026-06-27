#include<iostream>
#include<vector>
using namespace std;

void q107()
{
    vector<vector<string>> employees; 
    int input;
    
    while (true)
    {
        cout << "\n===== SALARY MANAGEMENT SYSTEM =====\n";
        cout << "Enter input: 1- Add Employee  2- View Salary  3- Update Salary  4- Calculate Net Salary  5- View All Employees  6- Exit\n";
        cin >> input;
        cin.ignore();                      //learns and revise this
        
        if (input == 1)
        {
            string empId, name, basicSalary, allowance, deduction;
            
            cout << "Enter employee ID: ";
            getline(cin, empId);
            
            bool exists = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    exists = true;
                    break;
                }
            }
            
            if (exists)
            {
                cout << "Error! Employee ID already exists.\n";
            }
            else
            {
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter basic salary: ";
                getline(cin, basicSalary);
                cout << "Enter allowance: ";
                getline(cin, allowance);
                cout << "Enter deduction: ";
                getline(cin, deduction);
                
                employees.push_back({empId, name, basicSalary, allowance, deduction});
                cout << "Employee salary record added successfully!\n";
            }
        }
        else if (input == 2)
        {
            string empId;
            cout << "Enter employee ID to view salary: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    int basicSalary = stoi(employees[i][2]);
                    int allowance = stoi(employees[i][3]);
                    int deduction = stoi(employees[i][4]);
                    int netSalary = basicSalary + allowance - deduction;
                    
                    cout << "\n========== SALARY DETAILS ==========\n";
                    cout << "Employee ID: " << employees[i][0] << endl;
                    cout << "Name: " << employees[i][1] << endl;
                    cout << "Basic Salary: " << basicSalary << endl;
                    cout << "Allowance: " << allowance << endl;
                    cout << "Deduction: " << deduction << endl;
                    cout << "Net Salary: " << netSalary << endl;
                    cout << "====================================\n";
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Employee not found!\n";
            }
        }
        else if (input == 3)
        {
            string empId;
            cout << "Enter employee ID to update salary: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    cout << "\nWhat do you want to update?\n";
                    cout << "1- Basic Salary  2- Allowance  3- Deduction\n";
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    
                    if (choice == 1)
                    {
                        cout << "Enter new basic salary: ";
                        getline(cin, employees[i][2]);
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter new allowance: ";
                        getline(cin, employees[i][3]);
                    }
                    else if (choice == 3)
                    {
                        cout << "Enter new deduction: ";
                        getline(cin, employees[i][4]);
                    }
                    else
                    {
                        cout << "Invalid choice!\n";
                    }
                    
                    cout << "Salary record updated successfully!\n";
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Employee not found!\n";
            }
        }
        else if (input == 4)
        {
            string empId;
            cout << "Enter employee ID to calculate net salary: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    int basicSalary = stoi(employees[i][2]);
                    int allowance = stoi(employees[i][3]);
                    int deduction = stoi(employees[i][4]);
                    int netSalary = basicSalary + allowance - deduction;
                    
                    cout << "\n========== NET SALARY CALCULATION ==========\n";
                    cout << "Employee Name: " << employees[i][1] << endl;
                    cout << "Basic Salary: " << basicSalary << endl;
                    cout << "+ Allowance: " << allowance << endl;
                    cout << "- Deduction: " << deduction << endl;
                    cout << "-------------------------------------------\n";
                    cout << "NET SALARY: " << netSalary << endl;
                    cout << "===========================================\n";
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Employee not found!\n";
            }
        }
        else if (input == 5)
        {
            if (employees.size() == 0)
            {
                cout << "No employees in the system!\n";
            }
            else
            {
                cout << "\n========== ALL EMPLOYEES SALARY ==========\n";
                cout << "Emp ID\t\tName\t\t\tNet Salary\n";
                cout << "==========================================\n";
                
                int totalSalary = 0;
                for (int i = 0; i < employees.size(); i++)
                {
                    int basicSalary = stoi(employees[i][2]);
                    int allowance = stoi(employees[i][3]);
                    int deduction = stoi(employees[i][4]);
                    int netSalary = basicSalary + allowance - deduction;
                    
                    cout << employees[i][0] << "\t\t" << employees[i][1] << "\t\t" << netSalary << endl;
                    totalSalary += netSalary;
                }
                cout << "==========================================\n";
                cout << "Total Employees: " << employees.size() << endl;
                cout << "Total Salary: " << totalSalary << endl;
            }
        }
        else if (input == 6)
        {
            cout << "Thank you for using Salary Management System!\n";
            break;
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }
    }
}

int main()
{
    q107();
    return 0;
}