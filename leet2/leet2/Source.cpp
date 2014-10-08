#include"Header.h"
#include <queue>
#include <string>
#include <functional>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace::std;

class Solution_linkedlist {
public:
	void reverse_linkedlist(ListNode*& head) {
		if (!head)
			return;
		ListNode* pre = NULL;
		ListNode* curr = head;

		while (curr) {
			ListNode* next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}
		head = pre;
	}
};

bool comp(int a, int b) {
	if (a < b)
		return true;
	return false;
}

void you_test(int A[], int n) {
	if (n <= 1)
		return;

	bool normal = true;

	for (int i = 0; i < n - 1; i++) {
			if (normal) {
				if (A[i] > A[i + 1]) {
					int temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}
			}
			else {
				if (A[i] < A[i + 1]) {
					int temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}
			}
		normal = !normal;
	}

}

int maxProduct(int A[], int n) {
	int nmax = A[0];
	int pmax = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] < 0) {
			if (A[i] * pmax < nmax) {
				nmax = A[i] * pmax;
			}
			else
				nmax = A[i];
			if (A[i] * nmax > pmax)
				pmax = A[i] * nmax;
		}
		else {
			if (A[i] * nmax < nmax && nmax < 0)
				nmax = A[i] * nmax;
			if (A[i] * pmax > pmax)
				pmax = A[i] * pmax;
			else
				pmax = max(A[i], pmax);
		}

	}

	return pmax;
}

//longest increasing subsequence
int LIS(int A[], int n) {
	int *table = new int[n];
	table[0] = 1;

	for (int i = 1; i < n; i++) {
		int max = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] >= A[j] && table[j] + 1 >= max)
				max = table[j] + 1;
		}
		table[i] = max;
	}

	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (table[i] > max)
			max = table[i];
	}

	return max;
}

