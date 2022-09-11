#pragma once
#include <functional>
#include <vector>

/**Container for criterias implemented on std::vector.
    criterias are given as functions that take int as
    argument and return bool*/
class FilterCriteria {
    
    private:
    
    std::vector<std::function<bool (int)>> v;   //vector that stores data
    
    public:
    
    /**Creates new container*/
    FilterCriteria();
    
    /**adds function to the container*/
    void add(std::function<bool (int)> fun);
    
    /**returns number of functions in the container*/
    int size() const;
    
    /**returns function with given index*/
    const std::function<bool (int)> &get(int index) const;

};
