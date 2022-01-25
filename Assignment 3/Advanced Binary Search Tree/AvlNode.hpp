//
//  AvlNode.hpp
//  Avl Hmw2
//
//  Created by Spencer Gause on 4/24/20.
//  Copyright © 2020 Spencer Gause. All rights reserved.
//

#ifndef AvlNode_hpp
#define AvlNode_hpp

#include <stdio.h>
class AvlNode
{
public:
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode();
    
    AvlNode(const int el, AvlNode *pt, AvlNode *rt):element(el),left(pt),right(rt),height(1),top(nullptr){}
    
    friend class AvlTree;
private:
    AvlNode* top;
};
#endif /* AvlNode_hpp */
