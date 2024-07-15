#include <iostream>
#include <string>

using namespace std;

class Book 
{
private:
    string title;
    string author;
    string ISBN;
    bool available;
    bool checkedOut;
    int daysCheckedOut;

public:
    Book() : title(""), author(""), ISBN(""), available(true), checkedOut(false), daysCheckedOut(0) {}

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), available(true), checkedOut(false), daysCheckedOut(0) {}

    string getTitle() const
	{
        return title;
    }

    string getAuthor() const 
	{
        return author;
    }

    string getISBN() const
	{
        return ISBN;
    }

    bool isAvailable() const 
	{
        return available;
    }

    void checkoutBook() 
	{
        if (available) 
		{
            available = false;
            checkedOut = true;
            cout << "Book checked out successfully." << endl;
        } 
		else 
		{
            cout << "Book is not available for checkout." << endl;
        }
    }

    void returnBook() 
	{
        if (checkedOut) 
		{
            checkedOut = false;
            available = true;
            cout << "Book returned successfully." << endl;
        } 
		else 
		{
            cout << "Book is not checked out." << endl;
        }
    }

    int getDaysCheckedOut() const 
	{
        return daysCheckedOut;
    }

    void setDaysCheckedOut(int days) 
	{
        daysCheckedOut = days;
    }
};

class Library 
{
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const Book& newBook) 
	{
        if (bookCount < MAX_BOOKS) 
		{
            books[bookCount++] = newBook;
        } else 
		{
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void searchBooks(const string& searchCriteria) const 
	{
        bool found = false;
        for (int i = 0; i < bookCount; ++i) 
		{
            if (books[i].getTitle() == searchCriteria || books[i].getAuthor() == searchCriteria || books[i].getISBN() == searchCriteria) {
                cout << "Book found - Title: " << books[i].getTitle() << ", Author: " << books[i].getAuthor() << ", ISBN: " << books[i].getISBN() << endl;
                found = true;
            }
        }
        if (!found) 
		{
            cout << "Book not found." << endl;
        }
    }

    void calculateFine(const Book& overdueBook) const 
	{
        int fine = overdueBook.getDaysCheckedOut() * 10; 
        cout << "Fine for overdue book is: " << fine << " Rupees." << endl;
    }

    Book* findBookByTitle(const string& title) 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            if (books[i].getTitle() == title) 
			{
                return &books[i];
            }
        }
        return NULL;
    }
};

int main()
 {
 	cout << "*********************************" << endl;
    cout << "*   Library Management System   *" << endl;
    cout << "*********************************" << endl;
    Library library;
    int choice = 0;

    while (choice != 6) 
	{
        cout << "\nLibrary Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Books" << endl;
        cout << "3. Checkout Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Calculate Fine" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin

        if (choice == 1) 
		{
            string title, author, ISBN;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book ISBN: ";
            getline(cin, ISBN);
            library.addBook(Book(title, author, ISBN));
        } 
        else if (choice == 2) 
		{
            string searchCriteria;
            cout << "Enter title, author, or ISBN to search: ";
            getline(cin, searchCriteria);
            library.searchBooks(searchCriteria);
        } 
        else if (choice == 3) 
		{
            string title;
            cout << "Enter the title of the book to checkout: ";
            getline(cin, title);
            Book* book = library.findBookByTitle(title);
            if (book) 
			{
                book->checkoutBook();
            } 
			else 
			{
                cout << "Book not found." << endl;
            }
        } 
        else if (choice == 4) 
		{
            string title;
            cout << "Enter the title of the book to return: ";
            getline(cin, title);
            Book* book = library.findBookByTitle(title);
            if (book) 
			{
                book->returnBook();
            } 
			else 
			{
                cout << "Book not found." << endl;
            }
        } 
        else if (choice == 5) 
		{
            string title;
            cout << "Enter the title of the overdue book: ";
            getline(cin, title);
            Book* book = library.findBookByTitle(title);
            if (book) 
			{
                int days;
                cout << "Enter the number of days overdue: ";
                cin >> days;
                cin.ignore(); // To consume the newline character left by cin
                book->setDaysCheckedOut(days);
                library.calculateFine(*book);
            } 
			else {
                cout << "Book not found." << endl;
            }
        } 
        else if (choice == 6) {
            cout << "Exiting..." << endl;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

}




