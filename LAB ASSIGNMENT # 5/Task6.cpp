#include <iostream>
#include <vector>
using namespace std;
struct MenuItem
{
    string name;
    double price;
    string type;
};
class CoffeeShop
{
private:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders;
public:
    CoffeeShop(string shopName, vector<MenuItem> menuItems) : name(shopName), menu(menuItems) {}
    string getName() const
    {
        return name;
    }
    string addOrder(string itemName)
    {
        for (const auto &item : menu)
        {
            if (item.name == itemName)
            {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }
    string fulfillOrder()
    {
        if (!orders.empty())
        {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }
    vector<string> listOrders() const
    {
        return orders;
    }
    double dueAmount() const
    {
        double total = 0;
        for (const auto &order : orders)
        {
            for (const auto &item : menu)
            {
                if (item.name == order)
                {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }
    string cheapestItem() const
    {
        if (menu.empty())
            return "No items available";
        const MenuItem *cheapest = &menu[0];
        for (const auto &item : menu)
        {
            if (item.price < cheapest->price)
            {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }
    vector<string> drinksOnly() const
    {
        vector<string> drinks;
        for (const auto &item : menu)
        {
            if (item.type == "drink")
            {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }
    vector<string> foodOnly() const
    {
        vector<string> foods;
        for (const auto &item : menu)
        {
            if (item.type == "food")
            {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main()
{
    vector<MenuItem> menu;
    int numItems;
    cout << "Enter the number of menu items: ";
    cin >> numItems;
    cin.ignore();
    for (int i = 0; i < numItems; i++)
    {
        MenuItem item;
        cout << "Enter item name: ";
        getline(cin, item.name);
        cout << "Enter item price: ";
        cin >> item.price;
        cin.ignore();
        cout << "Enter item type (food/drink): ";
        getline(cin, item.type);
        menu.push_back(item);
    }
    CoffeeShop shop("Java Cafe", menu);
    string order;
    char moreOrders;
    do
    {
        cout << "Enter an item to order: ";
        getline(cin, order);
        cout << shop.addOrder(order) << endl;
        cout << "Do you want to order more? (y/n): ";
        cin >> moreOrders;
        cin.ignore();
    } while (moreOrders == 'y' || moreOrders == 'Y');
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks available: ";
    for (const auto &drink : drinks)
        cout << drink << " ";
    cout << endl;
    vector<string> foods = shop.foodOnly();
    cout << "Food available: ";
    for (const auto &food : foods)
        cout << food << " ";
    cout << endl;
    return 0;
}
