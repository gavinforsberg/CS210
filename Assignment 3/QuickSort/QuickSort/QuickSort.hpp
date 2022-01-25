//
//  QuickSort.hpp
//  QuickSort
//
//  Created by Gavin Forsberg on 4/30/20.
//  Copyright © 2020 Gavin Forsberg. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp
#include <stdio.h>

class quickSort
{
public:
    void quickSortAlg(int arr[], int l, int h);
    int kthSmallest(int arr[] , int l , int r , int k);
    int findMedian(int arr[] , int n);
    void swap (int* x, int* y);
    int partition( int arr[] , int l , int r , int x );
    void printArray( int arr[] , int size );
    int main();
};

#endif /* QuickSort_hpp */
