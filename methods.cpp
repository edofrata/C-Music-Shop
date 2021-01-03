#include "database.h"
#include <iostream>

using namespace std;

void Database::user()
{
    int choice;
    int action;

    cout << "Are you an Employee or Customer?" << endl;

    cin >> choice;

    if (choice == 1)
    {

        cout << "Your are a Customer,  What would you like to buy?" << endl;
        sell_item();
    }
    else if (choice == 0)
    {

        cout << "You are an Employee" << endl;
        cout << "Please Select the action you would like to do" << endl;

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
            cout<< "Wrong format! Please try again" << endl;
            break;
        }
        

    }
    else
    {

        cout << "Wrong format, Try again" << endl;
        user();
    }
}

void Database::restock_product()
{
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
