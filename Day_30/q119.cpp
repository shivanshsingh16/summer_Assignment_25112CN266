#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Employee {
    int empId;
    string name;
    string department;
    double salary;
    int yearsOfService;
};

double calculateBonus(Employee &e) {
    if(e.yearsOfService < 1) return 0;
    else if(e.yearsOfService < 3) return e.salary * 0.05;
    else if(e.yearsOfService < 5) return e.salary * 0.10;
    else return e.salary * 0.15;
}

int main() {
    vector<Employee> employees;
    int choice;

    while(true) {
        cout << "\n=== Mini Employee Management System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Search by Department\n";
        cout << "5. Update Salary\n";
        cout << "6. Calculate Bonus\n";
        cout << "7. Delete Employee\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Employee e;
            cout << "Enter Employee ID: ";
            cin >> e.empId;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, e.name);
            cout << "Enter Department: ";
            getline(cin, e.department);
            cout << "Enter Salary: ";
            cin >> e.salary;
            cout << "Enter Years of Service: ";
            cin >> e.yearsOfService;
            employees.push_back(e);
            cout << "Employee added successfully!\n";
        }
        else if(choice == 2) {
            if(employees.empty()) {
                cout << "No employees found!\n";
            }
            else {
                cout << "\n--- All Employees ---\n";
                for(int i = 0; i < employees.size(); i++) {
                    cout << "ID: " << employees[i].empId << "\n";
                    cout << "Name: " << employees[i].name << "\n";
                    cout << "Department: " << employees[i].department << "\n";
                    cout << "Salary: " << fixed << setprecision(2) << employees[i].salary << "\n";
                    cout << "Years of Service: " << employees[i].yearsOfService << "\n";
                    cout << "---\n";
                }
            }
        }
        else if(choice == 3) {
            int empId;
            cout << "Enter Employee ID to search: ";
            cin >> empId;
            bool found = false;
            for(int i = 0; i < employees.size(); i++) {
                if(employees[i].empId == empId) {
                    cout << "\nEmployee Found!\n";
                    cout << "Name: " << employees[i].name << "\n";
                    cout << "Department: " << employees[i].department << "\n";
                    cout << "Salary: " << fixed << setprecision(2) << employees[i].salary << "\n";
                    cout << "Years of Service: " << employees[i].yearsOfService << "\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Employee not found!\n";
            }
        }
        else if(choice == 4) {
            string dept;
            cin.ignore();
            cout << "Enter Department to search: ";
            getline(cin, dept);
            bool found = false;
            cout << "\n--- Employees in " << dept << " ---\n";
            for(int i = 0; i < employees.size(); i++) {
                if(employees[i].department == dept) {
                    cout << "ID: " << employees[i].empId << "\n";
                    cout << "Name: " << employees[i].name << "\n";
                    cout << "Salary: " << fixed << setprecision(2) << employees[i].salary << "\n";
                    cout << "Years of Service: " << employees[i].yearsOfService << "\n";
                    cout << "---\n";
                    found = true;
                }
            }
            if(!found) {
                cout << "No employees found in this department!\n";
            }
        }
        else if(choice == 5) {
            int empId;
            cout << "Enter Employee ID to update salary: ";
            cin >> empId;
            bool found = false;
            for(int i = 0; i < employees.size(); i++) {
                if(employees[i].empId == empId) {
                    cout << "Current Salary: " << fixed << setprecision(2) << employees[i].salary << "\n";
                    cout << "Enter New Salary: ";
                    cin >> employees[i].salary;
                    cout << "Salary updated successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Employee not found!\n";
            }
        }
        else if(choice == 6) {
            int empId;
            cout << "Enter Employee ID to calculate bonus: ";
            cin >> empId;
            bool found = false;
            for(int i = 0; i < employees.size(); i++) {
                if(employees[i].empId == empId) {
                    double bonus = calculateBonus(employees[i]);
                    cout << "Name: " << employees[i].name << "\n";
                    cout << "Salary: " << fixed << setprecision(2) << employees[i].salary << "\n";
                    cout << "Years of Service: " << employees[i].yearsOfService << "\n";
                    cout << "Bonus: " << fixed << setprecision(2) << bonus << "\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Employee not found!\n";
            }
        }
        else if(choice == 7) {
            int empId;
            cout << "Enter Employee ID to delete: ";
            cin >> empId;
            bool found = false;
            for(int i = 0; i < employees.size(); i++) {
                if(employees[i].empId == empId) {
                    employees.erase(employees.begin() + i);
                    cout << "Employee deleted successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Employee not found!\n";
            }
        }
        else if(choice == 8) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}