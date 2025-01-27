/*Write a program that prompts the user to enter the weight of a person in kilograms and outputs the
equivalent weight in pounds. Output both the weights rounded to two decimal places.*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float weight, pounds;
    cout << "Enter the weight in kilograms: ";
    cin >> weight;
    pounds = weight * 2.2;
    cout << fixed << setprecision(2);
    cout << "The weight in kilograms is: "<< weight <<endl;
    cout << "The weight in pounds is: "<< pounds <<endl;
}