//
//  main.cpp
//  Homework for data structure
//
//  Created by spencer  gause on 2/5/20.
//  Copyright © 2020 spencer  gause. All rights reserved.
//
#include "List.hpp"
#include <iostream>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    
    List linkedlist;
    /*
    srand (time(NULL));
    for(int x =0; x < 10; x++)
    {
        int nums = rand() % 100;
        linkedlist.appNode(nums);
    }
    */
    bool end = false;
    int nub;
    
    while(end != true)
    {
        std::cout << "enter digits to list and press -1 to end " << std::endl;
        std::cin >> nub;
        if(nub == -1)
        {
            end = true;
        }
        else
        {
           linkedlist.appNode(nub);
        }
        linkedlist.display();
        
    }
    end = false;
    nub = 0;
    int num;
    while(end != true)
    {
        std::cout << "enter 1 for mtf search and 2 for transpose search and press -1 to end " << std::endl;
        std::cin >> nub;
        switch(nub)
        {
            case -1:
                end = true;
                break;
            case 1:
                std::cout << "enter number to search" << std::endl;
                std::cin >> num;
                linkedlist.search_mtf(num);
                linkedlist.display();
                break;
            case 2:
                std::cout << "enter number to search" << std::endl;
                std::cin >> num;
                linkedlist.search_t(num);
                linkedlist.display();
                break;
            default:
                end = true;
                break;
        }
        
        
    }
    
    return 0;
}
