#include<iostream>
using namespace std;

int main(){
    double a, b;
    int choice;
    
    while(true){
        cout << "\n=== Calculator Menu ===" << endl;
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 5) break;
        
        if(choice < 1 || choice > 5){
            cout << "Invalid choice!\n";
            continue;
        }
        
        cout << "Enter two numbers: ";
        cin >> a >> b;
        
        switch(choice){
            case 1:
                cout << "Result: " << a + b << endl;
                break;
            case 2:
                cout << "Result: " << a - b << endl;
                break;
            case 3:
                cout << "Result: " << a * b << endl;
                break;
            case 4:
                if(b == 0) cout << "Error: Division by zero!\n";
                else cout << "Result: " << a / b << endl;
                break;
        }
    }
    
    return 0;
}