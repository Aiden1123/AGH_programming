#include "FilterCriteria.h"
#include <functional>

FilterCriteria::FilterCriteria() {
    v = std::vector<std::function<bool (int)>>();       //create new vector
}

void FilterCriteria::add(std::function<bool (int)> fun) {
    v.push_back(fun);
}

int FilterCriteria::size() const{
    return v.size();
}

const std::function<bool (int)> &FilterCriteria::get(int index) const{
    return v[index];
}

