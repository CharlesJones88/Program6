//
//  main.cpp
//  Program 6
//
//  Created by Charles Jones on 11/2/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <vector>
#include "Sort.h"

using namespace std;

int file[] = {1, 2, 3};
string insertSrt[] = {"I1", "I2", "I3"};
string shellSrt[] = {"S1", "S2", "S3"};
string quickSrt[] = {"Q1", "Q2", "Q3"};
int fileNum = 0;
const int POINT = 3;

//The print function
//Purpose: Prints out the results of the different sorts
//Parameters: int array, int, Sort reference
//Returns: none
void printInsert(int[], int, Sort&);
void printShell(int[], int, Sort&);
void printQuick(int[], int, Sort&);

int main() {
    Sort srtInsert;
    Sort srtShell;
    Sort srtQuick;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(POINT);
	int* dataOne;
	int* dataTwo;
	int* dataThree;
    int countOne = 0;
    int countTwo = 0;
    int countThree = 0;
    vector<int> storeOne;
    vector<int> storeTwo;
    vector<int> storeThree;
    ifstream fileOneRead;
    ifstream fileTwoRead;
    ifstream fileThreeRead;
    string fileOneName;
    string fileTwoName;
    string fileThreeName;
    int value;
    cout << "Charles Jones\nCS2420 Section 002\nProgram 6 - Sorting" << endl;
    cout << "Enter in the first file name: ";
    cin >> fileOneName;
    cout << "Enter in the second file name: ";
    cin >> fileTwoName;
    cout << "Enter in the third file name: ";
    cin >> fileThreeName;
    cout << "\t\t\tNUMBER\tELAPSED\t\tELAPSED\t\t SORTED" << endl;
    cout << "SORT\t\tFILE#\t ITEMS\t CLOCK\t\t TIME\t\tFILE NAME\n---------\t-----\t------\t--------\t--------\t----------" << endl;
    fileOneRead.open(fileOneName);
    if(fileOneRead.fail())
    {
        cout << "Failed to open file " << fileOneName << ". Terminating program." << endl;
        fileOneRead.close();
        system("pause");
        exit(EXIT_FAILURE);
    }
    
    while(fileOneRead >> value)
    {
        storeOne.push_back(value);
        countOne++;
    }
    dataOne = new int[countOne];
    for(int i = 0; i < storeOne.size(); i++)
        dataOne[i] = storeOne.at(i);
    
    printInsert(dataOne, countOne, srtInsert);
    srtInsert.clear();
    printShell(dataOne, countOne, srtShell);
    srtShell.clear();
    printQuick(dataOne, countOne, srtQuick);
    srtQuick.clear();
    cout << endl;

    fileTwoRead.open(fileTwoName);
    if(fileTwoRead.fail())
    {
        cout << "Failed to open file " << fileTwoName << ". Terminating program." << endl;
        fileTwoRead.close();
        system("pause");
        exit(EXIT_FAILURE);
    }
    while(fileTwoRead >> value)
    {
        storeTwo.push_back(value);
        countTwo++;
    }
    dataTwo = new int[countTwo];
    for(int i = 0; i < storeTwo.size(); i++)
        dataTwo[i] = storeTwo.at(i);
    
    printInsert(dataTwo, countTwo, srtInsert);
    srtInsert.clear();
    printShell(dataTwo, countTwo, srtShell);
    srtShell.clear();
    printQuick(dataTwo, countTwo, srtQuick);
    srtQuick.clear();
    cout << endl;
    
    fileThreeRead.open(fileThreeName);
    if(fileThreeRead.fail())
    {
        cout << "Failed to open file " << fileThreeName << ". Terminating program." << endl;
        fileThreeRead.close();
        system("pause");
        exit(EXIT_FAILURE);
    }
    while(fileThreeRead >> value)
    {
        storeThree.push_back(value);
        countThree++;
    }
    dataThree = new int[countThree];
    for(int i = 0; i < storeThree.size(); i++)
        dataThree[i] = storeThree.at(i);
    
    printInsert(dataThree, countThree, srtInsert);
    srtInsert.clear();
    printShell(dataThree, countThree, srtShell);
    srtShell.clear();
    printQuick(dataThree, countThree, srtQuick);
    srtQuick.clear();
    cout << endl;
	delete[] dataOne;
	delete[] dataTwo;
	delete[] dataThree;
	fileOneRead.close();
    fileTwoRead.close();
    fileThreeRead.close();
    system("pause");
    return 0;
}

void printInsert(int data[], int n, Sort& srt)
{
    ofstream fileWrite;
    double start;
    double end;
    clock_t elapsedClock;
    double elapsedTime;
    start = clock();
    srt.insert(data, n);
    end = clock();
    elapsedClock = end - start;
    elapsedTime = ((end - start) / CLK_TCK);
    cout << "Insertion\t" << setw(5) << right << file[fileNum] << "\t" << setw(6) << right << n << "\t" << setw(8) << right << elapsedClock << "\t" << setw(8) << right << elapsedTime << "\t\t" << setw(2) << right << insertSrt[fileNum] << endl;
    fileWrite.open(insertSrt[fileNum] + ".txt");
    srt.write(fileWrite);
    fileWrite.close();
}

void printShell(int data[], int n, Sort& srt)
{
    ofstream fileWrite;
    double start;
    double end;
    clock_t elapsedClock;
    double elapsedTime;
    start = clock();
    srt.shell(data, n);
    end = clock();
    elapsedClock = end - start;
    elapsedTime = ((end - start) / CLK_TCK);
    cout << "Shellsort\t" << setw(5) << right << file[fileNum] << "\t" << setw(6) << right << n << "\t" << setw(8) << right << elapsedClock << "\t" << setw(8) << right << elapsedTime << "\t\t" << setw(2) << right << shellSrt[fileNum] << endl;
    fileWrite.open(shellSrt[fileNum] + ".txt");
    srt.write(fileWrite);
    fileWrite.close();
}

void printQuick(int data[], int n, Sort& srt)
{
    ofstream fileWrite;
    double start;
    double end;
    clock_t elapsedClock;
    double elapsedTime;
    start = clock();
    srt.quick(data, n);
    end = clock();
    elapsedClock = end - start;
    elapsedTime = ((end - start) / CLK_TCK);
    cout << "Quicksort\t" << setw(5) << right << file[fileNum] << "\t" << setw(6) << right << n << "\t" << setw(8) << right << elapsedClock << "\t" << setw(8) << right << elapsedTime << "\t\t" << setw(2) << right << quickSrt[fileNum] << endl;
    fileWrite.open(quickSrt[fileNum] + ".txt");
    srt.write(fileWrite);
    fileWrite.close();
    fileNum++;
}