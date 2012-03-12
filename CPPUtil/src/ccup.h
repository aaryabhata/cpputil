/*
 * ccup.cpp
 *
 *  Created on: Mar 11, 2012
 *      Author: kondav2
 */

#include<iostream>
using namespace std;

void spiralTraverse(int array[5][5], int rows, int cols, int depth){

	if (rows <= 0 || cols <=0){
		return;
	}

	if(rows == 1)
	{
		for(int i=0; i<cols; i++)
			cout<<array[depth][depth+i];
		return;
	}

	if (cols == 1){
		//no cols to  print

		for(int i=0; i<rows; i++)
			cout<<array[depth+i][depth];
		return;
	}

	for(int i=0; i<cols-1; i++)
	{
		cout<<" "<<array[depth][depth+i];
	}

	for(int i=0; i<rows-1; i++)
	{
		cout<<" "<<array[depth+i][depth+cols-1];
	}

	for(int i=0; i<cols-1; i++)
	{
		cout<<" "<<array[depth+rows-1][depth+cols-1-i];
	}

	for(int i=0; i<rows-1; i++)
	{
		cout<<" "<<array[depth+rows-1-i][depth];
	}

	cout<<" \n ";
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

