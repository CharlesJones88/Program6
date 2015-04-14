//
//  Sort.h
//  Program 6
//
//  Created by Charles Jones on 11/2/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//
#include <iostream>
#include <fstream>

using namespace std;

class Sort
{
private:
    int* value;
    int count;
public:
    Sort();
    
    //The insert function
    //Purpose: Performs an insert sort
    //Parameters: int array and an int
    //Returns: none
    void insert(int[], int);
    
    //The shell function
    //Purpose: Performs a shell sort
    //Paramters: int array and an int
    //Returns: none
    void shell(int[], int);
    
    //The quick function
    //Purpose: Performs a quick sort
    //Parameters: int array and an int
    //Returns: none
    void quick(int[], int);
    
	//The quickHelper function
	//Purpose: Helps with recursion for the quick sort
	//Parameters: int pointer, int and an int
	//Returns: none
    void quickHelper(int*, int, int);
    
    //The partition function
    //Purpose: Performs a partition on the quick sort
    //Parameters: int pointer, int and an int reference
    //Returns: int
    int partition(int*, int, int);
    
	//The write function
	//Purpose: Writes out all the elements from the sort into their own files.
	//Parameters: ofstream reference
	//Returns: none
    void write(ofstream&) const;
    
	//The clear function
	//Purpose: deletes value and sets count to 0
	//Parameters: none
	//Returns: none
    void clear();
    
    ~Sort();
};
