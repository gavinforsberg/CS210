//
//  QuickSelect.cpp
//  QuickSort
//
//  Created by Gavin Forsberg on 4/30/20.
//  Copyright © 2020 Gavin Forsberg. All rights reserved.
//

#include "QuickSelect.hpp"
#include <iostream>
using namespace std;


// Below is the code for the algorithm QuickSelect.
// Similar to QuickSort, the only difference is, instead
// of recurring both subarrays, only the one which contains
// the kth-element is partitioned

int kthSmallest(int arr[], int, int, int);
void printArray(int arr[], int);

int quickSelect::partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i] , arr[j]);
            i++;
        }
    }
    swap(arr[i] , arr[r]);
    return i;
}

// kthSmallest algorithm using QuickSort logic
int quickSelect::kthSmallest(int arr[], int l, int r, int k)
{
    if( k > 0 && k <= r - l + 1 )
    {
        // Partition around last element
        int index = partition(arr, l, r);
        
        // if position is equal to k
        if (index - l == k - 1)
            return arr[index];
        
        // if position is more than k
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        
        // else (position is less than k)
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }
    // return max int if k is more than num of elements
    return INT_MAX;
}

void quickSelect::printArray(int arr[], int size)
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

int quickSelect::main()
{
    cout << "-----------------------------------------\n";
    cout << "----------QuickSelect Algorithm----------\n";
    
    //-------------In-Class Test------------
    int myArr[] = {2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15, 18, 22};
    int length = sizeof(myArr) / sizeof(myArr[0]);
    printArray(myArr, length);
    int k;
    
    //k: 4, 8, 12
    k = 4;
    cout << "4th smallest is: " << kthSmallest(myArr, 0, length - 1, k) << endl;
    k = 8;
    cout << "8th smallest is: " << kthSmallest(myArr, 0, length - 1, k) << endl;
    k = 12;
    cout << "12th smallest is: " << kthSmallest(myArr, 0, length - 1, k) << endl << endl;
    
    //------------Separate Test--------------
    int testArr[] = {3, 7, 1, 20, 11, 15, 5, 6, 2, 19, 43, 26, 55, 11, 17, 23};
    int testlength = sizeof(testArr) / sizeof(testArr[0]);
    printArray(testArr, testlength);
    int k2;
    
    //k2: 2, 5, 9
    k2 = 2;
    cout << "2nd smallest element is: " << kthSmallest(testArr, 0, testlength - 1, k2) << endl;
    k2 = 5;
    cout << "5th smallest element is: " << kthSmallest(testArr, 0, testlength - 1, k2) << endl;
    k2 = 9;
    cout << "9th smallest element is: " << kthSmallest(testArr, 0, testlength - 1, k2) << endl;
    return 0;
}
