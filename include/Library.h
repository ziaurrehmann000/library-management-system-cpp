#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <iostream>
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add a new book
    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    // Add a new member
    void addMember(Member member) {
        members.push_back(member);
        cout << "Member added successfully.\n";
    }

    // Display all books
    void displayBooks() const {
        cout << "\n========== BOOK LIST ==========\n";

        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        for (const Book& book : books) {
            cout << "ID: " << book.getId()
                 << " | Title: " << book.getTitle()
                 << " | Author: " << book.getAuthor()
                 << " | Status: "
                 << (book.isAvailable() ? "Available" : "Issued")
                 << endl;
        }
    }

    // Search for a book
    void searchBook(int id) const {
        for (const Book& book : books) {

            if (book.getId() == id) {

                cout << "\n========== BOOK FOUND ==========\n";
                cout << "ID: " << book.getId() << endl;
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "Status: "
                     << (book.isAvailable() ? "Available" : "Issued")
                     << endl;

                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Issue a book
    void issueBook(int id) {

        for (Book& book : books) {

            if (book.getId() == id) {

                if (!book.isAvailable()) {
                    cout << "Book is already issued.\n";
                    return;
                }

                book.issueBook();

                cout << "Book issued successfully.\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Return a book
    void returnBook(int id) {

        for (Book& book : books) {

            if (book.getId() == id) {

                if (book.isAvailable()) {
                    cout << "Book is already available.\n";
                    return;
                }

                book.returnBook();

                cout << "Book returned successfully.\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Display all members
    void displayMembers() const {

        cout << "\n========== MEMBER LIST ==========\n";

        if (members.empty()) {
            cout << "No members registered.\n";
            return;
        }

        for (const Member& member : members) {

            cout << "Member ID: "
                 << member.getMemberId()
                 << " | Name: "
                 << member.getName()
                 << endl;
        }
    }

};

#endif
