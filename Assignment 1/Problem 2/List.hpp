//
//  List.hpp
//  Homework for data structure
//
//  Created by spencer  gause on 2/16/20.
//  Copyright © 2020 spencer  gause. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <cstdlib>
#include <iostream>
#include <stdio.h>
class List
{
    
private:
    struct node{int num; node* next;};
    
    node* head;
    node* now;
    node* temp;
    bool found;
    
public:
    List();
    void appNode(int n);
    void display();
    
    void search(int s);
    void search_mtf(int t);
    void search_t(int r);

};
#endif /* List_hpp */
