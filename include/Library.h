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
    void addBook(Book book) {
        books.push_back(book);
    }

    void addMember(Member member) {
        members.push_back(member);
    }

    void displayBooks() const {
        cout << "\n===== BOOK LIST =====\n";

        for (const Book& book : books) {
            cout << "ID: " << book.getId()
                 << " | Title: " << book.getTitle()
                 << " | Author: " << book.getAuthor()
                 << " | Status: "
                 << (book.isAvailable() ? "Available" : "Issued")
                 << endl;
        }
    }

    void searchBook(int id) const {
        for (const Book& book : books) {
            if (book.getId() == id) {
                cout << "\nBook Found!\n";
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
};

#endif
