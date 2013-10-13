#include "merge.h"


//top down merge sort
void MergeSort(int A[], int arraySize)
{
    int B[arraySize]; //temp workspace
    Split(A, 0, arraySize, B);
}
 
void Split(int A[], int start, int end, int B[])
{
    if(end - start < 2) // if list has only one element, then it is sorted
        return;                  
    
    // recursively split into two halves until each part is size 1, then merge & return back up the call chain
    int mid = (end + start) / 2; //mid point to determine splitting
    
    Split(A, start, mid, B); //split and merge left  half
    Split(A, mid, end, B);   //split and merge right half
    
    Merge(A, start, mid, end, B); //merge the previous two split runs
    
    CopyArray(B, start, end, A); //copy the merged runs back to A from temp workspace
}
 
void Merge(int A[], int start, int mid, int end, int B[])
{
    int left = start;
    int right = mid;
 
    // While there are elements in the left or right runs
    for ( int j = start; j < end; j++) 
    {
        // If left run head exists and is <= existing right run head.
        if ( (left < mid) && (right >= end || A[left] <= A[right]) )
            B[j] = A[left++];  // update left index after using it
        else
            B[j] = A[right++];  // udpate right index after using it
    }
}

void CopyArray(int B[], int start, int end, int A[])
{
    for (int i = start; i < end; ++i)
        A[i] = B[i];
}