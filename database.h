#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
// declaring the classes
class Database
{

private:
    int *cd_stock;
    int *dvd_stock;
    int *magazine_stock;
    int *sell_count;

public:
    void restock_product();

    void sell_item();

    void update_stock();

    void sale_report();

    void user();
};

class Cd_stock
{

public:
    int pop;
    int rock;
    int rap;
    int lyrics;
};

class Dvd_stock
{

public:
    int action;
    int comedy;
    int horror;
    int fantasy;
};

class Magazine_stock
{

public:
    int novel;
    int review;
    int manga;
    int article;
};

class Book_stock
{

public:
    int fiction;
    int non_fiction;
    int thriller;
    int fairytale;
};
#endif