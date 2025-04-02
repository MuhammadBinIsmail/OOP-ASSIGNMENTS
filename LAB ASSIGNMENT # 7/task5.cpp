#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media
{
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool checkedOut;

public:
    Media(string t, string pd, string id, string pub)
        : title(t), publicationDate(pd), uniqueID(id), publisher(pub), checkedOut(false) {}

    virtual void displayInfo()
    {
        cout << "\nTitle: " << title
             << "\nPublication Date: " << publicationDate
             << "\nID: " << uniqueID
             << "\nPublisher: " << publisher
             << "\nStatus: " << (checkedOut ? "Checked Out" : "Available");
    }

    void checkOut()
    {
        if (checkedOut)
        {
            cout << "\nThis item is already checked out!";
        }
        else
        {
            checkedOut = true;
            cout << "\nItem successfully checked out.";
        }
    }

    void returnItem()
    {
        if (!checkedOut)
        {
            cout << "\nThis item wasn't checked out!";
        }
        else
        {
            checkedOut = false;
            cout << "\nItem successfully returned.";
        }
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
    string getID() const { return uniqueID; }
    virtual string getCreator() const { return ""; }
};

class Book : public Media
{
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pd, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pd, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "\nType: Book"
             << "\nAuthor: " << author
             << "\nISBN: " << ISBN
             << "\nPages: " << numberOfPages;
    }

    string getCreator() const override { return author; }
};

class DVD : public Media
{
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pd, string id, string pub, string dir, int dur, string rat)
        : Media(t, pd, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "\nType: DVD"
             << "\nDirector: " << director
             << "\nDuration: " << duration << " minutes"
             << "\nRating: " << rating;
    }

    string getCreator() const override { return director; }
};

class CD : public Media
{
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pd, string id, string pub, string art, int tracks, string gen)
        : Media(t, pd, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "\nType: CD"
             << "\nArtist: " << artist
             << "\nTracks: " << numberOfTracks
             << "\nGenre: " << genre;
    }

    string getCreator() const override { return artist; }
};

class Library
{
    vector<Media *> collection;

public:
    void addMedia(Media *item)
    {
        collection.push_back(item);
    }

    void displayAll()
    {
        cout << "\n\n    LIBRARY COLLECTION     ";
        for (const auto &item : collection)
        {
            item->displayInfo();
            cout << "\n";
        }
    }

    void searchByTitle(const string &title)
    {
        cout << "\nSearch Results for Title: " << title;
        bool found = false;
        for (const auto &item : collection)
        {
            if (item->getTitle().find(title) != string::npos)
            {
                item->displayInfo();
                cout << "\n";
                found = true;
            }
        }
        if (!found)
            cout << "\nNo items found with that title.";
    }

    void searchByCreator(const string &creator)
    {
        cout << "\nSearch Results for Creator: " << creator;
        bool found = false;
        for (const auto &item : collection)
        {
            if (item->getCreator().find(creator) != string::npos)
            {
                item->displayInfo();
                cout << "\n";
                found = true;
            }
        }
        if (!found)
            cout << "\nNo items found with that creator.";
    }

    void searchByYear(const string &year)
    {
        cout << "\nSearch Results for Year: " << year;
        bool found = false;
        for (const auto &item : collection)
        {
            if (item->getPublicationDate().find(year) != string::npos)
            {
                item->displayInfo();
                cout << "\n";
                found = true;
            }
        }
        if (!found)
            cout << "\nNo items found from that year.";
    }

    Media *findById(const string &id)
    {
        for (const auto &item : collection)
        {
            if (item->getID() == id)
                return item;
        }
        return nullptr;
    }
};

int main()
{
    Library library;
    library.addMedia(new Book(
        "The Sole Spokesman", "1985-01-01", "B102", "Cambridge University Press",
        "Ayesha Jalal", "9780521262714", 334));

    library.addMedia(new DVD(
        "Khuda Kay Liye", "2007-07-20", "D101", "Geo Films",
        "Shoaib Mansoor", 168, "PG-13"));

    library.addMedia(new CD(
        "Coke Studio Season 14", "2021-08-27", "C101", "Coke Studio Pakistan",
        "Various Artists", 8, "Fusion"));

    int choice;
    do
    {
        cout << "\n\n=== PAKISTANI LIBRARY MANAGEMENT SYSTEM ==="
             << "\n1. Display All Items"
             << "\n2. Search by Title"
             << "\n3. Search by Creator (Author/Director/Artist)"
             << "\n4. Search by Year"
             << "\n5. Check Out Item"
             << "\n6. Return Item"
             << "\n0. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        string searchTerm;
        string itemId;
        Media *item;
        switch (choice)
        {
        case 1:
            library.displayAll();
            break;
        case 2:
            cout << "Enter title to search: ";
            getline(cin, searchTerm);
            library.searchByTitle(searchTerm);
            break;
        case 3:
            cout << "Enter creator to search: ";
            getline(cin, searchTerm);
            library.searchByCreator(searchTerm);
            break;
        case 4:
            cout << "Enter year to search: ";
            getline(cin, searchTerm);
            library.searchByYear(searchTerm);
            break;
        case 5:
            cout << "Enter item ID to check out: ";
            cin >> itemId;
            item = library.findById(itemId);
            if (item)
            {
                item->checkOut();
            }
            else
            {
                cout << "Item not found!";
            }
            break;
        case 6:
            cout << "Enter item ID to return: ";
            cin >> itemId;
            item = library.findById(itemId);
            if (item)
            {
                item->returnItem();
            }
            else
            {
                cout << "Item not found!";
            }
            break;
        }
    } while (choice != 0);

    return 0;
}