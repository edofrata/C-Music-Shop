#include "music_shop.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Database::user()
{
    // int choice;
    int action;

    // cout << "Are you an Employee or Customer?" << '\n'
    //      << " Employee --> 0" << '\n'
    //      << " Customer --> 1" << endl;

    // cin >> choice;

    // if (choice == 1)
    // {

    // cout << "Your are a Customer,  What would you like to buy?" << endl;
    // sell_item();
    // }
    // else if (choice == 0)
    // {

    // cout << "You are an Employee" << endl;
    cout << '\n'
         << "Please Select the action you would like to do" << '\n'
         << " Restock Product -----> 0 " << '\n'
         << " Update Stock Level --> 1 " << '\n'
         << " Sell Item -----------> 2 " << '\n'
         << " Sale Report ---------> 3 " << '\n'
         << '\n'
         << " Exit ----------------> 4" << '\n'
         << " Select your choice: ";

    cin >> action;

    switch (action)
    {
    case 0:
        restock_product();
        break;

    case 1:
        update_stock();
        break;

    case 2:
        sell_item();
        break;
    case 3:
        sale_report();
        break;

    case 4:
        exit(1);
        break;
    default:
        if (!isdigit(action))
        {
            cout << "Wrong format! Please try again" << endl;
            user();
            break;
        }
        else
        {
            cout << "Wrong format! Please try again" << endl;
            user();
            break;
        }
    }
}
// else
// {

//     cout << "Wrong format, Try again" << endl;
//     user();
// }
// }

// RESTOCK PRODUCT METHOD
void Database::restock_product()
{
    // Cd_stock cd;
    // Dvd_stock dvd;
    // Magazine_stock magazine;
    // Book_stock book;

    int choice;
    int new_total;

   // int *ptr = &cd.stock;

    vector<int> stocks;
    // declaring the object for fstream

    ofstream new_stock;

    reader("STOCK");

    cout << "What Product would you like to restock? " << '\n'
         << " CDs --------> 0 " << '\n'
         << " DVDs -------> 1 " << '\n'
         << " Magazines --> 2 " << '\n'
         << " Books ------> 3 " << '\n'
         << "Please Select the product: ";

    cin >> choice;

    switch (choice)
    {

        // RESTOCKING THE VALUE OF THE CDS
    case 0:
        cout << '\n'
             << "The value is: " << cd_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

       cd_stock = cd_stock + new_total;
        total_products += new_total;
        // save the value back to the file
        writer();

        cout << "The item has been restocked, "
             << cd_stock << " "
             << "are the CDs available" << endl;

        after_action();
        break;

        // RESTOCKING THE VALUE OF THE DVDS
    case 1:
        cout << '\n'
             << "The value is: " << dvd_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        dvd_stock += new_total;
        total_products += new_total;
        writer();

        cout << "The item has been restocked, "
             << dvd_stock << " "
             << "are the DVDs available" << endl;

        after_action();
        break;

        // RESTOCKING THE VALUE OF THE MAGAZINES
    case 2:
        cout << '\n'
             << "The value is: " << magazine_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        magazine_stock += new_total;
        total_products += new_total;
        writer();

        cout << "The item has been restocked, "
             << magazine_stock << " "
             << "are the magazines available" << endl;

        after_action();
        break;

        // RESTOCKING THE VALUE OF THE BOOKS
    case 3:
        cout << '\n'
             << " The value is: " << book_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        book_stock += new_total;
        total_products += new_total;
        writer();

        cout << "The item has been restocked, "
             << book_stock << " "
             << "are the books available" << endl;

        after_action();
        break;

    default:
        cout << "Wrong format! Please Try Again" << endl;
        restock_product();
        break;
    }
}

void Database::sell_item()
{

    // Cd_stock cd;
    // Dvd_stock dvd;
    // Magazine_stock magazine;
    // Book_stock book;

    int product_choice;

    ofstream new_stock;

    reader("PRODUCT");

    cout << '\n'
         << "What Product would you like to buy " << '\n'
         << " CDs --------> 0 " << '\n'
         << " DVDs -------> 1 " << '\n'
         << " Magazines --> 2 " << '\n'
         << " Books ------> 3 " << '\n'
         << "Please Select the product: ";

    cin >> product_choice;

    switch (product_choice)
    {

    case 0:
        selling(cd_stock);
        break;
    case 1:
        selling(dvd_stock);
        break;
    case 2:
        selling(magazine_stock);
        break;
    case 3:
        selling(book_stock);
        break;
    default:
        cout << "We do not have that product yet" << endl;
        sell_item();
        break;
    }
}

