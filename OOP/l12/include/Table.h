#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Data.h"

class Table {

    std::vector<Data> rows;
    int min_row_count;

    public:

    Table();
    void print();
    Table &sort(int index);
    Table &sortBy( bool (*fun)(const Data &, const Data &));
    Table &operator+=(const Data &d);
};