// visitor_design_pattern_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/visitor-design-pattern/

#include <iostream>
#include <array>
#include "stock.h"


int main()
{
    std::array<stock*,5> stocks { new apple{}, new google{}, new google{}, new apple{}, new apple{} };

    buy_visitor buy_operation;
    sell_visitor sell_operation;

    for (stock* st : stocks)
    {
        st->accept(&buy_operation);
    }
    buy_operation.total_stocks();

    for (stock* st : stocks)
    {
        st->accept(&sell_operation);
    }
    sell_operation.total_stocks();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
