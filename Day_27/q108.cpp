#include<iostream>
#include<vector>
using namespace std;

void q108()
{
    vector<vector<string>> students; 
    int input;
    
    while (true)
    {
        cout << "\n===== MARKSHEET GENERATION SYSTEM =====\n";
        cout << "Enter input: 1- Add Student Marks  2- View Marksheet  3- View All Marksheets  4- Calculate Grade  5- Delete Record  6- Exit\n";
        cin >> input;
        cin.ignore();                                  //revise this
        
        if (input == 1)
        {
            string roll, name, math, english, science;
            
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
                cout << "Enter mathematics marks: ";
                getline(cin, math);
                cout << "Enter english marks: ";
                getline(cin, english);
                cout << "Enter science marks: ";
                getline(cin, science);
                
                int mathMarks = stoi(math);
                int englishMarks = stoi(english);
                int scienceMarks = stoi(science);
                int total = mathMarks + englishMarks + scienceMarks;
                int percentage = total / 3;
                
                string grade;
                if (percentage >= 90)
                    grade = "A+";
                else if (percentage >= 80)
                    grade = "A";
                else if (percentage >= 70)
                    grade = "B";
                else if (percentage >= 60)
                    grade = "C";
                else if (percentage >= 50)
                    grade = "D";
                else
                    grade = "F";
                
                students.push_back({roll, name, math, english, science, to_string(total), to_string(percentage), grade});
                cout << "Student marks added successfully!\n";
            }
        }
        else if (input == 2)
        {
            string roll;
            cout << "Enter roll number to view marksheet: ";
            getline(cin, roll);
            
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    found = true;
                    cout << "\n========== MARKSHEET ==========\n";
                    cout << "Roll Number: " << students[i][0] << endl;
                    cout << "Name: " << students[i][1] << endl;
                    cout << "Mathematics: " << students[i][2] << endl;
                    cout << "English: " << students[i][3] << endl;
                    cout << "Science: " << students[i][4] << endl;
                    cout << "Total Marks: " << students[i][5] << endl;
                    cout << "Percentage: " << students[i][6] << "%" << endl;
                    cout << "Grade: " << students[i][7] << endl;
                    cout << "===============================\n";
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
            if (students.size() == 0)
            {
                cout << "No students in the system!\n";
            }
            else
            {
                cout << "\n========== ALL MARKSHEETS ==========\n";
                cout << "Roll No\t\tName\t\t\tTotal\t\tPercentage\tGrade\n";
                cout << "====================================================\n";
                
                for (int i = 0; i < students.size(); i++)
                {
                    cout << students[i][0] << "\t\t" << students[i][1] << "\t\t" << students[i][5] << "\t\t" << students[i][6] << "%\t\t" << students[i][7] << endl;
                }
                cout << "====================================================\n";
                cout << "Total Students: " << students.size() << endl;
                
                int totalPercentage = 0;
                for (int i = 0; i < students.size(); i++)
                {
                    totalPercentage += stoi(students[i][6]);
                }
                cout << "Class Average: " << (totalPercentage / students.size()) << "%" << endl;
            }
        }
        else if (input == 4)
        {
            string roll;
            cout << "Enter roll number to calculate grade: ";
            getline(cin, roll);
            
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i][0] == roll)
                {
                    found = true;
                    int percentage = stoi(students[i][6]);
                    
                    cout << "\n========== GRADE CALCULATION ==========\n";
                    cout << "Student Name: " << students[i][1] << endl;
                    cout << "Total Marks: " << students[i][5] << endl;
                    cout << "Percentage: " << percentage << "%" << endl;
                    cout << "Grade: " << students[i][7] << endl;
                    
                    if (percentage >= 90)
                        cout << "Result: Outstanding Performance!\n";
                    else if (percentage >= 80)
                        cout << "Result: Excellent Performance!\n";
                    else if (percentage >= 70)
                        cout << "Result: Good Performance\n";
                    else if (percentage >= 60)
                        cout << "Result: Average Performance\n";
                    else if (percentage >= 50)
                        cout << "Result: Below Average Performance\n";
                    else
                        cout << "Result: Failed\n";
                    
                    cout << "========================================\n";
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
        else if (input == 6)
        {
            cout << "Thank you for using Marksheet Generation System!\n";
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
    q108();
    return 0;
}