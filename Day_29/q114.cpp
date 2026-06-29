#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr;
    int choice, num;
    
    while(true){
        cout << "\n=== Array Operations ===" << endl;
        cout << "1. Add element\n2. Display array\n3. Search element\n4. Delete element\n5. Sort array\n6. Find max\n7. Find min\n8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 8) break;
        
        switch(choice){
            case 1:
                cout << "Enter element: ";
                cin >> num;
                arr.push_back(num);
                cout << "Element added!\n";
                break;
                
            case 2:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                } else {
                    cout << "Array: ";
                    for(int x : arr) cout << x << " ";
                    cout << endl;
                }
                break;
                
            case 3:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                    break;
                }
                cout << "Enter element to search: ";
                cin >> num;
                {
                    auto it = find(arr.begin(), arr.end(), num);
                    if(it != arr.end()){
                        cout << "Element found at index: " << (it - arr.begin()) << endl;
                    } else {
                        cout << "Element not found!\n";
                    }
                }
                break;
                
            case 4:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                    break;
                }
                cout << "Enter element to delete: ";
                cin >> num;
                {
                    auto it = find(arr.begin(), arr.end(), num);
                    if(it != arr.end()){
                        arr.erase(it);
                        cout << "Element deleted!\n";
                    } else {
                        cout << "Element not found!\n";
                    }
                }
                break;
                
            case 5:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                    break;
                }
                sort(arr.begin(), arr.end());
                cout << "Array sorted!\n";
                break;
                
            case 6:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                    break;
                }
                cout << "Max element: " << *max_element(arr.begin(), arr.end()) << endl;
                break;
                
            case 7:
                if(arr.empty()){
                    cout << "Array is empty!\n";
                    break;
                }
                cout << "Min element: " << *min_element(arr.begin(), arr.end()) << endl;
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}