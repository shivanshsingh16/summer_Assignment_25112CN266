#include<iostream>
#include<vector>
using namespace std;

void q105()
{
    vector<vector<string>> students; 
    int input;
    
    while (true)
    {
        cout << "\n==== STUDENT RECORD MANAGEMENT SYSTEM ====\n";
        cout << "Enter input: 1- Add Student  2- View Student  3- Update Student  4- Delete Student  5- View All Students  6- Exit\n";
        cin >> input;
        cin.ignore();                       //learns and revise this
        
        if (input == 1)
        {
            string roll, name, email, phone, address;
            
            cout << "Enter roll number: ";
            getline(cin, roll);
            
            bool exists = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    exists = true;
                    break;
                }
            }
            
            if (exists)
            {
                cout << "Error! Roll number already exists.\n";
            }
            else
            {
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter phone number: ";
                getline(cin, phone);
                cout << "Enter address: ";
                getline(cin, address);
                
                students.push_back({roll, name, email, phone, address});
                cout << "Student added successfully!\n";
            }
        }
        else if (input == 2)
        {
            string roll;
            cout << "Enter roll number to search: ";
            getline(cin, roll);
            
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    found = true;
                    cout << "\n========== STUDENT DETAILS ==========\n";
                    cout << "Roll Number: " << students[i][0] << endl;
                    cout << "Name: " << students[i][1] << endl;
                    cout << "Email: " << students[i][2] << endl;
                    cout << "Phone: " << students[i][3] << endl;
                    cout << "Address: " << students[i][4] << endl;
                    cout << "=====================================\n";
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Student not found!\n";
            }
        }
        else if (input == 3)
        {
            string roll;
            cout << "Enter roll number to update: ";
            getline(cin, roll);
            
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    found = true;
                    cout << "\nWhat do you want to update?\n";
                    cout << "1- Name  2- Email  3- Phone  4- Address\n";
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    
                    if (choice == 1)
                    {
                        cout << "Enter new name: ";
                        getline(cin, students[i][1]);
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter new email: ";
                        getline(cin, students[i][2]);
                    }
                    else if (choice == 3)
                    {
                        cout << "Enter new phone: ";
                        getline(cin, students[i][3]);
                    }
                    else if (choice == 4)
                    {
                        cout << "Enter new address: ";
                        getline(cin, students[i][4]);
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
                cout << "Student not found!\n";
            }
        }
        else if (input == 4)
        {
            string roll;
            cout << "Enter roll number to delete: ";
            getline(cin, roll);
            
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    found = true;
                    students.erase(students.begin() + i);
                    cout << "Student record deleted successfully!\n";
                    break;
                }
            }
            
            if (!found)
            {
                cout << "Student not found!\n";
            }
        }
        else if (input == 5)
        {
            if (students.size() == 0)
            {
                cout << "No students in the system!\n";
            }
            else
            {
                cout << "\n========== ALL STUDENTS ==========\n";
                cout << "Roll No\t\tName\t\t\tEmail\n";
                cout << "=================================\n";
                
                for (int i = 0; i < students.size(); i++)
                {
                    cout << students[i][0] << "\t\t" << students[i][1] << "\t\t" << students[i][2] << endl;
                }
                cout << "=================================\n";
                cout << "Total Students: " << students.size() << endl;
            }
        }
        else if (input == 6)
        {
            cout << "Thank you for using Student Record Management System!\n";
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
    q105();
    return 0;
}