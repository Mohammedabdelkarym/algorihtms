//
//  QuickUnionWeightedTree.cpp
//  Algorithms
//
//  Created by Mohammed Abdelkarym on 11/13/14.
//  Copyright (c) 2014 mo7amedkhairy. All rights reserved.
//

#include <stdio.h>

/*
 Lazzy approcach
 Imporvement one :make the tree wieghted with (log n) height so big o for union is log N and to check connection is log N
 finding root should be considered
 'depth of any node is at most log N
 
 caution this algo depends on size of tree not height or rank
 */

#include <iostream>
#include <ctime>

using namespace std;

class QuickUnionWeightedTree
{
    
public:
    QuickUnionWeightedTree()
    {
        numberOfObjects=10;
        start();
    }
    
private:
    int* array;
    int* treeSizesArray;
    int numberOfObjects;
    time_t startingTime;
    time_t finishingTime;
    
    void initialize()
    {
        array=new int[numberOfObjects];
        treeSizesArray=new int[numberOfObjects];
        for(int i=0; i<numberOfObjects; i++){
            array[i]=i;
            treeSizesArray[i]=1;
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
        
        if(pRoot!=qRoot){
            if(treeSizesArray[pRoot]>=treeSizesArray[qRoot]){
                array[pRoot]=qRoot;treeSizesArray[qRoot]+=treeSizesArray[pRoot];
            }else{
                array[qRoot]=pRoot;treeSizesArray[pRoot]+=treeSizesArray[qRoot];
            }
        }
    }
    
    void printResult()
    {
        std::cout<<"***********************************************Quick Union improvement one weigted tree*****************************************************************"<<std::endl;
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