//
//  List.cpp
//  Homework for data structure
//
//  Created by spencer  gause on 2/16/20.
//  Copyright © 2020 spencer  gause. All rights reserved.
//

#include "List.hpp"

List::List()
{
    head = NULL;
    
}

void List::appNode(int n)
{
    bool repeat = false;
    node* newNode = new node;
    newNode->next = NULL;
    newNode->num = n;
    
    if(head != NULL)
    {
        now = head;
        
        while(now->next != nullptr)
        {
            if(now->num == n)//this is broken
            {
                repeat = true;
            }
            
            now = now->next;
            
        }
        
        if(repeat == false)
        {
            now->next = newNode;
        }
        else
        {
            std::cout << "That number is already within the list" << std::endl;
        }
        
    }
    else
    {
        head = newNode;
    }
}

void List::display()
{
    now = head;
    while(now != NULL)
    {
        std::cout << now->num << " -> ";
        now = now->next;
    }
    std::cout << "Null" << std::endl;
}

void List::search(int s)
{
    int counter =0;
    now = head;
    while(now->num != s)
    {
        std::cout << now->num << std::endl;
        now = now->next;
        counter++;
    }
    std::cout << "The number " << s << " was found at position " << counter << std:: endl;
}

void List::search_mtf(int t)
{
    temp = now;
    now = head;
    while (now != NULL)
    {
        found = false;
        if(now->num == t)
        {
            if(temp != NULL)
            {
                temp->next = now->next;
                now->next = head;
                head = now;
            }
            found= true;
        }
        else
        {
            
        }
        
        
        temp=now;
        now = now->next;
    }
    
    
    if(found==true)
    {
      std::cout << "The number " << t << " was found" << std:: endl;
    }
    else
    {
        std::cout << "The number " << t << " was NOT found" << std:: endl;
    }
    

}

void List::search_t(int r)
{
    
    int g;
    temp = now;
    now = head;
    while (now != NULL)
    {
        found = false;
        if(now->num == r)
        {
            if(temp != NULL)
            {
                g = temp->num;
                temp->num = now->num;
                now->num = g;
                
            }
            found = true;
            
        }
        else
        {
            
        }
        temp = now;
        now = now->next;
    }
    
    if(found==true)
    {
      std::cout << "The number " << r << " was found" << std:: endl;
    }
    else
    {
        std::cout << "The number " << r << " was NOT found" << std:: endl;
    }
    
}

