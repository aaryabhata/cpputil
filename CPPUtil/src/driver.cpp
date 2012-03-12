#include "sortAlgos.h"
#include "listAlgos.h"
#include "urldecode.h"
#include "MaxWindow.h"
#include <iostream>
#include "ccup.h"

using namespace std;
int main(){
	cout<<"hello"<<endl;
	//listAlgosDriver();
	/*unsigned int input[] = {5,4,2,1}; //provide the inputlist here

	    cout<<maxWindowBruteForce(input, sizeof(input)/sizeof(input[0]))<<endl;
	    cout<<maxWindowOrderN(input, sizeof(input)/sizeof(input[0]))<<endl;
	    cout<<maxWindowOrderNWithLists(input, sizeof(input)/sizeof(input[0]))<<endl;
*/
	int array[5][5] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 },
			{ 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };

	spiralTraverse((int**)array,5,5,0);
	cout<<"world";
	return 0;
}
