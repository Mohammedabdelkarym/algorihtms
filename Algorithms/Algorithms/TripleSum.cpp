//
//  TripleSum.cpp
//  Algorithms
//
//  Created by Mohammed Abdelkarym on 11/16/14.
//  Copyright (c) 2014 mo7amedkhairy. All rights reserved.
//



/*
 thsi problem to find 3 integers which their sum is 0:
 it can be solved in two ways first one 3 nested loops to find all posiblilities but iit has complexity of N^3  which leads to 451 seconds to search list of 16K integer
 So we need to come up with better solution which has better complexity we can think in this way 
 the possiblities are 2 integers possitive and one negative or two integers negative and one possitive like this (a[i]+a[j]),-(a[i]+a[j])
 so we get a[i],a[j] cost n^2 then we search the -(a[i],a[j]) by binary search in the array which leads us to n^2log(N)
 */


#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
using namespace std;

class TripleSum
{
    
public:
    TripleSum()
    {
        numberOfObjects=32000;
        start();
    }
    
private:
    int* array;
    int numberOfObjects;
    time_t startingTime;
    time_t finishingTime;
    vector<int> vector;
    int numberOfValids=0;
    
    void initialize()
    {
        array=new int[numberOfObjects];
        int counter=0;
        while(counter<numberOfObjects){
            int x = -numberOfObjects + ( std::rand() % ( numberOfObjects + 1 ) );
            
            if(std::find(vector.begin(), vector.end(), x)==vector.end()){
                array[counter]=x;
                vector.push_back(x);
                counter++;
            }
        }
        std::sort(array, array+numberOfObjects);
    }
    
    bool binarySearch(int number)
    {
        int min=0;
        int max=numberOfObjects-1;
        int mid;
        
        while (min<max) {
            mid=min+(max-min)/2;
            if(number == array[mid])
                return true;
            if(number < array[mid])
                max=mid-1;
            else min=mid+1;
        }
        return false;
    }
    
    void findNumbers()
    {
        for(int i=0;i<numberOfObjects;i++)
        {
            for (int j=i+1; j<numberOfObjects; j++)
            {
                if(binarySearch(-(array[i]+array[j])))
                {
                    numberOfValids++;
                    //cout<<array[i]<<"   "<<array[j]<<"  "<<-(array[i]+array[j])<<endl;
                }
            }
        }
    }
    
    void printResult()
    {
        std::cout<<"**************************************************Quick Find*********************************************************************"<<std::endl;
        double timeTook=difftime(finishingTime,startingTime);
        
        std::cout<<"Count : "<<numberOfValids<<" Starting Time : "<<startingTime<<" finishingTime: "<<finishingTime<<" Time took is : "<<timeTook<<std::endl;
        
        std::cout<<std::endl;
    }
    
    void start()
    {
        initialize();
        
        
        initialize();

        startingTime=time(0);

        findNumbers();
        
        finishingTime=time(0);
        
        printResult();        
    }
};
