/*
Name: Andrew Zelinka
Due Date: August 30, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
Description: This program computes an invoice derived from user input.
    The user will include the name of an item, its cost in USD, and the sales tax rate as a percentage (minus the percentage sign)
    It will then output a properly formatted and easily interpreted invoice for the user.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main1_2(){
    string product;
    float unitPrice, pretaxPrice, taxRate, tax, totalPrice;
    int num, w = 80;

    cout << "Enter a product description: ";
    getline(cin, product);
    cout << "Enter the product list price: $";
    cin >> unitPrice;
    cout << "How many units to purchase? ";
    cin >> num;
    cout << "What is the sales tax rate? (no % sign needed) ";
    cin >> taxRate;

    pretaxPrice = unitPrice * num;
    tax = taxRate/100 * pretaxPrice;
    totalPrice = pretaxPrice + tax;

    cout << endl << setfill('-')<< setw(w/2+4) << "INVOICE" << setw(w/2-4) << "-" << endl;
    cout << "Product:         " << product << endl;
    cout << fixed << setprecision(2) << setfill(' ') << "Unit Price:      $" << setw(w/2-19) << unitPrice << " | Units Purchased: " << num << endl;
    cout << setfill('-') << setw(w) << "-" << setfill(' ') << endl;
    cout << "Purchase Amount: $" << setw(w/2-19) << pretaxPrice << endl;
    cout << "Sales Tax:       $" << setw(w/2-19) << tax << endl;
    cout << setfill('-') << setw(w/2) << "-" << setfill(' ') << endl;
    cout << "Total Price:     $" << setw(w/2-19) << totalPrice << endl;
    cout << setfill('-')<< setw(w/2+2) << "END" << setw(w/2-2) << "-" << endl;
    return 0;
}