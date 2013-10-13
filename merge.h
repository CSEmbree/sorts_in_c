#ifndef MERGE_H
#define MERGE_H


#include "sortcmp.h"

//Merge sort methods
void MergeSort(int A[], int arraySize); 
void Split(int A[], int start, int end, int B[]);
void Merge(int A[], int start, int mid, int end, int B[]);
void CopyArray(int B[], int start, int end, int A[]);


#endif