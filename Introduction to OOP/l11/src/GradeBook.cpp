#include "GradeBook.h"

GradeBook::GradeBook() {
    this->count = 0;
    this->array = nullptr;
}

GradeBook::~GradeBook() {
    for(int i=0;i<this->count;i++) {
        delete (this->array)[i];
    }
    
    delete[] this->array;
}
void GradeBook::Insert(const Grade &grade) {
    
    const Grade **temp = this->array;
    this->count += 1;
    this->array = new const Grade*[count];
    
    for(int i=0;i<this->count-1;i++) {
        (this->array)[i] = temp[i];
    }
    
    if (temp) {
        delete[] temp;
    }
    
    const Grade *grade_on_heap = new Grade(grade);
    (this->array)[count-1] = grade_on_heap;
    
}

void GradeBook::Insert(const Grade *grade) {
    
    const Grade **temp = this->array;
    this->count += 1;
    this->array = new const Grade*[count];
    
    for(int i=0;i<this->count-1;i++) {
        (this->array)[i] = temp[i];
    }
    
    if (temp) {
        delete[] temp;
    }

    (this->array)[count-1] = grade;
}

const Grade *GradeBook::GetPtrConst(int index) {
    
    if (index<0 || index>=this->count)
        return nullptr;
    
    return (this->array)[index];
}


Grade *GradeBook::GetPtr(int index) {
    
    if (index<0 || index>=this->count)
        return nullptr;
    
    return const_cast<Grade *>((this->array)[index]);
}

void GradeBook::Print(const char* message) {
    for(int i=0;i<this->count;i++) {
        ((this->array)[i])->Print(message);
    }
}

