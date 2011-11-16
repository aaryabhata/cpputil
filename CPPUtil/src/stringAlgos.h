void removeSpace(char *str) {
	char *p1 = str, *p2 = str;
	do {
		while (*p2 == ' ') {
			p2++;
		}
	} while (*p1++ = *p2++);
	return;
}
int countNumWords(const char *str) {
	bool inWord = false;
	int wordCount = 0;
	while (*str) {
		if (!inWord && isalpha(*str)) {
			inWord = true;
			wordCount++;
		} else if (inWord && *str == ' ') {
			inWord = false;
		}
		str++;
	}
	return wordCount;
}

void putlong(unsigned long n) {
	char arr[10];
	int i = 0;
	while (n > 0) {
		arr[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0) {
		putchar('0' + arr[i]);
	}
}

void putlong(unsigned long n) {
	if (n < 10) {
		putchar(n + '0');
		return;
	}
	putlong(n / 10);
	putchar(n % 10 + '0');
}

void printReverse(const char *str) {
	if (!*str)
		return;
	printReverse(str + 1);
	putchar(*str);
}
/*
 We can have two index, which both starts at zero. Compare the two first elements of A and B.
 If A[0] is greater than B[0], we increase index of B by one. If B[0] is greater than A[0],
 we increase index of A by one. If they are equal, we know an intersection has occurred,
 so add it to the list and increment index of A and B by one. Once either index reaches the
 end of A or B, we have found all the intersections of A and B.
 */
vector<int> findIntersection(vector<int> A, vector<int> B) {
	vector<int> intersection;
	int n1 = A.size();
	int n2 = B.size();
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (A[i] > B[j]) {
			j++;
		} else if (B[j] > A[i]) {
			i++;
		} else {
			intersection.push_back(A[i]);
			i++;
			j++;
		}
	}
	return intersection;
}

int doubleSquare(unsigned int m) {
	int p = sqrt((double) m / 2.0);
	int total = 0;
	for (int i = 0; i <= p; i++) {
		double j = sqrt((double) m - i * i);
		if (j - (int) j == 0.0) // might have precision issue,
			total++; // can be resolved using |j-(int)j| == delta
	}
	return total;
}
int doubleSquare(unsigned int m) {
	int total = 0;
	int iUpper = sqrt((double) m / 2.0);
	for (int i = 0; i <= iUpper; i++) {
		unsigned int ii = i * i;
		for (int j = i;; j++) {
			unsigned int sum = ii + j * j;
			if (sum == m)
				total++;
			else if (sum > m)
				break;
		}
	}
	return total;
}

/*
 How do we loop for only N-M+1 times? We are able to calculate the size of the string and substring by
 iterating a total of N+M times. In fact, finding just the length of the substring, M is sufficient. We
 use an additional pointer, p1Adv and advance it M-1 times ahead of the string pointer. Therefore, when
 p1Adv points to \0', we know that it has iterated N-M+1 times
 */

char* StrStr(const char *str, const char *target) {
	if (!*target)
		return str;
	char *p1 = (char*) str, *p2 = (char*) target;
	char *p1Adv = (char*) str;
	while (*++p2)
		p1Adv++;
	while (*p1Adv) {
		char *p1Begin = p1;
		p2 = (char*) target;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2)
			return p1Begin;
		p1 = p1Begin + 1;
		p1Adv++;
	}
	return NULL;
}

/*
 Matrix Search
 */

bool stepWise(int mat[][N_MAX], int N, int target, int &row, int &col) {
	if (target < mat[0][0] || target > mat[N - 1][N - 1])
		return false;
	row = 0;
	col = N - 1;
	while (row <= N - 1 && col >= 0) {
		if (mat[row][col] < target)
			row++;
		else if (mat[row][col] > target)
			col--;
		else
			return true;
	}
	return false;
}

