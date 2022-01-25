//
//  QuickSort.cpp
//  QuickSort
//
//  Created by Gavin Forsberg on 4/30/20.
//  Copyright © 2020 Gavin Forsberg. All rights reserved.
//

#include "QuickSort.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int, int);
int kthSmallest(int arr[], int, int, int);
int partition(int arr[], int, int, int);
void printArray(int arr[], int);
int findMedian(int arr[], int);


//--------------------------------- QuickSort in O(nlogn) w/ QuickSelect -----------------------------------

// QuickSort algorithm to sort an array in O(nlogn) worst case time.
// uses kth smallest algorithm to find median of array
// and uses that as pivot element
void quickSort::quickSortAlg(int arr[], int l, int h)
{
    if (l < h)
    {
        // Size of the current subarray
        int n = h - l + 1;
        
        // Finds the median
        int med = kthSmallest(arr, l, h, n/2);
        
        // Partition the array around median
        int p = partition(arr, l, h, med);
        
        quickSortAlg(arr, l, p - 1);
        quickSortAlg(arr, p + 1, h);
    }
}

// Algorithm to find kth-smallest element of a given array.
// uses median of medians to solve. breaks array into 5 separate
// subarrays, finds median of each subarray, then finds median of
// all 5 medians
int quickSort::kthSmallest(int arr[] , int l , int r , int k)
{
    if( k > 0 && k <= r - l + 1 )
    {
        int n = r - l + 1;
        
        //divide the array into groups of 5, check median of each
        //group, then store them in new array.
        int i;
        int medians[ (n+4) / 5 ];
        
        for( i = 0; i < n/5; i++)
            medians[i] = findMedian(arr+l + i*5, 5);
        if( i*5 < n )
        {
            medians[i] = findMedian(arr+l + i*5, n % 5);
            i++;
        }
        
        //finds the median of medians via recursive call
        //if only one median (i == 1), then don't use recursive call
        int medOfMed = (i == 1) ? medians[i-1] : kthSmallest(medians, 0, i-1, i/2);
        
        int pos = partition( arr, l, r, medOfMed );
        
        // If the position is the same as k
        if( pos-l == k-1 )
            return arr[pos];
        // If the position is more, recur for left
        if( pos-l > k-1 )
            return kthSmallest( arr, l, pos-1, k );
        // Else recur for right
        return kthSmallest( arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

// method to find the median
int quickSort::findMedian(int arr[] , int n)
{
    sort(arr, arr + n);
    return arr[n/2];
}

//method to swap two elements
void quickSort::swap (int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition method
int quickSort::partition( int arr[] , int l , int r , int x )
{
    // Searching for x and moves it to the end
    int i;
    for ( i = l; i < r; i++ )
        if (arr[i] == x)
            break;
    swap( &arr[i], &arr[r] );
    
    // Partition
    i = l;
    for( int j = l; j <= r - 1; j++ )
    {
        if( arr[j] <= x )
        {
            swap( &arr[i], &arr[j] );
            i++;
        }
    }
    swap( &arr[i], &arr[r] );
    return i;
}

// Function to print the array
void quickSort::printArray( int arr[] , int size )
{
    int i;
    for (i = 0; i < size; ++i)
    {
        cout << arr[i];
        if (i+1 != size)
            cout << ", ";
    }
    cout << endl;
}

int quickSort::main()
{
    cout << "\n\n-----------------------------------------\n";
    cout << "--QuickSort Algorithm with QuickSelect--\n";
    cout << "-----------In-Class Test Cases-----------\n";
    int testArr[] = {2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15, 18, 22};
    int testLength = sizeof(testArr) / sizeof(testArr[0]);
    printArray(testArr, testLength);

    // QuickSort test on testArr[]
    quickSortAlg(testArr, 0, testLength - 1);
    cout << "\nSorted array:\n";
    printArray(testArr, testLength);
    cout << endl << endl;

    cout << "-----------Separate Test Cases------------\n";
    int myArr[] = {3, 7, 1, 20, 11, 15, 5, 6, 2, 19, 43, 26, 55, 11, 17, 23};
    int length = sizeof(myArr) / sizeof(myArr[0]);
    printArray(myArr, length);

    // QuickSort test on myArr[]
    quickSortAlg(myArr, 0, length - 1);
    cout << "\nSorted array:\n";
    printArray(myArr, length);
    return 0;
}
