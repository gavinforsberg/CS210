//
//  AvlTree.hpp
//  Avl Hmw2
//
//  Created by Spencer Gause on 4/24/20.
//  Copyright © 2020 Spencer Gause. All rights reserved.
//

#ifndef AvlTree_hpp
#define AvlTree_hpp

#include <stdio.h>
#include <iostream>
#include "AvlNode.hpp"
class AvlTree
{
public:

    
    int search(int x, AvlNode* n) const;
    void printAvlTree() const;
    void insert(const int x , AvlNode* r, AvlNode* n);
    void destroy(const int x);
    void showAvlST(AvlNode* n);
    void showBF(AvlNode* n);
    void display(std::vector<AvlNode *>);
    int getBalance(AvlNode *N);
    int height(AvlNode *N);
    
    void LL(AvlNode *t);
    void RR(AvlNode *t);
    void LR(AvlNode *t);
    void RL(AvlNode *t);
    
    int max(int f, int s);
    
private:
    AvlNode *root;
};


#endif /* AvlTree_hpp */
