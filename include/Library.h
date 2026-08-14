#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    void addMember(Member member) {
        members.push_back(member);
        cout << "Member added successfully.\n";
    }

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

    void saveBooks() const {
        ofstream file("data/books.txt");

        if (!file) {
            cout << "Error: Could not save books.\n";
            return;
        }

        for (const Book& book : books) {
            file << book.getId() << "|"
                 << book.getTitle() << "|"
                 << book.getAuthor() << "|"
                 << book.isAvailable() << "\n";
        }

        file.close();
    }

    void loadBooks() {
        ifstream file("data/books.txt");

        if (!file) {
            return;
        }

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string idStr, title, author, availableStr;

            getline(ss, idStr, '|');
            getline(ss, title, '|');
            getline(ss, author, '|');
            getline(ss, availableStr, '|');

            if (idStr.empty()) {
                continue;
            }

            int id = stoi(idStr);
            bool available = (availableStr == "1");

            Book book(id, title, author);

            if (!available) {
                book.issueBook();
            }

            books.push_back(book);
        }

        file.close();
    }

    void saveMembers() const {
        ofstream file("data/members.txt");

        if (!file) {
            cout << "Error: Could not save members.\n";
            return;
        }

        for (const Member& member : members) {
            file << member.getMemberId()
                 << "|"
                 << member.getName()
                 << "\n";
        }

        file.close();
    }

    void loadMembers() {
        ifstream file("data/members.txt");

        if (!file) {
            return;
        }

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string idStr;
            string name;

            getline(ss, idStr, '|');
            getline(ss, name, '|');

            if (idStr.empty()) {
                continue;
            }

            int id = stoi(idStr);

            members.push_back(Member(id, name));
        }

        file.close();
    }

    void saveData() const {
        saveBooks();
        saveMembers();
    }

    void loadData() {
        loadBooks();
        loadMembers();
    }
};

#endif
