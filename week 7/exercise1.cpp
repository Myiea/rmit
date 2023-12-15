#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    int availableCopies;
    vector<string> namesOfBorrowers;

public:
    Book(const string& bookTitle, int copies) : title(bookTitle), availableCopies(copies) {}

    bool isAvailable() const {
        return availableCopies > 0;
    }

    void borrowBook(const string& borrowerName) {
        if (isAvailable()) {
            availableCopies--;
            namesOfBorrowers.push_back(borrowerName);
            cout << "Book " << title << " borrowed by " << borrowerName << endl;
        } else {
            cout << "Sorry, book " << title << " is not available for borrowing." << endl;
        }
    }

    void returnBook(const string& borrowerName) {
        vector<string>::iterator it = find(namesOfBorrowers.begin(), namesOfBorrowers.end(), borrowerName);
        if (it != namesOfBorrowers.end()) {
            namesOfBorrowers.erase(it);
            availableCopies++;
            cout << "Book "<< title << " returned by " << borrowerName << endl;
        } else {
            cout << "Error: " << borrowerName << " did not borrow book " << title << endl;
        }
    }

    string getTitle() const {
        return title;
    }
};

class User {
private:
    string name;
    vector<Book*> borrowedBooks;

public:
    User(const string& userName) : name(userName) {}

    bool borrowBook(Book& book) {
        if (book.isAvailable()) {
            book.borrowBook(name);
            borrowedBooks.push_back(&book);
            return true;
        } else {
            cout << "Sorry, book " << book.getTitle() << " is not available for borrowing." << endl;
            return false;
        }
    }

    void returnBook(Book& book) {
        book.returnBook(name);
        vector<Book*>::iterator it = find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }
};

int main() {
    vector<Book*> books;
    books.push_back(new Book("Book 1", 3));
    books.push_back(new Book("Book 2", 1));
    books.push_back(new Book("Book 3", 2));

    User user1("User 1");
    User user2("User 2");

    user1.borrowBook(*books[0]);
    user1.borrowBook(*books[1]);
    user2.borrowBook(*books[1]);
    user2.borrowBook(*books[2]);

    user1.returnBook(*books[0]);
    user2.returnBook(*books[1]);

    for (size_t i = 0; i < books.size(); i++) {
    delete books[i];
    }

    return 0;
}
