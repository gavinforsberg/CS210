//
//  main.cpp
//  Avl Hmw2
//
//  Created by Spencer Gause on 4/24/20.
//  Copyright © 2020 Spencer Gause. All rights reserved.
//

#include <iostream>
#include "AvlTree.hpp"
int main(int argc, const char * argv[]) {
    
   
    AvlTree pine;
    AvlNode needle = AvlNode(15,nullptr,nullptr);
    
    AvlNode p2;
    AvlNode p3;
    AvlNode p4;
    AvlNode p5;
    
    pine.insert(78, &needle, &p2);
    pine.insert(9, &needle, &p3);
    pine.insert(60, &needle, &p4);
    pine.insert(36, &needle, &p5);

    std::cout << "inorder level" << std::endl;
    pine.showAvlST(&needle);
    std::cout<<std::endl;
    std::cout << "balance factor" << std::endl;
    pine.showBF(&needle);
    /*
    AvlTree elk;
    AvlNode sap = AvlNode(2,nullptr,nullptr);
    
    AvlNode s2;
    AvlNode s3;
    AvlNode s4;
    AvlNode s5;
    AvlNode s6;
    
    elk.insert(5, &sap,&s2);
    elk.insert(1, &sap,&s3);
    elk.insert(4, &sap,&s4);
    elk.insert(3, &sap,&s5);
    elk.insert(6, &sap,&s6);
    std::cout << "inorder level" << std::endl;
   // elk.showAvlST(&s4);
    std::cout << "balance factor" << std::endl;
    std::cout <<std::endl;
   // elk.showBF(&sap);
*/
    
    /*
    AvlTree redwood;
    AvlNode root = AvlNode(4,nullptr,nullptr);
    redwood.insert(root.element, nullptr, nullptr);
    
    AvlNode node2;
    AvlNode node3;
    AvlNode node4;
    AvlNode node5;
    AvlNode node6;
    
    redwood.insert(10, &root,&node2);
    redwood.insert(3, &root,&node3);
    redwood.insert(6, &root,&node4);
    redwood.insert(5, &root,&node5);
    redwood.insert(25, &root,&node6);
    std::cout << "Reverse in-order tree treversal."<<std::endl;
    redwood.showAvlST(&node4);
    std::cout << std::endl;
    std::cout << "balance values"<<std::endl;
    redwood.showBF(&node4);
     */
    
    //std::cout << root.height << std::endl;
    //redwood.showAvlST(&root);
    //redwood.search(5, &root);
  /*
    AvlTree oak;
    AvlNode plant = AvlNode(10,nullptr,nullptr);
    oak.insert(plant.element, nullptr, nullptr);
    
    AvlNode n2;
    AvlNode n3;
    AvlNode n4;
    AvlNode n5;
    AvlNode n6;
    AvlNode n7;
    
    oak.insert(20, &plant,&n2);
    oak.insert(30, &plant,&n3);
    oak.insert(40, &plant,&n4);
    oak.insert(50, &plant,&n5);
    oak.insert(60, &plant,&n6);
    oak.insert(70, &plant,&n7);
    */
    //oak.showAvlST(&n4);
    //oak.showBF(&n4);

}
