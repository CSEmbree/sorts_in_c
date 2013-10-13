#ifndef SORTCMP_H
#define SORTCMP_H



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "merge.h"
#include "insert.h"
#include "quick.h"



//success or error return values
#define SUCCESS 0
#define ERROR -1

#define TRUE 0
#define FALSE -1

#define MAX_SIZE 10000



//MERGE
void TestMergeSort(int arraySize);

//INSERTION
void TestInsertionSort(int arraySize);

//QUICK
void TestQuickSort(int arraySize);

double ExecutionTime(double duration, double factor);
void DisplayList(int *Array, int arraySize);


#endif