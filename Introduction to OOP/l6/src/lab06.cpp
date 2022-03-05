#include <iostream>
#include "lab06.h"

const double *initGeometricalSequence(double start, double q, int size) {
    
    if (size<=0) {          //check if size is valid
        std::cout<<"Size must be non-zero (and positive)"<<std::endl;
        return NULL;
    }
    
    double *seq = new double[size];     //allocate memory
    
    seq[0] = start;                     //initialise first element
    
    for(int i=1;i<size;i++) {           //recurrent initialisation of other elements
        seq[i] = seq[i-1] * q;
    }
     
    return seq;                         //return sequence
}
const double *initArithmeticSequence(double start, double r, int size) {
    
    if (size<=0) {          //check if size is valid
        std::cout<<"Size must be non-zero (and positive)"<<std::endl;
        return NULL;
    }
    
    double *seq = new double[size];     //allocate memory
    
    seq[0] = start;                     //initialise first element
    
    for(int i=1;i<size;i++) {           //recurrent initialisation of other elements
        seq[i] = seq[i-1]+r;
    }
     
    return seq;                         //return sequence
}
void printSequence(const double *sequence, int size) {

    if (!sequence || !size) {           //check if arguments are valid
        std::cout<<"Nothing to print."<<std::endl;
        return;
    }
    
    std::cout<<"(";                     //print sequence
    
    for(int i=0;i<size;i++) {
        std::cout<<sequence[i];
        if (i+1!=size) {
            std::cout<<",";
        }
    }
    
    std::cout<<")"<<std::endl;

    return;
}
void deleteSequence(const double **sequence) {
    
    if (*sequence) {            //case 1: sequence exists
        delete[] *sequence;
        *sequence = NULL;
        std::cout<<"Sequence deleted."<<std::endl;   
    }
    else {                      //case 2: sequence doesn't exist
        std::cout<<"Nothing to delete."<<std::endl;
    }
    
    return;
}
void addSequence(const double ***seqList, int **seqLenList, const double *seq, int size) {
    
    if (!(*seqList)) {                      //case 1: adding first element
        *seqList = new const double*[2];    //allocate memory
        *seqLenList = new int[1];
        
        (*seqList)[0] = seq;                //initialise values
        (*seqList)[1] = NULL;
        (*seqLenList)[0] = size;
    }
    
    else {                                  //case 2: some elements are already present
        int count = 0;      //number of sequences in the array
        
        for(int i=0;(*seqList)[i];i++) {    //calculate count
            count++;
        }
    
        const double **old_seqList = *seqList;  //copy current arrays
        int *old_seqLenList = *seqLenList;
        
        *seqList = new const double*[count + 2];    //allocate memory for new arrays
        *seqLenList = new int[count + 1];
        
        for(int i=0;i<count;i++) {
            (*seqList)[i] = old_seqList[i];         //copy data from old arrays to new arrays
            (*seqLenList)[i] = old_seqLenList[i];
        }
        
        (*seqList)[count] = seq;                    //initialise new values
        (*seqList)[count+1] = NULL;
        (*seqLenList)[count]= size;
        
        delete[] old_seqList;                       //free memory
        delete[] old_seqLenList; 
  
    }
    
    return;
}
void printSequence(const double **seqList, int *seqLenList) {
    for(int i=0;seqList[i];i++) {
        std::cout<<"Sequence "<<i+1<<": ";
        printSequence(seqList[i],seqLenList[i]);
    }
    return;
}
void deleteSequence(const double **seqList, int *seqLenList) {
    for(int i=0;seqList[i];i++) {                   //delete sequences
       delete[] seqList[i];
       std::cout<<"Sequence deleted."<<std::endl;
    }    
    delete[] seqList;                               //delete array of sequences
    delete[] seqLenList;                            //delete array of lengths
    return;
}
