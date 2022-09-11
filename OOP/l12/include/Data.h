#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>

class Sum;
class Table;

class Data {

    std::string name;
    std::vector<double> data;

    public:

    Data(std::string name,std::vector<double> data); 
    void print() const;

    friend Table;
    friend Sum sumData(const Data &d);
};

