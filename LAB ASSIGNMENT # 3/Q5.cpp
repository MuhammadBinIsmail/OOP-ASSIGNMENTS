#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string book_name;
    string isbn_number;
    string author_name;
    string publisher;

public:
    Book(string book_name, string isbn_number, string author_name, string publisher)
    {
        this->book_name = book_name;
        this->isbn_number = isbn_number;
        this->author_name = author_name;
        this->publisher = publisher;
    }
    string get_book_name() 
    { 
        return this->book_name; 
    }
    string get_ISBN() 
    { 
        return this->isbn_number; 
    }
    string get_author_name() 
    { 
        return this->author_name; 
    }
    string get_publisher() 
    { 
        return this->publisher; 
    }
    string get_book_info()
    {
        return "Book Name: " + this->book_name + "\nISBN: " + this->isbn_number +
               "\nAuthor: " + this->author_name + "\nPublisher: " + this->publisher + "\n";
    }
};
int main()
{
    const int SIZE = 5;
    Book *books[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        string book_name, isbn_number, author_name, publisher;
        cout << "\nEnter details for Book " << (i + 1) << ":\n";
        cout << "Enter Book Name: ";
        cin.ignore();
        getline(cin, book_name);
        cout << "Enter ISBN: ";
        getline(cin, isbn_number);
        cout << "Enter Author Name: ";
        getline(cin, author_name);
        cout << "Enter Publisher: ";
        getline(cin, publisher);
        books[i] = new Book(book_name, isbn_number, author_name, publisher);
    }
    cout << "\nBook List:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nBook " << (i + 1) << " Details:\n";
        cout << books[i]->get_book_info();
        delete books[i];
    }
    return 0;
}
