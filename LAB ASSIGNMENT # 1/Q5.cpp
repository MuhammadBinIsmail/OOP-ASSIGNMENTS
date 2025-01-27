#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    string movie_name;
    float adult_ticket_price, child_ticket_price, donationPercent;
    int adult_tickets_sold, child_tickets_sold;
    cout << "Enter the movie name: ";
    getline(cin, movie_name);
    cout << "Enter the price of adult ticket: ";
    cin >> adult_ticket_price;
    cout << "Enter the price of child ticket: ";
    cin >> child_ticket_price;
    cout << "Enter the number of adult tickets: ";
    cin >> adult_tickets_sold;
    cout << "Enter the number of child tickets: ";
    cin >> child_tickets_sold;
    cout << "Enter the percentage of the gross amount donated: ";
    cin >> donationPercent;
    float gross_amount = (adult_tickets_sold * adult_ticket_price) + (child_tickets_sold * child_ticket_price);
    float amountDonated = (donationPercent / 100) * gross_amount;
    float netSale = gross_amount - amountDonated;

    cout << fixed << setprecision(2);
    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << left << setw(40) << "Movie name:" << movie_name << endl;
    cout << left << setw(40) << "Number of tickets Sold:" << right << setw(10) << (adult_tickets_sold + child_tickets_sold) << endl;
    cout << left << setw(40) << "gross Amount:"  << right << setw(10) << "$" << gross_amount << endl;
    cout << left << setw(40) << "Percentage of Gross Amount Donated:" << right << setw(10) << donationPercent << "%" << endl;
    cout << left << setw(40) << "amount Donated:" << right << setw(10) << "$" << amountDonated << endl;
    cout << left << setw(40) << "Net Sale:" << right << setw(10) << "$" << netSale << endl;
    return 0;
}
