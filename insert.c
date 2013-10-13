#include "insert.h"


void InsertionSort(int *list, int listLength)
{ 
    int i, j, temp;
    
    for( i = 0 ; i < listLength ; ++i )
    {
        temp = list[i]; // store the next element to sort
        j = i; 

        //step back through the sorted list to find correct placement of current element
        while( j > 0 && list[j-1] > temp) 
        { 
            list[j] = list[j-1]; //shift each element up one along the way
            j--;
        }

        list[j] = temp;  // place element in it's sorted position
    }
}