#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book
{
private:
    string title;
    string author;
    string publisher;
    double price;
    int stock;
public:
    Book(string t, string a, string p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}
    bool is_available(string t, string a) const
    {
        return (title == t && author == a);
    }
    void display_book() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }
    void sell_book(int quantity)
    {
        if (quantity <= stock)
        {
            cout << "Total cost: " << price * quantity << endl;
            stock -= quantity;
        }
        else
        {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main()
{
    vector<Book> inventory = {
        Book("Oliver Twist", "Charles Dickens", "Peak", 57.99, 5),
        Book("A tale of Two Citiess", "Charles Dickens", "Peak", 120.50, 3),
        Book("Harry Potter", "JK Rollings", "Peak", 79.00, 4)};

    string search_title, search_author;
    cout << "Enter book title: ";
    getline(cin, search_title);
    cout << "Enter author name: ";
    getline(cin, search_author);
    bool found = false;
    for (Book &book : inventory)
    {
        if (book.is_available(search_title, search_author))
        {
            found = true;
            book.display_book();
            int quantity;
            cout << "Enter number of copies required: ";
            cin >> quantity;
            book.sell_book(quantity);
            break;
        }
    }
    if (!found)
    {
        cout << "Book not available." << endl;
    }
    return 0;
}
