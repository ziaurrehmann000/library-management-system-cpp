#include <iostream>
#include "../include/Library.h"

using namespace std;

int main() {

    Library library;

    // Sample books
    library.addBook(Book(1, "C++ Programming", "Bjarne Stroustrup"));
    library.addBook(Book(2, "Data Structures", "Mark Allen Weiss"));
    library.addBook(Book(3, "Database Systems", "Raghu Ramakrishnan"));

    // Sample member
    library.addMember(Member(101, "Zia Ur Rehman"));

    int choice;

    do {
        cout << "\n=================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Search Book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            library.displayBooks();
            break;

        case 2: {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;

            library.searchBook(id);
            break;
        }

        case 3:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