void Database::update_stock()
{
}

void Database::sale_report()
{

    ifstream sale;
    // reading the sale report file
    sale.open("sale_report.csv");

    if (!sale.fail())
    {

        cerr << "The file couldn't open";
    }
    while (sale.good())
    {
        string line;
        getline(sale, line, ',');
    }
}

// CHOICE AFTER AN ACTION HAS BEEN MADE
void Database::after_action()
{

    int choice;

    cout << '\n'
         << " Restock another product --> 0 " << '\n'
         << " Main Menu ----------------> 1 " << '\n'
         << " Exit ---------------------> 2 " << '\n'
         << "Select your choice: ";

    cin >> choice;
    if (choice == 0)
        restock_product();
    else if (choice == 1)
        user();
    else if (choice == 2)
        exit(1);
    else
        cout << "Wrong format, Try again!";
    after_action();
}

// FILE READER AND CHOICE MENU
void Database::reader(std::string first)
{
    // Cd_stock cd;
    // Dvd_stock dvd;
    // Magazine_stock magazine;
    // Book_stock book;
    ifstream stock;

    stock.open("database_files/database.txt");
    string name_stock;
    int amount;
    if (stock.fail())
    {
        cerr << "Error occurred" << endl;
        exit(1);
    }

    int i = 0;
    while (stock >> name_stock >> amount)
    {

        cout << " " << name_stock << amount << endl;

        switch (i)
        {

        case 0:
            total_products = amount;
            break;

        case 1:
            cd_stock = amount;
            break;

        case 2:
            dvd_stock = amount;
            break;

        case 3:
            magazine_stock = amount;
            break;

        case 4:
            book_stock = amount;
            break;

        default:
            cout << " TOO MANY VARIABLES" << endl;
            break;
        }

        i++;
    }

    // stock >> cd_stock >> dvd_stock >> magazine_stock >> book_stock;

    // cout << '\n'
    //      << first << " AVAILABLE " << endl;
    // cout << "--------------------------------" << endl;

    // cout << " CD_stock :      " << cd_stock << endl;
    // cout << "--------------------------------" << endl;

    // cout << " DVD_stock:      " << dvd_stock << endl;
    // cout << "--------------------------------" << endl;

    // cout << " Magazine_stock: " << magazine_stock << endl;
    // cout << "--------------------------------" << endl;

    // cout << " Book_stock:     " << book_stock << endl;
    // cout << "--------------------------------" << endl;
}

void Database::writer()
{

    // Cd_stock cd;
    // Dvd_stock dvd;
    // Magazine_stock magazine;
    // Book_stock book;
    ofstream writer("database_files/database.txt");

    if (!writer.is_open())
    {
        cerr << "Error occurred" << endl;
        exit(1);
    }

    writer << "Total_Products: " << total_products << endl;
    writer << "CDs: " << cd_stock << endl;
    writer << "DVDs: " << dvd_stock << endl;
    writer << "Magazines: " << magazine_stock << endl;
    writer << "Books: " << book_stock << endl;
}

// SELLING ITEM METHOD
void Database::selling(int& product)
{

    int product_amount;
    int yes_or_no;

    cout << "Available: " << product << '\n'
         << "Please insert how many items you would like to purchase: " << endl;

    cin >> product_amount;

    if (product_amount > product)
    {

        cout << "I am sorry but we do not have that many at the moment" << endl;
        sell_item();
    }
    else
    {

        product -= product_amount;
        total_products -= product_amount;
        writer();
        cout << "Would you like to buy something else? " << '\n'
             << " Yes --> 0" << '\n'
             << "  No --> 1" << '\n'
             << " Type your choice: " << endl;

        cin >> yes_or_no;

        switch (yes_or_no)
        {

        case 0:
            sell_item();
            break;
        case 1:
            cout << "Thank You for buying from us!";
            user();
            break;
        }
    }
}
// new_stock.open("database_files/database.txt");
// stocks.push_back(*ptr);
// stocks.push_back(dvd_stock);
// stocks.push_back(magazine_stock);
// stocks.push_back(book_stock);

// for (int stock : stocks)
// {
//     new_stock << stock << endl;
// }