#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks[5];
    float average;
};

void calculateAverage(Student &s) {
    float sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += s.marks[i];
    }
    s.average = sum / 5.0;
}

int main() {
    vector<Student> students;
    int choice;

    while(true) {
        cout << "\n=== Student Record System ===\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Student s;
            cout << "Enter Roll No: ";
            cin >> s.rollNo;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter marks for 5 subjects:\n";
            for(int i = 0; i < 5; i++) {
                cout << "Subject " << (i+1) << ": ";
                cin >> s.marks[i];
            }
            calculateAverage(s);
            students.push_back(s);
            cout << "Student added successfully!\n";
        }
        else if(choice == 2) {
            if(students.empty()) {
                cout << "No students found!\n";
            }
            else {
                cout << "\n--- Student Records ---\n";
                for(int i = 0; i < students.size(); i++) {
                    cout << "Roll No: " << students[i].rollNo << "\n";
                    cout << "Name: " << students[i].name << "\n";
                    cout << "Marks: ";
                    for(int j = 0; j < 5; j++) {
                        cout << students[i].marks[j] << " ";
                    }
                    cout << "\nAverage: " << fixed << setprecision(2) << students[i].average << "\n";
                    cout << "---\n";
                }
            }
        }
        else if(choice == 3) {
            int rollNo;
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            bool found = false;
            for(int i = 0; i < students.size(); i++) {
                if(students[i].rollNo == rollNo) {
                    cout << "\nStudent Found!\n";
                    cout << "Name: " << students[i].name << "\n";
                    cout << "Marks: ";
                    for(int j = 0; j < 5; j++) {
                        cout << students[i].marks[j] << " ";
                    }
                    cout << "\nAverage: " << fixed << setprecision(2) << students[i].average << "\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Student not found!\n";
            }
        }
        else if(choice == 4) {
            int rollNo;
            cout << "Enter Roll No to update marks: ";
            cin >> rollNo;
            bool found = false;
            for(int i = 0; i < students.size(); i++) {
                if(students[i].rollNo == rollNo) {
                    cout << "Enter new marks for 5 subjects:\n";
                    for(int j = 0; j < 5; j++) {
                        cout << "Subject " << (j+1) << ": ";
                        cin >> students[i].marks[j];
                    }
                    calculateAverage(students[i]);
                    cout << "Marks updated successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Student not found!\n";
            }
        }
        else if(choice == 5) {
            int rollNo;
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            bool found = false;
            for(int i = 0; i < students.size(); i++) {
                if(students[i].rollNo == rollNo) {
                    students.erase(students.begin() + i);
                    cout << "Student deleted successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Student not found!\n";
            }
        }
        else if(choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}