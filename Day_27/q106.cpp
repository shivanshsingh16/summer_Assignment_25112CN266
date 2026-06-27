#include<iostream>
#include<vector>
using namespace std;

void q106()
{
    vector<vector<string>> employees;  
    int input;
    
    while (true)
    {
        cout << "\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n";
        cout << "Enter input: 1- Add Employee  2- View Employee  3- Update Employee  4- Delete Employee  5- View All Employees  6- Exit\n";
        cin >> input;
        cin.ignore();                        //learns and revise this
        
        if (input == 1)
        {
            string empId, name, department, position, phone;
            
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
                cout << "Enter department: ";
                getline(cin, department);
                cout << "Enter position: ";
                getline(cin, position);
                cout << "Enter phone number: ";
                getline(cin, phone);
                
                employees.push_back({empId, name, department, position, phone});
                cout << "Employee added successfully!\n";
            }
        }
        else if (input == 2)
        {
            string empId;
            cout << "Enter employee ID to search: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    cout << "\n======== EMPLOYEE DETAILS ========\n";
                    cout << "Employee ID: " << employees[i][0] << endl;
                    cout << "Name: " << employees[i][1] << endl;
                    cout << "Department: " << employees[i][2] << endl;
                    cout << "Position: " << employees[i][3] << endl;
                    cout << "Phone: " << employees[i][4] << endl;
                    cout<<endl;
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
            cout << "Enter employee ID to update: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    cout << "\nWhat do you want to update?\n";
                    cout << "1- Name  2- Department  3- Position  4- Phone\n";
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    
                    if (choice == 1)
                    {
                        cout << "Enter new name: ";
                        getline(cin, employees[i][1]);
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter new department: ";
                        getline(cin, employees[i][2]);
                    }
                    else if (choice == 3)
                    {
                        cout << "Enter new position: ";
                        getline(cin, employees[i][3]);
                    }
                    else if (choice == 4)
                    {
                        cout << "Enter new phone: ";
                        getline(cin, employees[i][4]);
                    }
                    else
                    {
                        cout << "Invalid choice!\n";
                    }
                    
                    cout << "Record updated successfully!\n";
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
            cout << "Enter employee ID to delete: ";
            getline(cin, empId);
            
            bool found = false;
            for (int i = 0; i < employees.size(); i++)
            {
                if (employees[i][0] == empId)
                {
                    found = true;
                    employees.erase(employees.begin() + i);
                    cout << "Employee record deleted successfully!\n";
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
                cout << "\n========== ALL EMPLOYEES ==========\n";
                cout << "Emp ID\t\tName\t\t\tDepartment\n";
                cout << "===================================\n";
                
                for (int i = 0; i < employees.size(); i++)
                {
                    cout << employees[i][0] << "\t\t" << employees[i][1] << "\t\t" << employees[i][2] << endl;
                }
                cout << "===================================\n";
                cout << "Total Employees: " << employees.size() << endl;
            }
        }
        else if (input == 6)
        {
            cout << "Thank you for using Employee Management System!\n";
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
    q106();
    return 0;
}