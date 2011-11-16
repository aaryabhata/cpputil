#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;

	Node(int v, Node* n):val(v),next(n){

	}
};


void printList(Node* head){
	Node* cur = head;
	while(cur->next){
		cout<<cur->val<<"->";
		cur = cur->next;
	}
	cout<<cur->val<<endl;

	return;
}

Node* reverseList(Node* head, Node*& newHead){

	if ((head)->next == NULL){
		newHead = head;
		return (head);
	}
	else
	{
		Node* second = (head)->next;
		Node* tail = reverseList(second, newHead);

		tail->next = head;
		(head)->next = NULL;

		return head;
	}
}

void reverseIterative(Node** head){

	Node* cur = *head;
	Node* prev = NULL;

	while(cur)
	{
		Node* tmp = cur->next;
		cur->next = prev ;
		prev = cur;
		cur = tmp;
	}

	*head = prev;

	return;
}

Node* kReverse(Node* head, int k){

	//reverse k elements
	int count = 0;
	Node* cur = head;
	Node* prev = NULL;

	while(cur != NULL && count < k){
		Node* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
		count++;
	}

	if (cur)
	{
		//recursive call to reverse
		head->next = kReverse(cur, k);
	}

	return prev;
}

Node* kReverseI(Node* current, int k)
{
        Node* r = NULL;

        Node *head;
        while(current)
        {
                int count = k;
                Node *next, *prev = NULL;
                Node *p = current;

                while(current && count--)
                {
                        next = current->next;
                        current->next = prev;
                        prev = current;
                        current = next;
                }
                if(!r)
                         r = prev;
                else
                        head->next = prev;
                head = p;
        }
        return r;
}

Node *addTwoNumbers(Node *l1, Node *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	// NO #include's are required

	Node* out = NULL;
	Node* cur = NULL;
	int carry = 0;

	while(l1 && l2)
	{
		int sum = l1->val + l2->val + carry;
		int val = sum%10;
		if (!out){
			out = new Node(val, NULL);
			cur = out;
		}else{
			cur->next = new Node(val, NULL);
			cur = cur->next;
		}
		carry = sum/10;
		l1=l1->next;
		l2=l2->next;
	}

	if (l1 || l2)
	{
		Node* r = (l1==NULL)?l2:l1;

		while(r)
		{
			int val = (r->val+carry)%10;
			cur->next = new Node(val, NULL);
			carry = (carry+r->val)/10;
			cur = cur->next;
			r = r->next;
		}

	}
	if (carry !=0)
		cur->next = new Node(carry, NULL);
	return out;
}

int findMedian(int A[], int B[], int aSize, int bSize){

	int m1 = aSize/2;
	int m2 = bSize/2;

	if(A[m1] < B[m2])
	{
		findMedian(A+m1, B, aSize-m1, m2);
	}
	else if (A[m1] > B[m2])
	{
		findMedian(A, B+m2, m1, bSize-m2);
	}
	else
	{
		return (A[m1]+B[m2])/2 ;
	}

	return 0;
}
int listAlgosDriver(){
	Node* head = new Node(1,NULL);
	head->next = new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, new Node(7, NULL))))));

	Node* newHead ;

	cout<<"Before Reverse"<<endl;
	printList(head);

	cout<<"After Recursive Reverse"<<endl;
	reverseList(head, newHead);

	printList(newHead);

	reverseIterative(&newHead);

	cout<<"After Iterative Reverse:"<<endl;
	printList(head);

	printList(kReverseI(head,2));

	return 0;
}
