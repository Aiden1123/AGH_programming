#pragma once
#include <iostream>
#include <math.h>
#include <string>

/** checks if given integer x is prime
    returns true if so and false otherwise */
bool isPrime(unsigned int x); 

/** Various functions for arrays with numbers */
namespace num {
    
    /** Returns mean from array arr of given size */
    template<typename T>
    double srednia(const T *arr, int size) {
    
        double res = 0;
        
        for(int i=0;i<size;i++)
            res += arr[i];
        
        return res/size;
    }
    
    /** Checks if integers in array arr are prime
        returns true if ints between start and end are prime
        start inclusive, end non-inclusive
        
        Also checks if start and end are valid: 
        if end is smaller than start or 
        start or end are out of range then error
        message will be printed to std::cout and function will return false */    
    template<int start,int end>
    bool czyWszystkiePierwsze(const int * arr, int size) {
        
        if (end < start || start < 0 || end > size) {
        
            std::cout<<"Nieprawidlowy zakres!"<<std::endl;
            return false;    
        
        }
        
        for(int i=start;i<end;i++) {
        
            if (!isPrime(arr[i]))
                return false;
        
        }
        
        return true;
    } 

    /** Simple function that converts val true/false to strings
       "TRUE"/"FALSE" respectively, and returns the string. */     
    std::string text(bool val) { return val ? "TRUE" : "FALSE";}    
    
}

