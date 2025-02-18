#include <iostream>
#include <string>
using namespace std;
class MenuItem
{
public:
    string name;
    string type;
    double price;
    MenuItem(string name, string type, double price)
        : name(name), type(type), price(price) {}
};

class CoffeeShop
{
private:
    string name;
    MenuItem *menu;
    int menuSize;
    string *orders;
    int orders_capacity;
    int orders_count;
public:
    CoffeeShop(string name, MenuItem *menu, int menuSize)
        : name(name), menu(menu), menuSize(menuSize), orders_capacity(100), orders_count(0)
    {
        orders = new string[orders_capacity];
    }

    ~CoffeeShop()
    {
        delete[] orders;
    }
    string addOrder(string item_name)
    {
        for (int i = 0; i < menuSize; i++)
        {
            if (menu[i].name == item_name)
            {
                if (orders_count < orders_capacity)
                {
                    orders[orders_count++] = item_name;
                    return item_name + " added to orders.";
                }
                else
                {
                    return "Order capacity reached.";
                }
            }
        }
        return "This item is currently unavailable.";
    }
    string fulfillOrder()
    {
        if (orders_count > 0)
        {
            string item = orders[0];
            for (int i = 1; i < orders_count; i++)
            {
                orders[i - 1] = orders[i];
            }
            orders_count--;
            return "The " + item + " is ready.";
        }
        else
        {
            return "All orders have been fulfilled.";
        }
    }
    void listOrders()
    {
        if (orders_count == 0)
        {
            cout << "No orders placed yet." << endl;
        }
        else
        {
            cout << "Current orders: ";
            for (int i = 0; i < orders_count; i++)
            {
                cout << orders[i] << " ";
            }
            cout << endl;
        }
    }
    double dueAmount()
    {
        double total = 0.0;
        for (int i = 0; i < orders_count; i++)
        {
            for (int j = 0; j < menuSize; j++)
            {
                if (menu[j].name == orders[i])
                {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }
    string cheapestItem()
    {
        if (menuSize == 0)
        {
            return "";
        }
        MenuItem *cheapest = &menu[0];
        for (int i = 1; i < menuSize; i++)
        {
            if (menu[i].price < cheapest->price)
            {
                cheapest = &menu[i];
            }
        }
        return cheapest->name;
    }
    void drinksOnly()
    {
        cout << "Drinks: ";
        for (int i = 0; i < menuSize; i++)
        {
            if (menu[i].type == "drink")
            {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
    void foodOnly()
    {
        cout << "Foods: ";
        for (int i = 0; i < menuSize; i++)
        {
            if (menu[i].type == "food")
            {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    MenuItem menu[] = {
        MenuItem("Black Coffee", "drink", 3.50),
        MenuItem("Cold Coffee", "drink", 4.00),
        MenuItem("Burger", "food", 5.50),
        MenuItem("Sandwich", "food", 5.00)};
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    CoffeeShop shop("Java Junction", menu, menuSize);
    while (true)
    {
        cout << "Enter the item you want to order (or type 'exit' to finish): ";
        string item_name;
        getline(cin, item_name);

        if (item_name == "exit")
        {
            break;
        }
        string result = shop.addOrder(item_name);
        cout << result << endl;
    }
    shop.listOrders();
    cout << "Total due amount: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    shop.drinksOnly();
    shop.foodOnly();
    return 0;
}