bool binPart(int mat[][N_MAX], int M, int N, int target, int l, int u, int r,
		int d, int &targetRow, int &targetCol) {
	if (l > r || u > d)
		return false;
	if (target < mat[u][l] || target > mat[d][r])
		return false;
	int mid = l + (r - l) / 2;
	int row = u;
	while (row <= d && mat[row][mid] <= target) {
		if (mat[row][mid] == target) {
			targetRow = row;
			targetCol = mid;
			return true;
		}
		row++;
	}
	return binPart(mat, M, N, target, mid + 1, u, r, row - 1, targetRow,
			targetCol) || binPart(mat, M, N, target, l, row, mid - 1, d,
			targetRow, targetCol);
}

bool binPart(int mat[][N_MAX], int N, int target, int &row, int &col) {
	return binPart(mat, N, N, target, 0, 0, N - 1, N - 1, row, col);
}

/*


 */
void numToStrHelper(int n) {
	if (n == 0)
		return;
	numToStrHelper((n - 1) / 26);
	cout << (char) ('a' + (n - 1) % 26);
}

void numTostr(int n) {
	numToStrHelper(n / 26);
	cout << (char) ('a' + n % 26);
}

int rotated_binary_search(int A[], int N, int key) {
	int L = 0;
	int R = N - 1;

	while (L <= R) {
		// Avoid overflow, same as M=(L+R)/2
		int M = L + ((R - L) / 2);
		if (A[M] == key)
			return M;

		// the bottom half is sorted
		if (A[L] <= A[M]) {
			if (A[L] <= key && key < A[M])
				R = M - 1;
			else
				L = M + 1;
		}
		// the upper half is sorted
		else {
			if (A[M] < key && key <= A[R])
				L = M + 1;
			else
				R = M - 1;
		}
	}
	return -1;
}

int FindSortedArrayRotation(int A[], int N) {
	int L = 0;
	int R = N - 1;

	while (A[L] > A[R]) {
		int M = L + (R - L) / 2;
		if (A[M] > A[R])
			L = M + 1;
		else
			R = M;
	}
	return L;
}

BinaryTree* sortedListToBST(ListNode *& list, int start, int end) {
	if (start > end)
		return NULL;
	// same as (start+end)/2, avoids overflow
	int mid = start + (end - start) / 2;
	BinaryTree *leftChild = sortedListToBST(list, start, mid - 1);
	BinaryTree *parent = new BinaryTree(list->data);
	parent->left = leftChild;
	list = list->next;
	parent->right = sortedListToBST(list, mid + 1, end);
	return parent;
}

BinaryTree* sortedListToBST(ListNode *head, int n) {
	return sortedListToBST(head, 0, n - 1);
}

void print_spiral(int mat[][N_MAX], int m, int n, int k) {
	if (m <= 0 || n <= 0)
		return;
	if (m == 1) {
		for (int j = 0; j < n; j++)
			cout << mat[k][k + j] << " ";
		return;
	}
	if (n == 1) {
		for (int i = 0; i < m; i++)
			cout << mat[k + i][k] << " ";
		return;
	}
	// print from top left
	for (int j = 0; j < n - 1; j++)
		cout << mat[k][k + j] << " ";
	// print from top right
	for (int i = 0; i < m - 1; i++)
		cout << mat[k + i][k + n - 1] << " ";
	// print from bottom right
	for (int j = 0; j < n - 1; j++)
		cout << mat[k + m - 1][k + n - 1 - j] << " ";
	// print from bottom left
	for (int i = 0; i < m - 1; i++)
		cout << mat[k + m - 1 - i][k] << " ";

	print_spiral(mat, m - 2, n - 2, k + 1);
}

void print_spiral_helper(int mat[][N_MAX], int m, int n) {
	print_spiral(mat, m, n, 0);
}

void postOrderTraversalIterative(BinaryTree *root) {
	if (!root)
		return;
	stack<BinaryTree*> s;
	s.push(root);
	BinaryTree *prev = NULL;
	while (!s.empty()) {
		BinaryTree *curr = s.top();
		// we are traversing down the tree
		if (!prev || prev->left == curr || prev->right == curr) {
			if (curr->left) {
				s.push(curr->left);
			} else if (curr->right) {
				s.push(curr->right);
			} else {
				cout << curr->data << " ";
				s.pop();
			}
		}
		// we are traversing up the tree from the left
		else if (curr->left == prev) {
			if (curr->right) {
				s.push(curr->right);
			} else {
				cout << curr->data << " ";
				s.pop();
			}
		}
		// we are traversing up the tree from the right
		else if (curr->right == prev) {
			cout << curr->data << " ";
			s.pop();
		}
		prev = curr; // record previously traversed node
	}
}

