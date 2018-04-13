// Instant Insanity.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

void addToThreadArray(int[], int, int, int&, int&, int&);
void initializeThread(int[], int);
using namespace std;
const int sizeOfThread = 8;
int main()
{
	int thread[sizeOfThread];
	int threadIndex = 0;

	int arr[] = { 1,2,3,4 };
	int cubes[4][6] = { {155, 2, 2, 4, 3, 3},
						{2, 1, 4, 2, 3, 3},
						{3, 3, 3, 4, 2, 2},
						{4, 4, 4, 3, 1, 1} };
	int row = 0;
	int col = 0;

	initializeThread(thread, sizeOfThread);
	int k = 0;

	do {
		int first = cubes[row][col];
		int second = cubes[row][col + 1];
		cout << row << col << threadIndex << endl;

		addToThreadArray(thread, first, second, row, col, threadIndex);
		cout << row << col << threadIndex << endl;
		k++;
	} while (thread[sizeOfThread-1] == -1);
	cout << row << col << threadIndex << endl;




	cout << endl << endl << endl;
	system("pause");
    return 0;
}
void initializeThread(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = -1;
}
void addToThreadArray(int threadArr[], int first, int second, int &row, int &col, int &tIndex)
{
	int fcount=0;
	int scount=0;
	cout << row << col << tIndex << endl;

	for (int j = 0; j < sizeOfThread; j++)
	{
		//if (first != second)
		//{
			if (threadArr[j] == first)
				fcount += 1;

			if (threadArr[j] == second)
				scount += 1;
		//}
	}
	
	if (first != second)
	{
		if (fcount < 2 && scount < 2)
		{
			threadArr[tIndex] = first;
			threadArr[tIndex + 1] = second;
			tIndex = tIndex + 2;
			row = row + 1;
			col = 0;

		}
		else if (fcount >= 2 || scount >= 2)
		{
			row = row;
			col = col + 2;
		}
	}
	if (first == second)
	{
		if (fcount == 0 && scount == 0)
		{
			threadArr[tIndex] = first;
			threadArr[tIndex + 1] = second;
			tIndex = tIndex + 2;
			row = row + 1;
			col = 0;

		}
		else if (fcount > 0 || scount > 0)
			col = col + 2;
	}

	for (int j = 0; j < sizeOfThread; j+=2)
	{
		if (j <= (sizeOfThread))
		cout << threadArr[j] << ", " << threadArr[j + 1] << endl;
	}
}
