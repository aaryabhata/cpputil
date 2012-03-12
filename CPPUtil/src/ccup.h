/*
 * ccup.cpp
 *
 *  Created on: Mar 11, 2012
 *      Author: kondav2
 */

#include<iostream>
using namespace std;

void spiralTraverse(int** array, int rows, int cols, int depth){

	if (rows <= 0 || cols <=0){
		return;
	}

	if(rows == 1)
	{
		for(int i=depth; i<cols; i++)
			cout<<array[0][i];
		return;
	}

	if (cols == 1){
		//no cols to  print

		for(int i=depth; i<rows; i++)
			cout<<array[i][0];
		return;
	}

	for(int i=depth; i<cols; i++)
	{
		cout<<array[rows-1][i];
	}

	for(int i=depth+1; i<rows; i++)
	{
		cout<<array[i][cols-1];
	}

	for(int i=depth+1; i<cols; i++)
	{
		cout<<array[rows-1][cols-1-i];
	}

	for(int i=depth+1; i<rows; i++)
	{
		cout<<array[rows-1-i][cols-1];
	}

	spiralTraverse(array, rows-2, cols-2, depth+1);

	/*
	for(int i=0; i< rows; i++)
	{
		for(int j=0; j< cols; j++)
		{
			cout<<array[i][j]<<" ";

		}
		cout<<endl;
	}
	*/
}

