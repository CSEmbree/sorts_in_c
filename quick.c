#include "quick.h"

 
void QuickSort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
 
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];

  while (left < right)
  {
    while ( (numbers[right] >= pivot) && (left < right) )
      right--;
    
    if ( left != right )
    {
      numbers[left] = numbers[right];
      left++;
    }
    

    while ( (numbers[left] <= pivot) && (left < right) )
      left++;
    
    if ( left != right )
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  
  numbers[left] = pivot;
  
  pivot = left;
  left = l_hold;
  right = r_hold;
  
  if (left < pivot)
    QuickSort(numbers, left, pivot-1);
  
  if (right > pivot)
    QuickSort(numbers, pivot+1, right);
}




/*
// left is the index of the leftmost element of the subarray
  // right is the index of the rightmost element of the subarray (inclusive)
  // number of elements in subarray = right-left+1
  Partition(array, left, right, pivotIndex)
  {
     pivotValue = array[pivotIndex]
     swap array[pivotIndex] and array[right]  // Move pivot to end
     storeIndex = left
     for i from left to right - 1  // left ≤ i < right
         if array[i] < pivotValue
             swap array[i] and array[storeIndex]
             storeIndex = storeIndex + 1
     swap array[storeIndex] and array[right]  // Move pivot to its final place
     return storeIndex
  }

  QuickSort(array, left, right)
  {
     // If the list has 2 or more items
     if left < right
         // See "#Choice of pivot" section below for possible choices
         choose any pivotIndex such that left ≤ pivotIndex ≤ right
         // Get lists of bigger and smaller items and final position of pivot
         pivotNewIndex = Partition(array, left, right, pivotIndex)
         // Recursively sort elements smaller than the pivot
         quicksort(array, left, pivotNewIndex - 1)
         // Recursively sort elements at least as big as the pivot
         quicksort(array, pivotNewIndex + 1, right)
  }
*/