#ifndef _MUSIC_SHOP_H_
#define _MUSIC_SHOP_H_

#include <iostream>
// declaring the classes
class Database
{

private:
    int cd_stock;
    int dvd_stock;
    int magazine_stock;
    int book_stock;
    int sell_count;

public:
    void user();
    
    void restock_product();

    void sell_item();

    void update_stock();

    void sale_report();

    void after_action();

    void reader(std::string);
};

class Cd_stock
{

private:
    int pop;
    int rock;
    int rap;
    int lyrics;
};

class Dvd_stock
{

private:
    int action;
    int comedy;
    int horror;
    int fantasy;
};

class Magazine_stock
{

private:
    int novel;
    int review;
    int manga;
    int article;
};

class Book_stock
{

private:
    int fiction;
    int non_fiction;
    int thriller;
    int fairytale;
};
#endif