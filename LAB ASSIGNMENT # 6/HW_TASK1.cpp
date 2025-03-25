#include <iostream>
#include <string>
using namespace std;
class Books{
    protected:
    string bookgenere;
    public: 
    Books (string g) : bookgenere(g) {}
    virtual void displaydetails() {
        cout << "The genere of the book is: " << bookgenere << endl;
    }
};
class InterestingBook : public Books {
    private:
    string title;
    string author;
    public:
    InterestingBook(string t, string a) : Books("Interesting"), title(t), author(a) {}
    void displaydetails() override {
        Books :: displaydetails();
        cout << "The title of the book is: " << title << endl;
        cout << "The author of the book is: " << author << endl;
    }
};
class FictionBook : public Books
{
private:
    string title;
    string author;

public:
    FictionBook(string t, string a) : Books("Fiction"), title(t), author(a) {}
    void displaydetails() override
    {
        Books ::displaydetails();
        cout << "The title of the book is: " << title << endl;
        cout << "The author of the book is: " << author << endl;
    }
};

int main()
{
    InterestingBook b1("Tom Sayer", "Henry");
    FictionBook b2("Black Beauty", "Dickens");
    b1.displaydetails();
    b2.displaydetails();
    return 0;
}