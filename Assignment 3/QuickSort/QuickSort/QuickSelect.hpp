//
//  QuickSelect.hpp
//  QuickSort
//
//  Created by Gavin Forsberg on 4/30/20.
//  Copyright © 2020 Gavin Forsberg. All rights reserved.
//

#ifndef QuickSelect_hpp
#define QuickSelect_hpp
#include <stdio.h>

class quickSelect
{
public:
    int partition(int arr[], int l, int r);
    int kthSmallest(int arr[], int l, int r, int k);
    void printArray(int arr[], int size);
    int main();
};

#endif /* QuickSelect_hpp */
