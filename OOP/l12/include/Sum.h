#pragma once
#include "Data.h"
#include <algorithm>
#include <iostream>

class Sum {

    double v;

    public:

    Sum(double val);

    double value();
    void operator()(double x);

};

Sum sumData(const Data &d);