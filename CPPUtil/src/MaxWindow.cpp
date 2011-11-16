#include <iostream>
#include <list>

using namespace std;

/*
* Brute force method
* Time Complexity:
* inplace: space complexity 0(1)
* worst case runtime: O(n^2)
*/
int maxWindowBruteForce(unsigned int* input, int size)
{
    int maxWindow = 0;

    for(int i = 0; i < size; i++)
    {
        /* Only consider till i+CurrentMax */
        for (int j = size-1; j > i + maxWindow; j--)
            if ( input[j] > input[i] && (j-i > maxWindow))
                maxWindow = j-i;
    }

    return maxWindow;               
}

/**
* To maximize j-i.. we need to maximize j and minimize i The candidates 
* to consider for i are those for which there is no i' such that A[i']<A[i] 
* and i'< i because if such a i' exists we can replace i with i' and get a 
* better solution. Similarly the candidates for j are those for which there 
* is no j' such that A[j'] > A[j] and j' > j
* Complexity: Time O(n) Space O(n)
*/

int maxWindowOrderN(unsigned int* input, int size)
{
    int i,j;
    int maxWindow = 0;

    
    unsigned int* iArr = new unsigned int[size]; 
    unsigned int* jArr = new unsigned int[size]; 

    //iArr[i] will store the min(input[0],...input[i]
    iArr[0] = input[0];
    for (i = 1; i < size; i++)
    {
        iArr[i] = (input[i]< iArr[i-1])? input[i] : iArr[i-1];
    }

     //jArr[i] will store the max(input[i],...input[size-1]
    jArr[size-1] = input[size-1];
    for (j = size-2 ; j >= 0; j--)
    {
        jArr[j] = (input[j] > jArr[j+1])? input[j] : jArr[j+1];
    }

    //This method depending on the input can store many duplicates in
    //these two lists. The next method optimizes this part

    //Now we can find the max window from the above two sorted arrays
    //(one has values corresponding to i and other has values corresponding to 
    // j) starting at beginning of two arrays
    
    i=0, j=0;
    while(i < size && j < size)
    {
        if (jArr[j] > iArr[i])
        {
            if(j-i > maxWindow)
                maxWindow = j-i;
            j++; //increment j
        }
        else
            i++;
    }

    delete [] iArr;
    delete [] jArr;


    return maxWindow;
}

/**
* In this method instead of storing the members of input arrays,
* unique possible indices of i and j are stored in two auxillary lists.
* The last step is also optimized because the two lists will have
* fewer elements
* Complexity: Time O(n) Space O(n)
*/
int maxWindowOrderNWithLists(unsigned int* input, int size)
{
    int i,j;
    int maxWindow = 0;

    
    list<unsigned int> iArr;  
    list<unsigned int> jArr;

    //list iArr stores the possible unique values of i
    iArr.push_back(0);
    for(i = 1; i < size; i++)
    {
        if(input[i] < input[iArr.back()])
            iArr.push_back(i);
    }

    //list jArr stores the possible unique values of j
    jArr.push_front(size-1);
    for (j = size-2 ; j >= 0; j--)
    {
        if (input[j] > input[jArr.front()])
            jArr.push_front(j);
    }

    //Both the lists are sorted in ascending order..
    list<unsigned int>::iterator it1 = iArr.begin(), it2 = jArr.begin();

    while ( it1 != iArr.end() && it2 != jArr.end())
    {
        if (*it2 - *it1 > 0 && input[*it2]>input[*it1])
        {
            maxWindow = (signed)(*it2 - *it1) > maxWindow ? (*it2 - *it1) : maxWindow;
            it2++;
        }
        else
        {
            it1++;
        }
    }
    return maxWindow;
}
/*
* driver program

int main(){
    unsigned int input[] = {5,4,2,1}; //provide the inputlist here

    cout<<maxWindowBruteForce(input, sizeof(input)/sizeof(input[0]))<<endl;
    cout<<maxWindowOrderN(input, sizeof(input)/sizeof(input[0]))<<endl;
    cout<<maxWindowOrderNWithLists(input, sizeof(input)/sizeof(input[0]))<<endl;


    return 0;
}
*/
