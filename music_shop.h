#ifndef _MUSIC_SHOP_H_
#define _MUSIC_SHOP_H_

#include <iostream>
// declaring the classes
class Database
{

public:
    int total_products;
 
    void user();

    void restock_product();

    void sell_item();

    void update_stock();

    void sale_report();
};

class Functionality : public Database
{

public:

    void after_action();

    void selling(int &product);

    void reader();

    void writer();
};

struct Cd_stock
{

    int stock;
    // int pop;
    // int rock;
    // int rap;
    // int lyrics;
};

struct Dvd_stock
{
    int stock;
    // int action;
    // int comedy;
    // int horror;
    // int fantasy;
};

struct Magazine_stock
{

    int stock;
    // int novel;
    // int review;
    // int manga;
    // int article;

};

struct Book_stock
{

    int stock;
    // int fiction;
    // int non_fiction;
    // int thriller;
    // int fairytale;
};
#endif