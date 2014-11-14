//
//  QuickUnion.cpp
//  Algorithms
//
//  Created by Mohammed Abdelkarym on 11/13/14.
//  Copyright (c) 2014 mo7amedkhairy. All rights reserved.
//

/*
 Lazzy approcach
 It can be worse if there is only one tall skinny tree
 or better if small short trees
 */

#include <iostream>
#include <ctime>

using namespace std;

class QuickUnion
{
    
public:
    QuickUnion()
    {
        numberOfObjects=10;
        start();
    }
    
private:
    int* array;
    int numberOfObjects;
    time_t startingTime;
    time_t finishingTime;
    
    void initialize()
    {
        array=new int[numberOfObjects];
        for(int i=0; i<numberOfObjects; i++){
            array[i]=i;
        }
        
    }
    
    int root(int n)
    {
        while (array[n]!=n)n=array[n];
            
        return n;
    }
    
    bool connected(int p,int q)
    {
        //CHECK TO SEE IF THEY HAVE SAME ROOT
        return root(p)==root(q);
    }
    
    void connect(int p,int q){
        
        int pRoot=root(p);
        int qRoot=root(q);
        
        if(pRoot!=qRoot)array[pRoot]=qRoot;
    }
    
    void printResult()
    {
        std::cout<<"**************************************************Quick Union*********************************************************************"<<std::endl;
        double timeTook=difftime(finishingTime,startingTime);
        
        std::cout<<"Starting Time : "<<startingTime<<" finishingTime: "<<finishingTime<<" Time took is : "<<timeTook<<std::endl;
        std::cout<<"Resut : "<<std::endl;
        
        for(int i=0;i<numberOfObjects;i++){
            std::cout<<array[i]<<"    ";
        }
        
        std::cout<<std::endl;
    }
    
    void start()
    {
        initialize();
        
        startingTime=time(0);
        connect(4, 3);
        connect(3, 8);
        connect(6, 5);
        connect(9, 4);
        connect(2, 1);
        connect(8, 9);
        connect(5, 0);
        connect(7, 2);
        connect(6, 1);
        connect(7, 3);
        finishingTime=time(0);
        
        printResult();
        
    }
};