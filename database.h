#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
// declaring the classes
class Database
{

private:
    int cd_stock = 100;
    int dvd_stock = 200;
    int magazine_stock  = 100;
    int book_stock = 200;
    int sell_count;

public:
    void restock_product();

    void sell_item();

    void update_stock();

    void sale_report();

    void user();
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