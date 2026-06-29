#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    int choice;
    
    while(true){
        cout << "\n=== String Operations ===" << endl;
        cout << "1. Input string\n2. Display string\n3. Length\n4. Reverse\n5. Uppercase\n6. Lowercase\n7. Concatenate\n8. Search character\n9. Replace character\n10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 10) break;
        
        switch(choice){
            case 1:
                cout << "Enter string: ";
                cin.ignore();
                getline(cin, str);
                break;
                
            case 2:
                if(str.empty()) cout << "String is empty!\n";
                else cout << "String: " << str << endl;
                break;
                
            case 3:
                cout << "Length: " << str.length() << endl;
                break;
                
            case 4:
                {
                    string rev = str;
                    reverse(rev.begin(), rev.end());
                    cout << "Reversed: " << rev << endl;
                }
                break;
                
            case 5:
                {
                    string upper = str;
                    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
                    cout << "Uppercase: " << upper << endl;
                }
                break;
                
            case 6:
                {
                    string lower = str;
                    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                    cout << "Lowercase: " << lower << endl;
                }
                break;
                
            case 7:
                {
                    string s2;
                    cout << "Enter string to concatenate: ";
                    cin.ignore();
                    getline(cin, s2);
                    cout << "Result: " << str + s2 << endl;
                }
                break;
                
            case 8:
                {
                    char ch;
                    cout << "Enter character to search: ";
                    cin >> ch;
                    size_t pos = str.find(ch);
                    if(pos != string::npos){
                        cout << "Character found at position: " << pos << endl;
                    } else {
                        cout << "Character not found!\n";
                    }
                }
                break;
                
            case 9:
                {
                    char old_ch, new_ch;
                    cout << "Enter character to replace: ";
                    cin >> old_ch;
                    cout << "Enter new character: ";
                    cin >> new_ch;
                    for(int i = 0; i < str.length(); i++){
                        if(str[i] == old_ch) str[i] = new_ch;
                    }
                    cout << "String updated!\n";
                }
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}