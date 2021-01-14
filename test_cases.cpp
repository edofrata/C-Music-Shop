#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "music_shop.hpp"

Functionality func;
Cd_stock cd;
Dvd_stock dvd;
Magazine_stock magazine;
Book_stock book;

TEST_CASE("testing initialiazed strings are not empty", "[id]")
{

    REQUIRE(cd.id == "C00");
    REQUIRE(dvd.id == "D00");
    REQUIRE(magazine.id == "M00");
    REQUIRE(book.id == "B00");
}

TEST_CASE("vector push works as it should", "[push_back]")
{

    vector<string> name;

    name.push_back("John");
    name.push_back("Elvis");
    name.push_back("Nirvana");

    REQUIRE(name.at(0) == "John");
    REQUIRE(name.at(1) == "Elvis");
    REQUIRE(name.at(2) == "Nirvana");

    SECTION("Testing the double vector")
    {
        vector<double> price;
        price.push_back(2.99);
        price.push_back(4.99);
        price.push_back(3.01);

        CHECK(price.at(0) == 2.99);
        CHECK(price.at(1) == 4.99);
        CHECK(price.at(2) == 3.01);

        SECTION("Testing the integer vector")
        {

            vector<int> quantity;

            quantity.push_back(10);
            quantity.push_back(25);
            quantity.push_back(15);

            CHECK(quantity.at(0) == 10);
            CHECK(quantity.at(1) == 25);
            CHECK(quantity.at(2) == 15);
        }
    }
}

TEST_CASE("Testing the restocking product", "[product_restock]")
{

    vector<int> quantity;

    quantity.push_back(25);

    REQUIRE(quantity.at(0) + 25 == 50);

    SECTION("Selling mode testing")
    {

        CHECK(quantity.at(0) - 10 == 15);
    }
}

bool is_in(vector<string> names, std::string name)
{

    if (std::count(names.begin(), names.end(), name))
    {

        return true;
    }
    else
    {
        return false;
    }
}

TEST_CASE("Testing a function which I will need for my program, [is_in]")
{

    vector<string> name;

    name.push_back("Jordan");
    name.push_back("John");
    name.push_back("Elton");

    REQUIRE(is_in(name, "Jordan"));
    REQUIRE(is_in(name, "jordan")); //test failes, it is case sensitive
    REQUIRE_FALSE(is_in(name, "Elvis"));
}