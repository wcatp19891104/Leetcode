//find_ancester

TreeNode* find_ancester(TreeNode* root, TreeNode* node1, TreeNode* node2) {
	if(!root || root == node1 || root == node2)
		return root;
	
	TreeNode* left = find_ancester(root->left, node1, node2);
	TreeNode* right = find_ancester(root->right, node1, node2);
	
	if(left && right)
		return root;
	if(!left)
		return right;
	if(!right)
		return left;
	return NULL;
}


//reverse linkedlist

void reverse_linkedlist(LinkedNode*& head) {
	if(!head)
		return;
	LinkedNode* pre = NULL;
	LinkedNode* curr = head;
	
	while(curr) {
		LinkedNode* next = curr->next;
		start->next = pre;
		pre = start;
		start = next;
	}
	head = pre;
}


//longest increasing subsequence
int LIS(int A[], int n) {
	int *table = new int[n];
	table[0] = 1;
	
	for(int i = 1; i < n; i++) {
		int max = 1;
		for(int j = 0; j < i; j++) {
			if(A[i] >= A[j] && table[j] + 1 >= max)
				max = table[j] + 1;
		}
		table[i] = max;
	}
	
	int max = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(table[i] > max)
			max = table[i];
	}
	
	return max;
}

// longest common sequence
int LCS(string A, string B) {
	int size_a = A.size();
	int size_b = B.size();
	if(size_a == 0 || size_b == 0)
		return 0;
	
	int **table = new int*[size_a + 1];
	for(int i = 0; i < size_a + 1; i++)
		table[i] = new int[size_b + 1];
	for(int i = 0; i <= size_b; i++)
		table[0][i] = 0;
	for(int i = 0; i <= size_a; i++)
		table[i][0] = 0;
	
	for(int i = 1; i <= size_a; i++)
		for(int j = 1; j <= size_b; j++) {
			table[i][j] = 0;
			int temp;
			if(A[i] == B[j])
				temp = table[i - i][j - 1] + 1;
			else
				temp = max(table[i - 1][j], table[i][j - 1]);
			table[i][j] = temp;
		}
	int i = size_a;
	int j = size_b;

	while (i > 0 && j > 0) {
		if (table[i][j] == table[i - 1][j - 1] + 1 && A[i - 1] == B[j - 1]) {
			cout << A[i - 1];
			i--;
			j--;
		}
		else if (table[i - 1][j] > table[i][j - 1])
			i--;
		else
			j--;
	}
	
	return table[size_a][size_b];
}

//longest common substr
int LCStr(string A, string B) {
	int size_a = A.size();
	int size_b = B.size();
	if(size_a == 0 && size_b == 0)
		return 0;
	
	int** table = new int*[size_a + 1];
	for(int i = 0; i <= size_a; i++)
		table[i] = new int[size_b + 1];
	for(int i = 0; i <= size_a; i++)
		table[i][0] = 0;
	for(int i = 0; i <= size_b; i++)
		table[0][i] = 0;
	
	int max = INT_MIN;
	for(int i = 1; i <= size_a; i++) {
		for(int j = 1; j <= size_b; j++) {
			table[i][j] = 0;
			if(A[i - 1] == B[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else	
				table[i][j] = 0;
			if(table[i][j] > max)
				max = table[i][j];
		}
	}
	
	return max;
}


//backpack
bool backpack(int A[], int n, int target) {
	if(n == 0)
		return false;
	
	vector<vector<bool>> table(n + 1, vector<bool>(target + 1, false));
	table[0][0] = true;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= target; j++) {
			if(target - A[i - 1] < 0) {
				table[i][j] = false;
				continue;
			}
			table[i][j] = (table[i - 1][target - A[i - 1]] || table[i - 1][target]);
			if(table[i - 1][target - A[i - 1]])
				cout << A[i - 1] << "--";
		}
	}
	
	return table[n][target];
}

//backpack number of solution

//k sum
F[i][j][k] = F[i - 1][j][k] || F[i - 1][j - 1][k - A[i]]

//















