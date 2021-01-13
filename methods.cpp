#include "music_shop.hpp"
#include <fstream>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
// Creating objects
Functionality func;
Cd_stock cd;
Dvd_stock dvd;
Magazine_stock magazine;
Book_stock book;

//Declaring vectors
vector<string> names;
vector<double> prices;
vector<int> quantities;
vector<string> reports;

// ---------------------------------------- Starting function ------------------------------
void Database::user()
{
    int action;

    cout << '\n'
         << "Please Select the action you would like to do" << '\n'
         << " Restock Product -----> 0 " << '\n'
         << " Add new item --------> 1 " << '\n'
         << " Sell Item -----------> 2 " << '\n'
         << " Sale Report ---------> 3 " << '\n'
         << "\n Exit ----------------> 4" << '\n'
         << " Select your choice: ";

    cin >> action;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong format! Please try again" << endl;
        user();
    }

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

        cout << "Wrong format! Please try again" << endl;
        user();
        break;
    }
}

// ---------------------------------------- RESTOCK PRODUCT METHOD -------------------------------
void Database::restock_product()
{

    int choice;
    int new_total;
    int code;

    choice = func.choice_product("What Product would you like to restock");

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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please insert the integer of the product eg. 001 = 1" << endl;
            cout << "\n"
                 << "Please select your choice: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]) || cin.fail());

        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products || cin.fail());

        quantities[code] += new_total;
        total_products += new_total;
        // save the value back to the file
        func.stock_writer("database_files/CDs.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now " << quantities[code]
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // inserting the serial code, to understand which Item to take;
            cout << "Please insert the integer of the product eg. 001 = 1" << endl;
            cout << "\n"
                 << "Please select your choice: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]) || cin.fail());

        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products || cin.fail());

        quantities[code] += new_total;
        total_products += new_total;
        func.stock_writer("database_files/DVDs.txt");

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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // inserting the serial code, to understand which Item to take;
            cout << "Please insert the integer of the product eg. 001 = 1" << endl;
            cout << "\n"
                 << "Please select your choice: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]) || cin.fail());

        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products || cin.fail());

        // restocking the product
        quantities[code] += new_total;
        total_products += new_total;
        func.stock_writer("database_files/Magazines.txt");

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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // inserting the serial code, to understand which Item to take;
            cout << "Please select your choice: ";
            cin >> code;

        } while (!std::count(quantities.begin(), quantities.end(), quantities[code]) || cin.fail());

        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n"
                 << "You have selected: " << names[code] << endl;
            cout << "Please insert the amount: ";
            cin >> new_total;

        } while (new_total > total_products || cin.fail());

        quantities[code] += new_total;
        total_products += new_total;
        func.stock_writer("database_files/Books.txt");

        cout << "The item has been restocked, "
             << names[code] << " and now  " << quantities[code]
             << " are the Books available" << endl;

        func.after_action();
        break;

    case 4:
        user();
        break;

    default:
        cout << "Wrong format! Please Try Again" << endl;
        restock_product();
        break;
    }
}

//------------------------------------------- METHODS THAT ADDS AN ITEM -------------------------
void Database::add_item()
{
    int choice;

    choice = func.choice_product("Where would you like to add the new item? ");

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
    case 4:
        user();
        break;
    default:
        cout << "Wrong format, Please Try Again: " << endl;
        add_item();
        break;
    }
}

//--------------------------------------SELL ITEM ----------------------------------
void Database::sell_item()
{
    int product_choice;

    product_choice = func.choice_product("What Product would you like to sell");

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
    case 4:
        user();
        break;
    default:
        cout << "We do not have that product yet" << endl;
        sell_item();
        break;
    }
}
//--------------------------------------- SALE REPORT ------------------------------
void Database::sale_report()
{
    int choice_file;
    int os_choice;

    if (reports.empty())
    {

        cout << "\n"
             << "TODAY NOTHING HAS BEEN SOLD YET" << endl;
    }

    cout << endl;

    for (int i = 0; i < reports.size(); i++)
    {

        cout << reports.at(i) << endl;
    }

    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nWould you like to see the FULL SALE REPORT?"
             << "\nYes ---> 1"
             << "\n No ---> 0"
             << "\nPlease select a choice: ";

        cin >> choice_file;

    } while ((choice_file < 0 || choice_file > 1) || cin.fail());

    if (choice_file == 1)
    {

        do
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " \nWhich OS you have? "

                 << " \nWindows/Linux ---> 0 "

                 << " \nMacOS  ----------> 1 "

                 << "\nSelect Choice: ";

            cin >> os_choice;
        } while ((os_choice < 0 || os_choice > 1) || cin.fail());

        switch (os_choice)
        {

        case 0:
            system("database_file/sale_report.txt");
            user();
            break;
        case 1:

            system("open database_files/sale_report.txt");
            user();
            break;
        }
    }
    else if (choice_file == 0)
    {
        user();
    }
}

