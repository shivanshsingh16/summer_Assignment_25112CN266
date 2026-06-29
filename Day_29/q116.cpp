#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

int main(){
    vector<Product> inventory;
    int choice;
    
    while(true){
        cout << "\n=== Inventory Management ===" << endl;
        cout << "1. Add product\n2. Display inventory\n3. Search product\n4. Update quantity\n5. Remove product\n6. Total value\n7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 7) break;
        
        switch(choice){
            case 1:
                {
                    Product p;
                    cout << "Enter product name: ";
                    cin.ignore();
                    getline(cin, p.name);
                    cout << "Enter price: ";
                    cin >> p.price;
                    cout << "Enter quantity: ";
                    cin >> p.quantity;
                    inventory.push_back(p);
                    cout << "Product added!\n";
                }
                break;
                
            case 2:
                if(inventory.empty()){
                    cout << "Inventory is empty!\n";
                } else {
                    cout << "\nProducts in Inventory:\n";
                    for(int i = 0; i < inventory.size(); i++){
                        cout << i+1 << ". " << inventory[i].name << " - Price: " << inventory[i].price 
                             << ", Quantity: " << inventory[i].quantity << endl;
                    }
                }
                break;
                
            case 3:
                {
                    string name;
                    cout << "Enter product name: ";
                    cin.ignore();
                    getline(cin, name);
                    bool found = false;
                    for(int i = 0; i < inventory.size(); i++){
                        if(inventory[i].name == name){
                            cout << "Product: " << inventory[i].name << endl;
                            cout << "Price: " << inventory[i].price << endl;
                            cout << "Quantity: " << inventory[i].quantity << endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found) cout << "Product not found!\n";
                }
                break;
                
            case 4:
                {
                    string name;
                    int qty;
                    cout << "Enter product name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new quantity: ";
                    cin >> qty;
                    bool found = false;
                    for(int i = 0; i < inventory.size(); i++){
                        if(inventory[i].name == name){
                            inventory[i].quantity = qty;
                            cout << "Quantity updated!\n";
                            found = true;
                            break;
                        }
                    }
                    if(!found) cout << "Product not found!\n";
                }
                break;
                
            case 5:
                {
                    string name;
                    cout << "Enter product name to remove: ";
                    cin.ignore();
                    getline(cin, name);
                    bool found = false;
                    for(int i = 0; i < inventory.size(); i++){
                        if(inventory[i].name == name){
                            inventory.erase(inventory.begin() + i);
                            cout << "Product removed!\n";
                            found = true;
                            break;
                        }
                    }
                    if(!found) cout << "Product not found!\n";
                }
                break;
                
            case 6:
                {
                    double total = 0;
                    for(int i = 0; i < inventory.size(); i++){
                        total += inventory[i].price * inventory[i].quantity;
                    }
                    cout << "Total Inventory Value: " << total << endl;
                }
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}