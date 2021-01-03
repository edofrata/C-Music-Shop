#include "database.h"
#include <iostream>
#include <string>

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

void Database::restock_product()
{
    int choice;
    int new_total;

    cout << " What Product would you like to restock? " << '\n'
         << " CDs --------> 0 " << '\n'
         << " DVDs -------> 1" << '\n'
         << " Magazines --> 2 " << '\n'
         << " Books ------> 3 " << '\n'
         << "Please Select the product: ";

    cin >> choice;

    switch (choice)
    {

// RESTOCKING THE VALUE OF THE CDS
    case 0:
        cout << "The value is: " << cd_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        cd_stock += new_total;

        cout << "The item has been restocked, "
            << cd_stock  << " " << "are the CDs available";
        break;

// RESTOCKING THE VALUE OF THE DVDS
    case 1:
        cout << "The value is: " << dvd_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        dvd_stock += new_total;

        cout << "The item has been restocked, "
            << dvd_stock  << " " << "are the DVDs available";
        break;


// RESTOCKING THE VALUE OF THE MAGAZINES
    case 2:
        cout << "The value is: " << magazine_stock <<endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        magazine_stock += new_total;

        cout << "The item has been restocked, "
              << magazine_stock << " " << "are the magazines available";
        break;

// RESTOCKING THE VALUE OF THE BOOKS
    case 3:
        cout << " The value is: " << book_stock << endl;

        cout << "Please insert the amount: ";
        cin >> new_total;

        book_stock += new_total;

        cout << "The item has been restocked, "
             << book_stock << " " << "are the books available";
        break;
    default:
        cout << "Wrong format! Please Try Again" << endl;
    }

}

void Database::sell_item()
{
}

void Database::update_stock()
{
}

void Database::sale_report()
{
}
