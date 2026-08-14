#include <iostream>
#include "../include/Library.h"

using namespace std;

int main() {

    Library library;

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Add Member\n";
        cout << "5. Display Members\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

        case 1: {
            int id;
            string title;
            string author;

            cout << "\nEnter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            library.addBook(Book(id, title, author));
            break;
        }

        case 2:
            library.displayBooks();
            break;

        case 3: {
            int id;

            cout << "\nEnter Book ID to search: ";
            cin >> id;

            library.searchBook(id);
            break;
        }

        case 4: {
            int id;
            string name;

            cout << "\nEnter Member ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Member Name: ";
            getline(cin, name);

            library.addMember(Member(id, name));
            break;
        }

        case 5:
            library.displayMembers();
            break;

        case 6: {
            int id;

            cout << "\nEnter Book ID to issue: ";
            cin >> id;

            library.issueBook(id);
            break;
        }

        case 7: {
            int id;

            cout << "\nEnter Book ID to return: ";
            cin >> id;

            library.returnBook(id);
            break;
        }

        case 8:
            cout << "\nThank you for using the Library Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Please enter a number from 1 to 8.\n";
        }

    } while (choice != 8);

    return 0;
}
