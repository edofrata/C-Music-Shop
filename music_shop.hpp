#ifndef _MUSIC_SHOP_H_
#define _MUSIC_SHOP_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    void selling(int &product, std::string path);

    void reader(std::string path, std::string id, std::string name, double price, int quantity);

    void stock_writer(std::string path);

    void adding_item(std::string path, std::string id, std::string name, double price, int quantity);

    vector<string> vector_writer(std::string item, int quantity);

    string current_time();
    
    int choice_product(std::string name);
};

struct Cd_stock : public Database
{
    int stock;
    string name;
    const string id = "C00";
    double price;
};

struct Dvd_stock : public Database
{
    int stock;
    string name;
    const string id = "D00";
    double price;
};

struct Magazine_stock : public Database
{

    int stock;
    string name;
    const string id = "M00";
    double price;
};

struct Book_stock : public Database
{

    int stock;
    string name;
    const string id = "B00";
    double price;
};
#endif