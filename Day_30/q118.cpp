#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Book {
    int bookId;
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

int main() {
    vector<Book> library;
    int choice;

    while(true) {
        cout << "\n=== Mini Library System ===\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. View Available Books\n";
        cout << "7. Delete Book\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Book b;
            cout << "Enter Book ID: ";
            cin >> b.bookId;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, b.title);
            cout << "Enter Author: ";
            getline(cin, b.author);
            cout << "Enter ISBN: ";
            cin >> b.isbn;
            b.isAvailable = true;
            library.push_back(b);
            cout << "Book added successfully!\n";
        }
        else if(choice == 2) {
            if(library.empty()) {
                cout << "No books in library!\n";
            }
            else {
                cout << "\n--- All Books ---\n";
                for(int i = 0; i < library.size(); i++) {
                    cout << "Book ID: " << library[i].bookId << "\n";
                    cout << "Title: " << library[i].title << "\n";
                    cout << "Author: " << library[i].author << "\n";
                    cout << "ISBN: " << library[i].isbn << "\n";
                    cout << "Status: " << (library[i].isAvailable ? "Available" : "Issued") << "\n";
                    cout << "---\n";
                }
            }
        }
        else if(choice == 3) {
            string title;
            cout << "Enter title to search: ";
            getline(cin, title);
            bool found = false;
            for(int i = 0; i < library.size(); i++) {
                if(library[i].title == title) {
                    cout << "\nBook Found!\n";
                    cout << "Book ID: " << library[i].bookId << "\n";
                    cout << "Author: " << library[i].author << "\n";
                    cout << "ISBN: " << library[i].isbn << "\n";
                    cout << "Status: " << (library[i].isAvailable ? "Available" : "Issued") << "\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Book not found!\n";
            }
        }
        else if(choice == 4) {
            int bookId;
            cout << "Enter Book ID to issue: ";
            cin >> bookId;
            bool found = false;
            for(int i = 0; i < library.size(); i++) {
                if(library[i].bookId == bookId) {
                    if(library[i].isAvailable) {
                        library[i].isAvailable = false;
                        cout << "Book issued successfully!\n";
                    }
                    else {
                        cout << "Book is already issued!\n";
                    }
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Book not found!\n";
            }
        }
        else if(choice == 5) {
            int bookId;
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            bool found = false;
            for(int i = 0; i < library.size(); i++) {
                if(library[i].bookId == bookId) {
                    if(!library[i].isAvailable) {
                        library[i].isAvailable = true;
                        cout << "Book returned successfully!\n";
                    }
                    else {
                        cout << "Book was not issued!\n";
                    }
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Book not found!\n";
            }
        }
        else if(choice == 6) {
            bool found = false;
            cout << "\n--- Available Books ---\n";
            for(int i = 0; i < library.size(); i++) {
                if(library[i].isAvailable) {
                    cout << "Book ID: " << library[i].bookId << "\n";
                    cout << "Title: " << library[i].title << "\n";
                    cout << "Author: " << library[i].author << "\n";
                    cout << "---\n";
                    found = true;
                }
            }
            if(!found) {
                cout << "No books available!\n";
            }
        }
        else if(choice == 7) {
            int bookId;
            cout << "Enter Book ID to delete: ";
            cin >> bookId;
            bool found = false;
            for(int i = 0; i < library.size(); i++) {
                if(library[i].bookId == bookId) {
                    library.erase(library.begin() + i);
                    cout << "Book deleted successfully!\n";
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Book not found!\n";
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