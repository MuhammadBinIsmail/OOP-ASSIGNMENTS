#include <iostream>
#include <string>
using namespace std;
class Invoice
{
private:
    string part_number;
    string part_description;
    int quantity;
    double price_per_item;

public:
    Invoice(string pNumber, string pDescription, int qty, double price)
        : part_number(pNumber), part_description(pDescription), quantity(qty), price_per_item(price)
    {
        if (quantity < 0)
            quantity = 0;
        if (price_per_item < 0)
            price_per_item = 0.0;
    }
    double get_invoice_amount() const
    {
        return quantity * price_per_item;
    }
    void display_invoice() const
    {
        cout << "Part Number: " << part_number << endl;
        cout << "Part Description: " << part_description << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << price_per_item << endl;
        cout << "Total Invoice Amount: " << get_invoice_amount() << endl;
    }
};
int main()
{
    string part_number, part_description;
    int quantity;
    double price_per_item;
    cout << "Enter Part Number: ";
    cin >> part_number;
    cin.ignore();
    cout << "Enter Part Description: ";
    getline(cin, part_description);
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Price per Item: ";
    cin >> price_per_item;
    Invoice myInvoice(part_number, part_description, quantity, price_per_item);
    cout << "\nInvoice Details:\n";
    myInvoice.display_invoice();
    return 0;
}
