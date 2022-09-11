#include "Sum.h"

Sum::Sum(double val) {v = val;}

double Sum::value() {return v;}

void Sum::operator()(double x) {v += x;}

Sum sumData(const Data &d) {
    double sum=0;
    auto func = [&sum](double x) {sum+=x;};
    std::for_each(d.data.begin(),d.data.end(),func);
    return Sum(sum);
}