#ifndef QUICK_H
#define QUICK_H

#include "sortcmp.h"

void QuickSort(int A[], int left, int right);
int Partition(int A[], int left, int right, int pivotIndex);
void Swap(int A[], int iFirst, int iSecond);

#endif