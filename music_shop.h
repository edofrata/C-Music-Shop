#ifndef _MUSIC_SHOP_H_
#define _MUSIC_SHOP_H_

#include <iostream>
// declaring the classes
class Database
{

private:
    int total_products;
    // Cd_stock cd;
    // Dvd_stock dvd;
    // Magazine_stock magazine;
    // Book_stock book;
    int cd_stock;
    int dvd_stock;
    int magazine_stock;
    int book_stock;

public:
    void user();

    void restock_product();

    void sell_item();

    void update_stock();

    void sale_report();

    void after_action();

    void selling(int& product);

    void reader(std::string);

    void writer();
};

class Cd_stock
{

public:
    int stock;
    // int pop;
    // int rock;
    // int rap;
    // int lyrics;
};

class Dvd_stock
{

public:
    int stock;
    // int action;
    // int comedy;
    // int horror;
    // int fantasy;
};

class Magazine_stock
{

public:
    int stock;
    // int novel;
    // int review;
    // int manga;
    // int article;
};

class Book_stock
{

public:
    int stock;
    // int fiction;
    // int non_fiction;
    // int thriller;
    // int fairytale;
};
#endif