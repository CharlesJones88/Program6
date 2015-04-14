//
//  Sort.cpp
//  Program 6
//
//  Created by Charles Jones on 11/2/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//

#include "Sort.h"

Sort::Sort()
{
    value = nullptr;
    count = 0;
}

void Sort::insert(int data[], int n)
{
	count = n;
	int temp, j;
	value = new int[count];
	for (int i = 0; i < count; i++)
		value[i] = data[i];
	for (int i = 1; i < count; i++)
	{
		j = i;
		while (j > 0 && value[j - 1] > value[j])
		{
			temp = value[j];
			value[j] = value[j - 1];
			value[j - 1] = temp;
			j--;
		}
	}
}

void Sort::shell(int data[], int n)
{
	count = n;
	value = new int[count];
    for(int i = 0; i < count; i++)
        value[i] = data[i];
    int d, temp, flag = 1;
    d = count;
    while(flag != 0 || (d > 1))
    {
        flag = 0;
        d = (d + 1) / 2;
        for(int i = 0; i < count - d; i++)
        {
            if(value[i] > value[i + d])
            {
                temp = value[i];
                value[i] = value[i + d];
                value[i + d] = temp;
                flag = 1;
            }
        }
    }
}

void Sort::quick(int data[], int n)
{
    count = n;
    value = new int[count];
	int top = 0;
    for(int i = 0; i < count; i++)
        value[i] = data[i];
    quickHelper(value, top, count - 1);
}

void Sort::quickHelper(int *data, int top, int bottom)
{
	int mid = partition(data, top, bottom);
    if(top < mid - 1)
		quickHelper(data, top, mid - 1);
	if (mid < bottom)
		quickHelper(data, mid, bottom);
}

int Sort::partition(int *data, int top, int bottom)
{
    int pivot = data[(top + bottom) / 2];

	while (top <= bottom)
    {
		while (data[top] < pivot)
			top++;
		while (data[bottom] > pivot)
			bottom--;
        if(top <= bottom)
        {
            int tempVal = data[top];
            data[top] = data[bottom];
            data[bottom] = tempVal;
			top++;
			bottom--;
        }
	} 
    
	return top;
}


void Sort::write(ofstream& out) const
{
    for(int i = 0; i < count; i++)
        out << value[i] << endl;
}

void Sort::clear()
{
    delete[] value;
    value = nullptr;
    count = 0;
}

Sort::~Sort()
{
	clear();
}