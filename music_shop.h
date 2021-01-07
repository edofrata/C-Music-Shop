#ifndef _MUSIC_SHOP_H_
#define _MUSIC_SHOP_H_

#include <iostream>
#include <string>
using namespace std;
// declaring the classes
class Database
{

public:
    int total_products;

    void user();

    void restock_product();

    void add_item();

    void sell_item();

    void sale_report();
};

class Functionality : public Database
{

public:
    void after_action();

    void selling(int &product, std::string path, std::string id, std::string name, double price, int quantity);

    void reader(std::string path, std::string id, std::string name, double price, int quantity);

    void writer(std::string path);
};

class Cd_stock : public Database
{
public:
    int stock;
    string name;
    string id = "C00";
    double price;



};

struct Dvd_stock
{
    int stock;
    string name;
    string id = "D00";
    double price;
};

struct Magazine_stock
{

    int stock;
    string name;
    string id = "M00";
    double price;
};

struct Book_stock
{

    int stock;
    string name;
    string id = "B00";
    double price;
};
#endif