#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct Book {
    int bookId;
    char title[50];
    char author[50];
    int quantity;
    int issued;
};

vector<Book> books;

void addBook() {
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.bookId;
    
    for (auto& book : books) {
        if (book.bookId == b.bookId) {
            cout << "Book ID already exists!\n";
            return;
        }
    }
    
    cin.ignore();
    cout << "Enter Title: ";
    cin.getline(b.title, 50);
    cout << "Enter Author: ";
    cin.getline(b.author, 50);
    cout << "Enter Quantity: ";
    cin >> b.quantity;
    b.issued = 0;
    
    books.push_back(b);
    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (books.empty()) {
        cout << "No books in library.\n";
        return;
    }
    
    cout << "\n" << setw(8) << "ID" << setw(20) << "Title" << setw(20) 
         << "Author" << setw(10) << "Qty" << setw(10) << "Issued\n";
    cout << string(68, '-') << "\n";
    
    for (auto& b : books) {
        cout << setw(8) << b.bookId << setw(20) << b.title << setw(20) 
             << b.author << setw(10) << b.quantity << setw(10) << b.issued << "\n";
    }
    cout << "\n";
}

void issueBook() {
    int id, qty;
    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Quantity to Issue: ";
    cin >> qty;
    
    for (auto& b : books) {
        if (b.bookId == id) {
            if (b.quantity - b.issued >= qty) {
                b.issued += qty;
                cout << qty << " book(s) issued successfully!\n";
            } else {
                cout << "Not enough copies available!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook() {
    int id, qty;
    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Quantity to Return: ";
    cin >> qty;
    
    for (auto& b : books) {
        if (b.bookId == id) {
            if (b.issued >= qty) {
                b.issued -= qty;
                cout << qty << " book(s) returned successfully!\n";
            } else {
                cout << "Invalid return quantity!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    
    for (int i = 0; i < books.size(); i++) {
        if (books[i].bookId == id) {
            books.erase(books.begin() + i);
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

int main() {
    int choice;
    
    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: deleteBook(); break;
            case 6: cout << "Thank you!\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}