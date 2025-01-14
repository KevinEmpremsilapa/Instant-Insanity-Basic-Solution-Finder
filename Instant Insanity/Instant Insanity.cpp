// Instant Insanity.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

void addToThreadArray(int[], int, int, int&, int&, int&);
void initializeThread(int[], int);
void addThreadToListOfThreads(int [], int [], int, int&);

using namespace std;
const int sizeOfThread = 8;
const int sizeOfAllThreas = 24;
int main()
{
	// Used for testing
	int arr[] = { 1,2,3,4 };
	//Undetermined use. Intended as a counter just forgot how I was going to use it.
	int k = 0;

	// Used to store all found threads
	int listOfThreads[sizeOfAllThreas];
	int numOfThreads = 0;
	// Used for finding threads though our cubes
	int thread[sizeOfThread];
	int threadIndex = 0;

	// This is our problem.
	// Having 4 cubes with 6 different sides.
	int cubes[4][6] = { {155, 2, 2, 4, 3, 3},
						{2, 1, 4, 2, 3, 3},	
						{2, 2, 3, 3, 2, 2},
						{4, 4, 4, 3, 1, 1} };

	// Used for keeping track fo the cubes[][] row that you are on. Also represents the cube # that you are working with.
	int row = 0;
	// Used for keeping track of the cubes[][] column you are on. Also represents the side color of the cube.
	int col = 0;

	// Sets every element of the thread array set to -1
	initializeThread(thread, sizeOfThread);
	initializeThread(listOfThreads, sizeOfAllThreas);
	
	do {
		// The first number of a given pair.
		int first = cubes[row][col];
		// The second number of a given pair.
		int second = cubes[row][col + 1];

		// Prints current row and column.
		//cout << row << col << threadIndex << endl; 

		// Call to to see if the piar (first, second) can be added.
		addToThreadArray(thread, first, second, row, col, threadIndex);

		// Prints current row and column.
		//cout << row << col << threadIndex << endl;
		if (thread[sizeOfThread-1] != -1)
		{
			cout << "hi\n";
			addThreadToListOfThreads(listOfThreads, thread, sizeOfThread, numOfThreads);
			// For testing
			int size = numOfThreads * 6;
		for (int i = 0; i <= size; i+=2)
				cout << "(" << listOfThreads[i] << ", " << listOfThreads[i + 1] << ")"<< endl;
		}

		// Undetermined use. Intended as a counter just forgot how I was going to use it.
		// Is initialized above the do{...}while loop.
		k++;
	} while (thread[sizeOfThread-1] == -1);

	// Prints current row and column.
	//cout << row << col << threadIndex << endl;




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

	// Prints current row and column.
	//cout << row << col << tIndex << endl;

	for (int j = 0; j < sizeOfThread; j++)
	{
		if (threadArr[j] == first)
			fcount += 1;
		if (threadArr[j] == second)
			scount += 1;
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
	cout << endl;
}
void addThreadToListOfThreads(int listOfThreads[], int thread[], int sizeOfThread, int &numOfThreads) {
	numOfThreads++;
	sizeOfThread = numOfThreads * sizeOfThread;
	for (int i = 0; i < sizeOfThread; i++)
	{
		listOfThreads[i] = thread[i];
		//cout << listOfThreads[i] << ", " << listOfThreads[i + 1] << endl;
	}
}