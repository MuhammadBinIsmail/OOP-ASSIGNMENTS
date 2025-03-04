#include <iostream>
#include <vector>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(std::string bookTitle, std::string bookAuthor, std::string bookISBN)
        : title(bookTitle), author(bookAuthor), isbn(bookISBN)
    {
        std::cout << "Book created: " << title << " (ISBN: " << isbn << ")" << std::endl;
    }
    ~Book()
    {
        std::cout << "Book destroyed: " << title << " (ISBN: " << isbn << ")" << std::endl;
    }
    std::string getISBN() const
    {
        return isbn;
    }
    std::string getTitle() const
    {
        return title;
    }
};

class Catalog
{
private:
    std::vector<Book *> books;
public:
    void addBook(Book *book)
    {
        books.push_back(book);
        std::cout << "Book added to catalog: " << book->getTitle() << std::endl;
    }
    Book *findBook(const std::string &isbn)
    {
        for (Book *book : books)
        {
            if (book->getISBN() == isbn)
            {
                return book;
            }
        }
        return nullptr;
    }
};

class Library
{
private:
    std::string name;
    Catalog catalog;           
    std::vector<Book *> books; 
public:
    Library(std::string libName) : name(libName)
    {
        std::cout << "Library created: " << name << std::endl;
    }
    ~Library()
    {
        std::cout << "Library destroyed: " << name << std::endl;
    }
    void addBook(Book *book)
    {
        books.push_back(book);
        catalog.addBook(book);
    }
    void findBookInCatalog(const std::string &isbn)
    {
        Book *book = catalog.findBook(isbn);
        if (book)
        {
            std::cout << "Book found in catalog: " << book->getTitle() << std::endl;
        }
        else
        {
            std::cout << "Book not found in catalog." << std::endl;
        }
    }
};

int main()
{
    Library myLibrary("City Library");
    Book book1("Harry Potter", "J.K Rollings", "2468");
    Book book2("A Tale of Two Cities", "Charles Dickens", "6890");
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.findBookInCatalog("12345");
    myLibrary.findBookInCatalog("99999");

    return 0;
}
