#include "quick.h"


void QuickSort(int A[], int left, int right)
{
    //If the list >= 2 items
    if( left < right ) 
    {
        //choose pivotIndex that left <= pivotIndex <= right
        int pivotIndex = rand()%(right-left + 1) + left;

        //Get lists of bigger and smaller items and final position of pivot
        int pivotNewIndex = Partition(A, left, right, pivotIndex);

        //Recursively sort elements < pivot
        QuickSort(A, left, pivotNewIndex - 1);

        //Recursively sort elements >= pivot
        QuickSort(A, pivotNewIndex + 1, right);
    }
}


// A[]   = Array of elements to sort
// left  = leftmost element index of array
// right = rightmost element inclusive index of array
int Partition(int A[], int left, int right, int pivotIndex)
{
  int pivotValue = A[pivotIndex];

    Swap(A, pivotIndex, right);  // Move pivot to end
    
    int storeIndex = left;
    
    for( int i = left; i < right; ++i)  // left ≤ i < right
    {
        if(A[i] < pivotValue) 
        {
            Swap(A, i, storeIndex);
            storeIndex++;
        }
    }

  Swap(A, storeIndex, right);  // Move pivot to its final place

  return storeIndex;
}


//Swap two values at given indecies
void Swap(int A[], int iFirst, int iSecond)
{
    int temp = A[iSecond];
    A[iSecond] = A[iFirst];
    A[iFirst] = temp;
}