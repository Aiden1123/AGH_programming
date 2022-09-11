#pragma once
#include <vector>
#include <functional>

/**Container for integers implemented using std::vector*/
class List {
    private:

    std::vector<int> v;     //vector with data
    
    public:
    
    /**Default constructor, creates new list*/
    List();
                                 
    /**Prints data stored in the list*/                             
    void print() const;
    
    /**Prints message and data stored in the list*/
    void print(const char *message) const;
    
    /**Inserts x at the beginning of the list*/
    void insert(int x);
    
    /**overload [] to work the same way as for arrays*/
    int &operator[](int k);
    
    /**Creates and returns new list which contains 
    elements from older list that match criteria specified
    by function fun (element matches criteria if fun returns
    true for the element)*/
    List filter(std::function<bool (int)> fun) const;
    
};