void postOrderTraversalIterative(BinaryTree *root) {
	if (!root)
		return;
	stack<BinaryTree*> s;
	s.push(root);
	BinaryTree *prev = NULL;
	while (!s.empty()) {
		BinaryTree *curr = s.top();
		if (!prev || prev->left == curr || prev->right == curr) {
			if (curr->left)
				s.push(curr->left);
			else if (curr->right)
				s.push(curr->right);
		} else if (curr->left == prev) {
			if (curr->right)
				s.push(curr->right);
		} else {
			cout << curr->data << " ";
			s.pop();
		}
		prev = curr;
	}
}

void postOrderTraversalIterativeTwoStacks(BinaryTree *root) {
	if (!root)
		return;
	stack<BinaryTree*> s;
	stack<BinaryTree*> output;
	s.push(root);
	while (!s.empty()) {
		BinaryTree *curr = s.top();
		output.push(curr);
		s.pop();
		if (curr->left)
			s.push(curr->left);
		if (curr->right)
			s.push(curr->right);
	}
	while (!output.empty()) {
		cout << output.top()->data << " ";
		output.pop();
	}
}

void in_order_traversal_iterative(BinaryTree *root) {
	stack<BinaryTree*> s;
	BinaryTree *current = root;
	bool done = false;
	while (!done) {
		if (current) {
			s.push(current);
			current = current->left;
		} else {
			if (s.empty()) {
				done = true;
			} else {
				current = s.top();
				s.pop();
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

void in_order_traversal_iterative(BinaryTree *root) {
	stack<BinaryTree*> s;
	BinaryTree *current = root;
	while (!s.empty() || current) {
		if (current) {
			s.push(current);
			current = current->left;
		} else {
			current = s.top();
			s.pop();
			cout << current->data << " ";
			current = current->right;
		}
	}
}

Node *LCA(Node *root, Node *p, Node *q) {
	if (!root || !p || !q)
		return NULL;
	if (max(p->data, q->data) < root->data)
		return LCA(root->left, p, q);
	else if (min(p->data, q->data) > root->data)
		return LCA(root->right, p, q);
	else
		return root;
}

int getHeight(Node *p) {
	int height = 0;
	while (p) {
		height++;
		p = p->parent;
	}
	return height;
}

// As root->parent is NULL, we don't need to pass root in.
Node *LCA(Node *p, Node *q) {
	int h1 = getHeight(p);
	int h2 = getHeight(q);
	// swap both nodes in case p is deeper than q.
	if (h1 > h2) {
		swap(h1, h2);
		swap(p, q);
	}
	// invariant: h1 <= h2.
	int dh = h2 - h1;
	for (int h = 0; h < dh; h++)
		q = q->parent;
	while (p && q) {
		if (p == q)
			return p;
		p = p->parent;
		q = q->parent;
	}
	return NULL; // p and q are not in the same tree
}

const int MAX = 256;
// a fast lookup for inorder's element -> index
// binary tree's element must be in the range of [0, MAX-1]
int mapIndex[MAX];
void mapToIndices(int inorder[], int n) {
	for (int i = 0; i < n; i++) {
		assert(0 <= inorder[i] && inorder[i] <= MAX - 1);
		mapIndex[inorder[i]] = i;
	}
}

// precondition: mapToIndices must be called before entry
Node *buildInorderPreorder(int in[], int pre[], int n, int offset) {
	assert(n >= 0);
	if (n == 0)
		return NULL;
	int rootVal = pre[0];
	int i = mapIndex[rootVal] - offset; // the divider's index
	Node *root = new Node(rootVal);
	root->left = buildInorderPreorder(in, pre + 1, i, offset);
	root->right = buildInorderPreorder(in + i + 1, pre + i + 1, n - i - 1,
			offset + i + 1);
	return root;
}

// precondition: mapToIndices must be called before entry
Node *buildInorderPostorder(int in[], int post[], int n, int offset) {
	assert(n >= 0);
	if (n == 0)
		return NULL;
	int rootVal = post[n - 1];
	int i = mapIndex[rootVal] - offset; // the divider's index
	Node *root = new Node(rootVal);
	root->left = buildInorderPostorder(in, post, i, offset);
	root->right = buildInorderPostorder(in + i + 1, post + i, n - i - 1, offset
			+ i + 1);
	return root;
}

/*
 Serialize BST to a file
 */

void readBSTHelper(int min, int max, int &insertVal, BinaryTree *&p,
		ifstream &fin) {
	if (insertVal > min && insertVal < max) {
		int val = insertVal;
		p = new BinaryTree(val);
		if (fin >> insertVal) {
			readBSTHelper(min, val, insertVal, p->left, fin);
			readBSTHelper(val, max, insertVal, p->right, fin);
		}
	}
}

void readBST(BinaryTree *&root, ifstream &fin) {
	int val;
	fin >> val;
	readBSTHelper(INT_MIN, INT_MAX, val, root, fin);
}

// Serialize Binary tree to a file

void readBinaryTree(BinaryTree *&p, ifstream &fin) {
	int token;
	bool isNumber;
	if (!readNextToken(token, fin, isNumber))
		return;
	if (isNumber) {
		p = new BinaryTree(token);
		readBinaryTree(p->left, fin);
		readBinaryTree(p->right, fin);
	}
}

void writeBinaryTree(BinaryTree *p, ostream &out) {
	if (!p) {
		out << "# ";
	} else {
		out << p->data << " ";
		writeBinaryTree(p->left, out);
		writeBinaryTree(p->right, out);
	}
}

void printLevelOrderZigZag(BinaryTree *root) {
	stack<BinaryTree*> currentLevel, nextLevel;
	bool leftToRight = true;
	currentLevel.push(root);
	while (!currentLevel.empty()) {
		BinaryTree *currNode = currentLevel.top();
		currentLevel.pop();
		if (currNode) {
			cout << currNode->data << " ";
			if (leftToRight) {
				nextLevel.push(currNode->left);
				nextLevel.push(currNode->right);
			} else {
				nextLevel.push(currNode->right);
				nextLevel.push(currNode->left);
			}
		}
		if (currentLevel.empty()) {
			cout << endl;
			leftToRight = !leftToRight;
			swap(currentLevel, nextLevel);
		}
	}
}

int maxHeight(BinaryTree *p) {
	if (!p)
		return 0;
	int left_height = maxHeight(p->left);
	int right_height = maxHeight(p->right);
	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

//Below is the code for finding the maximum depth of a binary tree using post-order traversal, without recursion.

int maxDepthIterative(BinaryTree *root) {
	if (!root)
		return 0;
	stack<BinaryTree*> s;
	s.push(root);
	int maxDepth = 0;
	BinaryTree *prev = NULL;
	while (!s.empty()) {
		BinaryTree *curr = s.top();
		if (!prev || prev->left == curr || prev->right == curr) {
			if (curr->left)
				s.push(curr->left);
			else if (curr->right)
				s.push(curr->right);
		} else if (curr->left == prev) {
			if (curr->right)
				s.push(curr->right);
		} else {
			s.pop();
		}
		prev = curr;
		if (s.size() > maxDepth)
			maxDepth = s.size();
	}
	return maxDepth;
}

/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(char *a, int i, int n) {
	int j;
	if (i == n)
		printf("%s\n", a);
	else {
		for (j = i; j <= n; j++) {
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			swap((a + i), (a + j)); //backtrack
		}
	}
}

/* Driver program to test above functions */
int main() {
	char a[] = "ABC";
	permute(a, 0, 2);
	getchar();
	return 0;
}

int ipow(int base, int exp) {
	int result = 1;
	while (exp) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

//Sliding window maximum
typedef pair<int, int> Pair;
void maxSlidingWindow(int A[], int n, int w, int B[]) {
	priority_queue<Pair> Q;
	for (int i = 0; i < w; i++)
		Q.push(Pair(A[i], i));
	for (int i = w; i < n; i++) {
		Pair p = Q.top();
		B[i - w] = p.first;
		while (p.second <= i - w) {
			Q.pop();
			p = Q.top();
		}
		Q.push(Pair(A[i], i));
	}
	B[n - w] = Q.top().first;
}

void maxSlidingWindow(int A[], int n, int w, int B[]) {
	deque<int> Q;
	for (int i = 0; i < w; i++) {
		while (!Q.empty() && A[i] >= A[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	for (int i = w; i < n; i++) {
		B[i - w] = A[Q.front()];
		while (!Q.empty() && A[i] >= A[Q.back()])
			Q.pop_back();
		while (!Q.empty() && Q.front() <= i - w)
			Q.pop_front();
		Q.push_back(i);
	}
	B[n - w] = A[Q.front()];
}

bool isBSTHelper(Node *p, int low, int high) {
	if (!p)
		return true;
	if (low < p->val && p->val < high)
		return isBSTHelper(p->left, low, p->val) && isBSTHelper(p->right,
				p->val, high);
	else
		return false;
}

bool isBST(Node *root) {
	// INT_MIN and INT_MAX are defined in C++'s <climits> library
	return isBSTHelper(root, INT_MIN, INT_MAX);
}

bool readNextToken(int& token, ifstream& ifs, bool& isNumber) {
	std::stringstream ss;
	string input;
	ifs >> input;
	if (ifs.eof()) {
		cout << "EOF encountered" << endl;
		return false;
	}
	ss << input;
	if (!(ss >> token)) {
		isNumber = false;
	} else
		isNumber = true;

	return isNumber;
}
int findKthSmallest(int A[], int m, int B[], int n, int k) {
	assert(m >= 0);
	assert(n >= 0);
	assert(k > 0);
	assert(k <= m + n);

	int i = (int) ((double) m / (m + n) * (k - 1));
	int j = (k - 1) - i;

	assert(i >= 0);
	assert(j >= 0);
	assert(i <= m);
	assert(j <= n);
	// invariant: i + j = k-1
	// Note: A[-1] = -INF and A[m] = +INF to maintain invariant
	int Ai_1 = ((i == 0) ? INT_MIN : A[i - 1]);
	int Bj_1 = ((j == 0) ? INT_MIN : B[j - 1]);
	int Ai = ((i == m) ? INT_MAX : A[i]);
	int Bj = ((j == n) ? INT_MAX : B[j]);

	if (Bj_1 < Ai && Ai < Bj)
		return Ai;
	else if (Ai_1 < Bj && Bj < Ai)
		return Bj;

	assert((Ai > Bj && Ai_1 > Bj) || (Ai < Bj && Ai < Bj_1));

	// if none of the cases above, then it is either:
	if (Ai < Bj)
		// exclude Ai and below portion
		// exclude Bj and above portion
		return findKthSmallest(A + i + 1, m - i - 1, B, j, k - i - 1);
	else
		/* Bj < Ai */
		// exclude Ai and above portion
		// exclude Bj and below portion
		return findKthSmallest(A, i, B + j + 1, n - j - 1, k - j - 1);
}

// Returns false if no valid window is found. Else returns
// true and updates minWindowBegin and minWindowEnd with the
// starting and ending position of the minimum window.
bool minWindow(const char* S, const char *T, int &minWindowBegin,
		int &minWindowEnd) {
	int sLen = strlen(S);
	int tLen = strlen(T);
	int needToFind[256] = { 0 };

	for (int i = 0; i < tLen; i++)
		needToFind[T[i]]++;

	int hasFound[256] = { 0 };
	int minWindowLen = INT_MAX;
	int count = 0;
	for (int begin = 0, end = 0; end < sLen; end++) {
		// skip characters not in T
		if (needToFind[S[end]] == 0)
			continue;
		hasFound[S[end]]++;
		if (hasFound[S[end]] <= needToFind[S[end]])
			count++;

		// if window constraint is satisfied
		if (count == tLen) {
			// advance begin index as far right as possible,
			// stop when advancing breaks window constraint.
			while (needToFind[S[begin]] == 0 || hasFound[S[begin]]
					> needToFind[S[begin]]) {
				if (hasFound[S[begin]] > needToFind[S[begin]])
					hasFound[S[begin]]--;
				begin++;
			}

			// update minWindow if a minimum length is met
			int windowLen = end - begin + 1;
			if (windowLen < minWindowLen) {
				minWindowBegin = begin;
				minWindowEnd = end;
				minWindowLen = windowLen;
			} // end if
		} // end if
	} // end for

	return (count == tLen) ? true : false;
}

// Find the largest BST subtree in a binary tree.
// If the subtree is a BST, return total number of nodes.
// If the subtree is not a BST, -1 is returned.
int findLargestBSTSubtree(BinaryTree *p, int &min, int &max, int &maxNodes,
		BinaryTree *& largestBST) {
	if (!p)
		return 0;
	bool isBST = true;
	int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes,
			largestBST);
	int currMin = (leftNodes == 0) ? p->data : min;
	if (leftNodes == -1 || (leftNodes != 0 && p->data <= max))
		isBST = false;
	int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes,
			largestBST);
	int currMax = (rightNodes == 0) ? p->data : max;
	if (rightNodes == -1 || (rightNodes != 0 && p->data >= min))
		isBST = false;
	if (isBST) {
		min = currMin;
		max = currMax;
		int totalNodes = leftNodes + rightNodes + 1;
		if (totalNodes > maxNodes) {
			maxNodes = totalNodes;
			largestBST = p;
		}
		return totalNodes;
	} else {
		return -1; // This subtree is not a BST
	}
}

BinaryTree* findLargestBSTSubtree(BinaryTree *root) {
	BinaryTree *largestBST = NULL;
	int min, max;
	int maxNodes = INT_MIN;
	findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
	return largestBST;
}

// Find the largest BST in a binary tree.
// This code does not delete dynamically-allocated nodes,
// so memory will be leaked upon exit.
// The min and max values are passed top-down to check if
// including a node satisfies the current BST constraint.
// The child nodes are passed bottom-up to be assigned
// to its parent.
// Returns the total number of nodes the child holds.
int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes,
		BinaryTree *& largestBST, BinaryTree *& child) {
	if (!p)
		return 0;
	if (min < p->data && p->data < max) {
		int leftNodes = findLargestBST(p->left, min, p->data, maxNodes,
				largestBST, child);
		BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
		int rightNodes = findLargestBST(p->right, p->data, max, maxNodes,
				largestBST, child);
		BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;
		// create a copy of the current node and
		// assign its left and right child.
		BinaryTree *parent = new BinaryTree(p->data);
		parent->left = leftChild;
		parent->right = rightChild;
		// pass the parent as the child to the above tree.
		child = parent;
		int totalNodes = leftNodes + rightNodes + 1;
		if (totalNodes > maxNodes) {
			maxNodes = totalNodes;
			largestBST = parent;
		}
		return totalNodes;
	} else {
		// include this node breaks the BST constraint,
		// so treat this node as an entirely new tree and
		// check if a larger BST exist in this tree
		findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
		// must return 0 to exclude this node
		return 0;
	}
}

BinaryTree* findLargestBST(BinaryTree *root) {
	BinaryTree *largestBST = NULL;
	BinaryTree *child;
	int maxNodes = INT_MIN;
	findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
	return largestBST;
}

void printSum(int candidates[], int index[], int n) {
	for (int i = 1; i <= n; i++)
		cout << candidates[index[i]] << ((i == n) ? "" : "+");
	cout << endl;
}

void solve(int target, int sum, int candidates[], int sz, int index[], int n) {
	if (sum > target)
		return;
	if (sum == target)
		printSum(candidates, index, n);

	for (int i = index[n]; i < sz; i++) {
		index[n + 1] = i;
		solve(target, sum + candidates[i], candidates, sz, index, n + 1);
	}
}

void solve(int target, int candidates[], int sz) {
	int index[10000];
	index[0] = 0;
	solve(target, 0, candidates, sz, index, 0);
}

#include <string>

using std::string;

int LongestCommonSubstring(const string& str1, const string& str2) {
	if (str1.empty() || str2.empty()) {
		return 0;
	}

	int *curr = new int[str2.size()];
	int *prev = new int[str2.size()];
	int *swap = NULL;
	int maxSubstr = 0;

	for (int i = 0; i < str1.size(); ++i) {
		for (int j = 0; j < str2.size(); ++j) {
			if (str1[i] != str2[j]) {
				curr[j] = 0;
			} else {
				if (i == 0 || j == 0) {
					curr[j] = 1;
				} else {
					curr[j] = 1 + prev[j - 1];
				}
				//The next if can be replaced with:
				//maxSubstr = max(maxSubstr, curr[j]);
				//(You need algorithm.h library for using max())
				if (maxSubstr < curr[j]) {
					maxSubstr = curr[j];
				}
			}
		}
		swap = curr;
		curr = prev;
		prev = swap;
	}
	delete[] curr;
	delete[] prev;
	return maxSubstr;
}
#define REHASH(a, b, h) ((((h) - (a)*d) << 1) + (b))
void KarbRabin(char *x, int m, char *y, int n) {
	int d, hx, hy, i, j;

	/* Preprocessing */
	/* computes d = 2^(m-1) with
	 the left-shift operator */
	for (d = i = 1; i < m; ++i)
		d = (d << 1);

	for (hy = hx = i = 0; i < m; ++i) {
		hx = ((hx << 1) + x[i]);
		hy = ((hy << 1) + y[i]);
	}

	/* Searching */
	j = 0;
	while (j <= n - m) {
		if (hx == hy && memcmp(x, y + j, m) == 0)
			OUTPUT(j);
		hy = REHASH(y[j], y[j + m], hy);
		++j;
	}

}

void preMp(char *x, int m, int mpNext[]) {
	int i, j;

	i = 0;
	j = mpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = mpNext[j];
		mpNext[++i] = ++j;
	}
}

void MorrisPratt(char *x, int m, char *y, int n) {
	int i, j, mpNext[XSIZE];

	/* Preprocessing */
	preMp(x, m, mpNext);

	/* Searching */
	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = mpNext[i];
		i++;
		j++;
		if (i >= m) {
			OUTPUT(j - i);
			i = mpNext[i];
		}
	}
}

/*
 This was a question asked in an onsite interview with amazon. The interviewer had to be the bar
 raiser because every other question was pretty easy.
 given a number, come up with all of the possible ways to insert '+' and '-' in that number. for example
 given 123, possible answer would be
 1+23
 1+2+3
 1-23
 1-2+3
 1-2-3
 1+2-3
 12+3
 */

void print(String head, String tail) {
	if (tail.length() == 0) {
		return;
	}
	char c = tail.charAt(0);
	if (head.length() > 0) {
		System.out.println(head + "+" + tail);
		print(head + "+" + c, tail.substring(1));
		System.out.println(head + "-" + tail);
		print(head + "-" + c, tail.substring(1));
	}
	print(head + c, tail.substring(1));
}

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	struct Node *left, *right;
	int data;

} Node;
typedef Node * Tree;
Node * predecessor(Tree t, int el) {
	Node *prev = NULL;
	while (t) {
		if (t->data < el) {
			prev = t;
			t = t->right;
		} else if (t->data == el) {
			if (t->left) {
				prev = t->left;
				if (prev) {
					while (prev->right)
						prev = prev->right;
				}
			}
			return prev;
		} else {
			t = t->left;
		}
	}
	return NULL; //not in the tree
}
Node * successor(Tree t, int el) {
	Node *next = NULL;
	while (t) {
		if (t->data > el) {
			next = t;
			t = t->left;
		} else if (t->data == el) {
			if (t->right) {
				next = t->right;
				if (next) {
					while (next->left)
						next = next->left;
				}
			}
			return next;
		} else {
			t = t->right;
		}
	}
	return NULL; //not in the tree
}

