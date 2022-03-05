#pragma once

const double *initGeometricalSequence(double start, double q, int size);
/** Creates array on heap with geometrical sequence. First element is initialised
    as start and others are defined as a[i] = a[i-1] * q. Returns pointer to array on succes
    and NULL on failure. */
     
const double *initArithmeticSequence(double start, double r, int size);
/** Creates array on heap with arithmetic sequence. First element is initialised
    as start and others are defined as a[i] = a[i-1] + r. Returns pointer to array on succes
    and NULL on failure. */
    
void printSequence(const double *sequence, int size);
/** Prints size elements from sequence if sequence exists. */

void deleteSequence(const double **sequence);
/** Deallocates memory of sequence and prints message if operation was succesful.*/

void addSequence(const double ***seqList, int **seqLenList, const double *seq, int size);
/** Adds sequnce (seq) to array of sequences (seqList) and updates array containing 
    sequences' lengths (seqLenList). seqList and seqLenList are dynamic arrays allocated on heap
    so they need to be deleted with deleteSequence later on. Last element of seqList is NULL */

void printSequence(const double **seqList, int *seqLenList);
/** Prints array of sequences (seqList). Number of elements to print is defined in seqLenList array */

void deleteSequence(const double **seqList, int *seqLenList);
/** Deallocates memory of all sequences in seqList and also deallocates seqList and seqLenList */