// ----------------------------------------CHOICE AFTER AN ACTION HAS BEEN MADE----------------------------
void Functionality::after_action()
{

    int choice;
    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << '\n'
             << " Restock another product --> 0 " << '\n'
             << " Main Menu ----------------> 1 " << '\n'
             << " Select your choice: ";
        cin >> choice;
    } while ((choice > 2 || choice < 0) || cin.fail());
    if (choice == 0)
        restock_product();
    else if (choice == 1)
        user();
    else
        cout << "Wrong format, Try again!";
    func.after_action();
}

// ---------------------------------- reads the file and prints it out -----------------------------------------
void Functionality::reader(std::string path, std::string id, std::string name, double price, int quantity)
{
    ifstream stock;
    // cleaning vectors
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
// writes the stock back to the file
void Functionality::stock_writer(std::string path)
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

// choice of the product
int Functionality::choice_product(std::string name)
{

    int choice;

    cout << name << '\n'
         << " CDs --------> 0 " << '\n'
         << " DVDs -------> 1 " << '\n'
         << " Magazines --> 2 " << '\n'
         << " Books ------> 3 " << '\n'
         << "\n Main Menu --> 4 " << '\n'
         << "Please Select the product: ";

    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong format! Please try again" << endl;
        func.choice_product(name);
    }
    else
    {
        return choice;
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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nAvailable: " << total_products
             << "\nPlease insert the integer of the product eg. 001 = 1" << endl;
        cout << "\nPlease insert which item you would like to purchase: ";
        cin >> product_chosen;

        if (quantities[product_chosen] <= 0)
            cout << "OUT OF STOCK \nIt will be back soon! " << endl;

    } while (!std::count(quantities.begin(), quantities.end(), quantities[product_chosen]) || cin.fail() || quantities[product_chosen] <= 0);

    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nYou have Selected: " << names[product_chosen] << " Available: " << quantities[product_chosen] << endl;
        cout << "Please Select how many you would like to sell: ";
        cin >> product_quantity;

        if ((product_quantity > quantities[product_chosen]))
            cout << "\nI am sorry but we don't have that many at the moment" << endl;

    } while ((product_quantity > quantities[product_chosen]) || (product_quantity <= 0) || cin.fail());

    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nYou have selected " << names[product_chosen] << " and the amount is " << product_quantity
             << "\nAre you sure you want to proceed?"
             << "\n Yes ---> 1"
             << "\n  No ---> 0"
             << "\nAnswer: ";

        cin >> confirm;
    } while ((confirm < 0 || confirm > 1) || cin.fail());

    if (confirm == 0)
    {
        sell_item();
    }
    else if (confirm == 1)
    {

        quantities[product_chosen] -= product_quantity;
        stock_writer(path);
        vector_writer(names[product_chosen], product_quantity);
        cout << "\nTHANK YOU" << endl;
        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nWould you like to sell something else? " << '\n'
                 << " Yes --> 1" << '\n'
                 << "  No --> 0" << '\n'
                 << "Type your choice: ";

            cin >> yes_or_no;
        } while ((yes_or_no < 0 || yes_or_no > 1) || cin.fail());

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
    int choice;

    func.reader(path, id, name, price, quantity);
    do
    {

        //  needs to accept only strings
        cout << "Please insert the name of the new product: " << endl;
        cin >> name_product;
    } while (isdigit(name_product[0]));

    names.push_back(name_product);

    // asking the value price
    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please insert the price of the product: " << endl;
        cin >> price_product;

    } while (price_product < 0 || cin.fail());

    prices.push_back(price_product);

    // asking the product quantity
    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please insert the quantity: " << endl;
        cin >> quantity_product;
    } while (quantity_product < 0 || cin.fail());

    quantities.push_back(quantity_product);

    cout << "\n"
         << "The Item " << name_product << " has been added!" << endl;
    func.stock_writer(path);

    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n Would you like to add another item?"
             << "\n Yes ---> 1"
             << "\n  No ---> 0"
             << "\nPlease Select choice: ";
        cin >> choice;
    } while ((choice < 0 || choice > 1) || cin.fail());

    if (choice == 1)
        func.add_item();
    else if (choice == 0)
        user();
}

// it returns a vector of sales of the day
vector<string> Functionality::vector_writer(std::string item, int quantity)
{

    ofstream sale("database_files/sale_report.txt", ios::app);

    if (!sale.is_open())
    {
        cerr << "Error occurred" << endl;
        exit(1);
    }
    string sale_sentence = to_string(quantity) + " of " + item + " have been sold " + current_time();

    //writing the sentence on the file;
    sale << sale_sentence << endl;

    sale_sentence = to_string(quantity) + " of " + item + " have been sold today";
    // adding the sentence to the vector;
    reports.push_back(sale_sentence);

    return reports;
}

// takes the current time and it returns a string
string Functionality::current_time()
{

    string current_time;

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char *dt = ctime(&now);

    current_time = dt;

    return current_time;
}