// longest common sequence
int LCS(string A, string B) {
	int size_a = A.size();
	int size_b = B.size();
	if (size_a == 0 || size_b == 0)
		return 0;

	int **table = new int*[size_a + 1];
	for (int i = 0; i < size_a + 1; i++)
		table[i] = new int[size_b + 1];
	for (int i = 0; i <= size_b; i++)
		table[0][i] = 0;
	for (int i = 0; i <= size_a; i++)
		table[i][0] = 0;

	for (int i = 1; i <= size_a; i++) {
		for (int j = 1; j <= size_b; j++) {
			table[i][j] = 0;
			if (A[i - 1] == B[j - 1]) {
				int temp = table[i - 1][j - 1];
				table[i][j] = temp + 1;
			}
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
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
	if (size_a == 0 && size_b == 0)
		return 0;

	int** table = new int*[size_a + 1];
	for (int i = 0; i <= size_a; i++)
		table[i] = new int[size_b + 1];
	for (int i = 0; i <= size_a; i++)
		table[i][0] = 0;
	for (int i = 0; i <= size_b; i++)
		table[0][i] = 0;

	int max = INT_MIN;
	for (int i = 1; i <= size_a; i++) {
		for (int j = 1; j <= size_b; j++) {
			table[i][j] = 0;
			if (A[i - 1] == B[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = 0;
			if (table[i][j] > max)
				max = table[i][j];
		}
	}

	return max;
}

//backpack
bool backpack(int A[], int n, int target) {
	if (n == 0)
		return false;

	vector<vector<bool>> table(n + 1, vector<bool>(target + 1, false));
	table[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			if (j - A[i - 1] < 0) {
				table[i][j] = false;
				continue;
			}
			table[i][j] = (table[i - 1][j - A[i - 1]] || table[i - 1][j]);
			if (table[i - 1][j - A[i - 1]])
				cout << A[i - 1] << "--";
		}
	}

	return table[n][target];
}

void flatten(TreeNode *root) {
	if (!root)
		return;
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* pre = new TreeNode(-1);
	TreeNode* start = pre;

	while (!st.empty()) {
		TreeNode* temp = st.top();
		st.pop();
		if (temp->right)
			st.push(temp->right);
		if (temp->left)
			st.push(temp->left);
		pre->right = temp;
		pre = temp;
	}

	root = start->right;
	delete start;
}

class Solution_nq {
public:
	bool valid(int i, int j, vector<int> record) {
		for (int p = 0; p < record.size(); p++) {
			if (record[p] == j)
				return false;
			if (record[p] != -1 && abs(p - i) == abs(record[p] - j))
				return false;
		}
		return true;
	}
	void dfs(vector<vector<string> > &ans, vector<string> &pass, vector<int> &record, int c, int n) {
		if (n == c) {
			ans.push_back(pass);
			return;
		}
		int num = n - c;
		for (int i = 0; i < n; i++) {
			if (valid(c, i, record)) {
				record[c] = i;
				pass[c][i] = 'Q';
				dfs(ans, pass, record, c + 1, n);
				record[c] = -1;
				pass[c][i] = '.';
			}
		}
	}
	vector<vector<string> > solveNQueens(int n) {
		string line = "";
		line.append(n, '.');
		vector<string> pass(n, line);
		vector<int> record(n, -1);
		vector<vector<string>> ans;

		dfs(ans, pass, record, 0, n);

		return ans;
	}
};

int trap(int A[], int n) {
	stack<int> st;
	int sum = 0;
	int i = 0;
	while (i < n) {
		if (st.empty() || A[i] <= A[st.top()]) {
			st.push(i);
			i++;
		}
		else {
			int temp = A[st.top()];
			st.pop();
			if (st.empty()) {
				i++;
				continue;
			}
			sum += (i - st.top() - 1) * (min(A[st.top()], A[i]) - temp);
		}
	}
	return sum;
}

class Solution_reg {
public:
	bool valid(char s, char p) {
		if (s == p)
			return true;
		if (p == '.')
			return true;
		return false;
	}
	bool isMatch(const char *s, const char *p) {
		int len_s = strlen(s);
		int len_p = strlen(p);

		vector<vector<int>> dp(len_s + 1, vector<int>(len_p + 1, false));
		for (int i = 1; i <= len_s; i++) {
			dp[i][0] = false;
		}
		for (int i = 1; i <= len_p; i++) {
			dp[0][i] = p[i - 1] == '*' && i >= 2 && dp[0][i - 2];
		}
		dp[0][0] = true;
		for (int i = 1; i <= len_s; i++) {
			for (int j = 1; j <= len_p; j++) {
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]) || ((dp[i - 1][j] || dp[i][j - 1]) &&
					p[j - 1] == '*' && s[i - 1] == p[j - 2])
					|| dp[i][j - 2] && j >= 2 && p[j - 1] == '*';

			}
		}
		return dp[len_s][len_p];
	}
};

void main() {
	Solution_reg reg;
	char* s = "aa";
	char* p = ".*";
	reg.isMatch(s, p);

	cout << (int)'a' << (int)'z' << endl;
	cout << (int)'A' << (int)'Z' <<endl;

	int trap_in[4] = {2, 1, 0, 2};
	cout << trap(trap_in, 4);

	unordered_set<string> dict;
	dict.insert("a");
	dict.erase("b");

	Solution_nq nq;
	nq.solveNQueens(4);

	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	flatten(root);

	int bp[5] = { 1, 3, 2, 4, 5 };
	cout << backpack(bp, 5, 10);

	unordered_map<string, string> map;
	unordered_map<string, string>::iterator it;
	it++;
	string ab = it->first;

	string A = "BDCABA";
	string B = "ABCBDAB";
	cout << LCStr(A, B);

	int lis[10] = { 1, 1000, 2, 3, 4};
	cout << LIS(lis, 5);

	int prduct[2] = { -4, -3 };
	maxProduct(prduct, 2);

	int you[5] = { 2, 5, 6, 4, 1 };
	you_test(you, 5);
	//priority_queue<int,vector<ListNode*>, std::greater<ListNode.val>>;

	Solution_linkedlist sp;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	sp.reverse_linkedlist(head);
}