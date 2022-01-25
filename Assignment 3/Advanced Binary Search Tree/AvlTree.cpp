//
//  AvlTree.cpp
//  Avl Hmw2
//
//  Created by Spencer Gause on 4/24/20.
//  Copyright © 2020 Spencer Gause. All rights reserved.
//
#include <vector>
#include "AvlTree.hpp"
int bf = 0;
std::vector<AvlNode *> tog;
int balance =0;
int counter = 0;
int AvlTree::search(int x, AvlNode* n) const
{
    
    while (n->element != x)
    {
        if(n->element != x)
        {
            if (n->element > x)
            {
                n = n->right;
            }
            else
            {
                n = n->left;
            }
        }
    }
    return n->height;
}

void AvlTree::insert(const int x, AvlNode* r, AvlNode* n)
{
    
    if(r == nullptr)
    {
        
    }
    else if(x > r->element)
    {
        n->top = r;
        if(r->right == nullptr)
        {
            
            r->height++;
            n->element = x;
            r->right = n;
        }
        else
        {
            insert(x, r->right, n);
        }
    }
    else if(x < r->element)
    {
        n->top = r;
        if(r->left == nullptr)
        {
            
             r->height++;
            n->element = x;
            r->left = n;
        }
        else
        {
            insert(x, r->left, n);
        }
    }

    if(r != nullptr)
        n->height = 1 + max(height(n->left),height(n->right));
    
    AvlNode *p;
    p=n;
    if(n!= nullptr)
    {
        while((p->top->top!=nullptr))
        {
            
            int balance = getBalance(p);
            p = p->top;
            p->height = 1 + max(height(p->left),height(p->right));
        }
    }
    n=p;
    
    int balance = getBalance(r);
    if(n != nullptr)
    {
    if((balance > 1) && (n->left == nullptr))
    {
       // std::cout << "1";
        RL(n);
        
    }
    else if((balance > 1) && (n->right == nullptr))
    {
       // std::cout << "2";
        LL(n);
        
       
    }
    else if((balance < -1) && (n->left == nullptr))
    {
       // std::cout << "3";
        RR(n->top);
        
        
    }
    else if((balance < -1) && (n->right == nullptr))
    {
       // std::cout << "4";
        LR(n);
        
    }
    }
    
}

void AvlTree::LL(AvlNode *t)
{
    
    AvlNode *t1 = t->left;
    t1->top = t->top;
    t->left = t->right;
    t1->right = t;
    if(t->right != nullptr){
    t->height = max(t->left->height, t->right->height)+1;
    t1->height = max(t1->left->height, t1->left->height)+1;
    }
    
    t = t1;
    t->top->right = t;
}

void AvlTree::RR(AvlNode *t)
{
    AvlNode *t1 = t->right;
    t1->top = t->top;
    t->right = t->left;
    t1->left = t;
    if(t->right != nullptr){
    t->height = max(t->left->height, t->right->height)+1;
    t1->height = max(t->right->height,t->right->height) + 1;
    }
    t = t1;
    if(t->top != nullptr)
     t->top->left = t;
    
    
}

void AvlTree::LR(AvlNode *t)
{
    RR(t->left);
    LL(t);
}

void AvlTree::RL(AvlNode *t)
{
    
    RR(t->right);
    LL(t);
}

int AvlTree::max(int f, int s)
{
    int fin;
    if(f > s)
    {
        fin = f;
    }
    else
    {
        fin = s;
    }
    
    return fin;
}

void AvlTree::showAvlST(AvlNode* n)
{
    
   if(n != nullptr)
   {
  
       showAvlST(n->left);
       std::cout << n->element << " ";
       showAvlST(n->right);
       
   }
    
}

void AvlTree::display(std::vector<AvlNode *> t)
{
    for(int y =3 ; y>0; y--)
    {
    for(int x = 0; x < t.size(); x++)
    {
        
        if(y == t[x]->height)
        {
            std::cout << t[x]->element <<"\t\n";
        }
        
    }
    }
}

void AvlTree::showBF(AvlNode* n)
{
    
    if(n != nullptr)
      {
          showBF(n->left);
        std::cout << getBalance(n) << " ";
          showBF(n->right);
      }
   
    
}
int AvlTree::getBalance(AvlNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
int AvlTree::height(AvlNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
