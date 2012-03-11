#include "sortAlgos.h"
#include "listAlgos.h"
#include "urldecode.h"
#include "MaxWindow.h"
#include <iostream>
#include "ccup.h"

using namespace std;
int main() {
	cout << "hello" << endl;
	//listAlgosDriver();
	unsigned int input[] = { 1, 5, 2, 4 }; //provide the inputlist here

	cout << maxWindowBruteForce(input, sizeof(input) / sizeof(input[0]))
			<< endl;
	cout << maxWindowOrderN(input, sizeof(input) / sizeof(input[0])) << endl;
	cout << maxWindowOrderNWithLists(input, sizeof(input) / sizeof(input[0]))
			<< endl;

	return 0;
}
