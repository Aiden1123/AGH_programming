#pragma once
#define MAX_SIZE 50

struct myArray {
    /**structure that holds information about array and array itself*/
    int N;              //length of array
    int data[MAX_SIZE];
    myArray *spouse;    
    myArray() {
        /**myArray constructor, sets proper values so that 
        other functions know that it is empty*/
        N=0;    
        spouse = nullptr;
        for(int i=0;i<MAX_SIZE;i++)
            data[i]=0;
    }
};

void printArray(myArray array);
/**prints array in terminal. If array is empty a proper message is displayed*/

int fillArrayWithFibonacci(myArray *array, int size);
/**fills array with fibonacci sequence. Number of elements is specified by size.
    function starts from index 0 and replaces size elements for fibonacci numbers so
    all data that has been in this range is deleted.
    
    return values: 1 on success, 0 otherwise*/
    
void revert(myArray *array);
/**Reverts order of the array,
    prints information about operation to console*/

void extend(myArray *array, int extend_num);
/**Extends array by number of elements specified by extend_num,
    value of new elements is not specified.
    
    Prints information about operation to console*/
    
void truncate(myArray *array, int truncate_num);
/**Shortens array by last truncate_num elements.
    If truncate_num is higher than number of elements in the array then it clears the array.
    
    Prints information about operation to console*/
    
void checkArraySpouse(myArray *array);
/**Checks if array has spouse and prints result to terminal*/

void marry(myArray *array_a, myArray *array_b);
/**if array_a and array_b are not identical then array_a is assigned array_b as spouse and vice versa*/

void divorce(myArray *array_a, myArray *array_b);
/**sets spouse pointers of array_a and array_b to nullptr if both of them exist*/
