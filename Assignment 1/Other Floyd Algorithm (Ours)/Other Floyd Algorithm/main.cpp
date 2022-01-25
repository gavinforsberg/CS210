//
//  main.cpp
//  Other Floyd Algorithm
//
//  Created by Gavin Forsberg on 2/21/20.
//  Copyright © 2020 Gavin Forsberg. All rights reserved.
//

// CS210HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
 Dynamic Programming-based Floyd-Warshall Algorithm for the All-Pairs Shortest Path Problem
 Chapter 3 exercise #8

 You should output the distance array D, the path array P
 and hte shortest paths. Test your implementation using (1)
 the test case given in class and (2) your own test cases including
 diagraphs iwth non-negative edes only and diagraphs with some
 negative edges.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int sizeA = 5;
void floyd2(int n, const int W[sizeA][sizeA], int D[sizeA][sizeA], int P[sizeA][sizeA]);

int main()
{
    //test scenario
    int max = 9000;
                //  1  2   3      4   5
    int W[5][5] = { 0, 1, max, 1, 5,
        /*2*/        9, 0, 3, 2, max,
        /*3*/        max, max, 0, 4, max,
        /*4*/        max, max, 2, 0, 3,
        /*5*/        3, max, max, max, 0};
    int P[5][5] = {};
    int D[5][5] = {};
    int n = 5;
    
    
    floyd2(n, W, D, P);
    
    
    
    //print P and D
    cout << "W" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(15) << W[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    
    cout << "P" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << P[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "D" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
}
    void floyd2(int n, const int W[sizeA][sizeA], int D[sizeA][sizeA], int P[sizeA][sizeA])
    {
        // initializing P
        int i, j, k = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                P[i][j] = 0;
        
        //initializing D
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                D[i][j] = W[i][j];


        //Updating P and D based on shortest path
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 1; j < n; j++)
                {
                    if ((D[i][k] + D[k][j]) < D[i][j])
                    {
                        P[i][j] = k;
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }
    }
    
