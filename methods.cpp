#include "music_shop.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

Functionality func;
Cd_stock cd;
Dvd_stock dvd;
Magazine_stock magazine;
Book_stock book;

vector<string> names;
vector<double> prices;
vector<int> quantities;

void Database::user()
{
    int action;

    cout << '\n'
         << "Please Select the action you would like to do" << '\n'
         << " Restock Product -----> 0 " << '\n'
         << " Add new item --------> 1 " << '\n'
         << " Sell Item -----------> 2 " << '\n'
         << " Sale Report ---------> 3 " << '\n'
         << '\n'
         << " Exit ----------------> 4" << '\n'
         << " Select your choice: ";

    cin >> action;

    switch (action)
    {
    case 0:
        func.restock_product();
        break;

    case 1:
        func.add_item();
        break;

    case 2:
        func.sell_item();
        break;
    case 3:
        func.sale_report();
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

// RESTOCK PRODUCT METHOD
void Database::restock_product()
{

    int choice;
    int new_total;
    int code;

    // func.reader();

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
        // reads the cds file
        func.reader("database_files/CDs.txt", cd.id, cd.name, cd.price, cd.stock);
        cout << '\n'
             << "The value is: " << total_products << endl;

        do
        {
            cout << "Please insert Serial Code: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]));

        do
        {
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products);

        quantities[code] += new_total;
        total_products += new_total;
        // save the value back to the file
        func.writer("database_files/CDs.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now  " << quantities[code]
             << " are the CDs available" << endl;

        func.after_action();
        break;

        // RESTOCKING THE VALUE OF THE DVDS
    case 1:

        // reads the dvd files
        func.reader("database_files/DVDs.txt", dvd.id, dvd.name, dvd.price, dvd.stock);
        cout << '\n'
             << "The value is: " << total_products << endl;

        do
        {
            // inserting the serial code, to understand which Item to take;
            cout << "Please insert Serial Code: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]));

        do
        {
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products);

        quantities[code] += new_total;
        total_products += new_total;
        func.writer("database_files/DVDs.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now  " << quantities[code]
             << " are the DVDs available" << endl;

        func.after_action();
        break;

        // RESTOCKING THE VALUE OF THE MAGAZINES
    case 2:
        // reads the magazines file
        func.reader("database_files/Magazines.txt", magazine.id, magazine.name,
                    magazine.price, magazine.stock);
        cout << '\n'
             << "The value is: " << total_products << endl;

        do
        {

            // inserting the serial code, to understand which Item to take;
            cout << "Please insert Serial Code: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]));

        do
        {
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products);

        // restocking the product
        quantities[code] += new_total;
        total_products += new_total;
        func.writer("database_files/Magazines.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now  " << quantities[code]
             << " are the Magazines available" << endl;

        func.after_action();
        break;

        // RESTOCKING THE VALUE OF THE BOOKS
    case 3:
        // reads the books files
        func.reader("database_files/Books.txt", book.id, book.name, book.price, book.stock);
        cout << '\n'
             << " The value is: " << total_products << endl;

        do
        {
            // inserting the serial code, to understand which Item to take;
            cout << "Please insert Serial Code: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]));

        do
        {
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products);

        quantities[code] += new_total;
        total_products += new_total;
        func.writer("database_files/Books.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now  " << quantities[code]
             << " are the Books available" << endl;

        func.after_action();
        break;

    default:
        cout << "Wrong format! Please Try Again" << endl;
        restock_product();
        break;
    }
}

// Methods that adds the function
void Database::add_item()
{
    int choice;

    cout << "Where would you like to add the new item? " << '\n'
         << " CDs --------> 0 " << '\n'
         << " DVDs -------> 1 " << '\n'
         << " Magazines --> 2 " << '\n'
         << " Books ------> 3 " << '\n'
         << "Please Select the product: ";

    cin >> choice;

    switch (choice)
    {

    case 0:
        func.adding_item("database_files/CDs.txt", cd.id, cd.name, cd.price, cd.stock);
        break;
    case 1:
        func.adding_item("database_files/DVDs.txt", dvd.id, dvd.name, dvd.price, dvd.stock);
        break;

    case 2:
        func.adding_item("database_files/Magazines.txt", magazine.id, magazine.name, magazine.price, magazine.stock);
        break;
    case 3:
        func.adding_item("database_files/Books.txt", book.id, book.name, book.price, book.stock);
        break;
    default:
        cout << "Wrong format, Please Try Again: " << endl;
        add_item();
        break;
    }
}

void Database::sell_item()
{
    int product_choice;

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
        func.reader("database_files/CDs.txt", cd.id, cd.name, cd.price, cd.stock);
        func.selling(cd.stock, "database_files/CDs.txt");
        break;
    case 1:
        func.reader("database_files/DVDs.txt", dvd.id, dvd.name, dvd.price, dvd.stock);
        func.selling(dvd.stock, "database_files/DVDs.txt");
        break;
    case 2:
        func.reader("database_files/Magazines.txt", magazine.id, magazine.name, magazine.price, magazine.stock);
        func.selling(magazine.stock, "database_files/Magazines.txt");
        break;
    case 3:
        func.reader("database_files/Books.txt", book.id, book.name, book.price, book.stock);
        func.selling(book.stock, "database_files/Books.txt");
        break;
    default:
        cout << "We do not have that product yet" << endl;
        sell_item();
        break;
    }
}

void Database::sale_report()
{
}

// CHOICE AFTER AN ACTION HAS BEEN MADE
void Functionality::after_action()
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
    func.after_action();
}

// FILE READER AND CHOICE MENU
void Functionality::reader(std::string path, std::string id, std::string name, double price, int quantity)
{
    ifstream stock;
    // cleaning vectors
    //ID.clear();
    names.clear();
    prices.clear();
    quantities.clear();

    stock.open(path);
    if (stock.fail())
    {
        cerr << "Error occurred" << endl;
        exit(1);
    }

    while (stock >> name >> price >> quantity)
    {
        names.push_back(name);
        prices.push_back(price);
        quantities.push_back(quantity);
    }

    total_products = accumulate(quantities.begin(), quantities.end(), 0);

    for (int i = 0; i < names.size(); i++)
    {

        cout << "\n"
             << id << i << " "
             << names.at(i) << " "
             << "£" << prices.at(i) << " : "
             << quantities.at(i) << "\n"
             << endl;
    }
}

void Functionality::writer(std::string path)
{

    ofstream writer(path);

    if (!writer.is_open())
    {
        cerr << "Error occurred" << endl;
        exit(1);
    }

    for (int i = 0; i < names.size(); i++)
    {

        writer << names[i] << " " << prices[i] << " " << quantities[i] << endl;
    }
}

// SELLING ITEM METHOD
void Functionality::selling(int &product, std::string path)
{

    int product_chosen;
    int product_quantity;
    int yes_or_no;
    int confirm;

    do
    {
        cout << "Available: " << total_products << '\n'
             << "Please insert which item you would like to purchase: ";
        cin >> product_chosen;
    } while (!std::count(quantities.begin(), quantities.end(), quantities[product_chosen]));

    do
    {
        cout << "You have Selected " << names[product_chosen] << endl;
        cout << "Please Select how many you would like to buy: " << endl;
        cin >> product_quantity;

    } while (product_quantity > quantities[product_chosen]);

    do
    {
        cout << "You have selected " << names[product_chosen] << " and the amount is " << product_quantity
             << " \n"
             << "Are you sure you want to proceed?"
             << "\n"
             << "Yes ---> 1"
             << "\n"
             << "No ----> 0"
             << "\n"
             << "Answer: ";

        cin >> confirm;
    } while (confirm > 1);

    if (confirm == 0)
    {
        sell_item();
    }
    else if (confirm == 1)
    {

        quantities[product_chosen] -= product_quantity;
        writer(path);

        cout << "THANK YOU" << endl;
        cout << "Would you like to buy something else? " << '\n'
             << " Yes --> 1" << '\n'
             << "  No --> 0" << '\n'
             << " Type your choice: ";

        cin >> yes_or_no;

        switch (yes_or_no)
        {

        case 0:
            cout << "Thank You for buying from us!";
            user();
            break;

        case 1:

            sell_item();
            break;
        }
    }
}

void Functionality::adding_item(std::string path, std::string id, std::string name, double price, int quantity)
{

    string name_product;
    double price_product;
    int quantity_product;

    func.reader(path, id, name, price, quantity);

    cout << "Please insert the name of the new product: " << endl;
    cin >> name_product;

    names.push_back(name_product);

    cout << "Please insert the price of the product: " << endl;
    cin >> price_product;

    prices.push_back(price_product);

    cout << "Please insert the quantity: " << endl;
    cin >> quantity_product;

    quantities.push_back(quantity_product);

    cout << "The Item " << name_product << " has been added!" << endl;
    func.writer(path);
}
