#pragma once
#include "Grade.h"

class GradeBook {
    
    private:
    
    int count;
    const Grade **array;
    
    public:
    
    GradeBook();
    ~GradeBook();
    void Insert(const Grade &grade);
    void Insert(const Grade *grade);
    const Grade *GetPtrConst(int index);
    Grade *GetPtr(int index);
    void Print(const char* message);
};
