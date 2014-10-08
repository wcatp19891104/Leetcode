#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace::std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
 public:
	 ListNode *reverseKGroup(ListNode *head, int k) {
		 if (head == NULL)
			 return NULL;
		 if (k == 1)
			 return head;
		 ListNode* first = new ListNode(0);
		 first->next = head;
		 ListNode* p = first;
		 ListNode* q = first;
		 while (true){
			 int i = 0;
			 while (q != NULL&&i<k){
				 q = q->next;
				 i++;
			 }
			 if (q == NULL)
				 return first->next;
			 while (p->next != q){
				 ListNode* temp = q->next;
				 q->next = p->next;
				 p->next = p->next->next;
				 q->next->next = temp;
			 }
			 for (int j = 0; j<k; j++){
				 p = p->next;
				 q = p;
			 }
		 }
		 return first->next;
	 }

 };


 bool isdigit(char in){
	 if (in<'0')  return false;
	 if (in>'9')  return false;
	 return true;
 }
 int _atoi(const char *str) {
	 if (!str)
		 return 0;
	 int i = 0;
	 bool neg = false;
	 int ret = 0;
	 while (str[i] == ' ')
		 i++;
	 if (str[i] == '+'){ neg = false; i++; }
	 else if (str[i] == '-'){ neg = true; i++; }
	 if (!isdigit(str[i]))
		 return 0;
	 while (isdigit(str[i])){
		 if (!neg&&ret>INT_MAX / 10)  return INT_MAX;
		 if (!neg&&ret == INT_MAX / 10 && int(str[i] - '0')>7)    return INT_MAX;
		 if (neg&&-ret<INT_MIN / 10)  return INT_MIN;
		 if (neg&&-ret == INT_MIN / 10 && int(str[i] - '0')>8)    return INT_MIN;
		 ret = ret * 10 + int(str[i] - '0');
		 i++;
	 }
	 if (neg) return -ret;
	 return ret;
 }

 ListNode *partition(ListNode *head, int x) {
	 ListNode* p = new ListNode(-1);
	 ListNode* start = p;
	 ListNode* end = p;
	 while (head){
		 ListNode* temp;
		 if (head->val<x){
			 temp = head;
			 temp->next = start;
			 start = temp;
		 }
		 else{
			 temp = head;
			 end->next = temp;
			 end = temp;
		 }
		 head = head->next;
	 }
	 if (p == start)
		 return p->next;
	 p = p->next;
	 return start;
 }

 class Solution_part {
 public:
	 bool valid(string s){
		 int size = s.size();
		 if (size == 1)
			 return true;
		 int st = 0;
		 int ed = size - 1;
		 while (st<ed){
			 if (s[st] != s[ed])
				 return false;
			 st++;
			 ed--;
		 }
		 return true;
	 }
	 void dfs(string s, vector<string>& storage, vector<vector<string>>& ret){
		 if (s.size() == 0){
			 //storage.push_back(s);
			 ret.push_back(storage);
			 //storage.clear();
			 return;
		 }
		 int size = s.size();
		 for (int i = 1; i<=size; i++){
			 if (valid(s.substr(0, i))){
				 storage.push_back(s.substr(0, i));
				 dfs(s.substr(i), storage, ret);
				 storage.pop_back();
			 }
		 }
	 }
	 vector<vector<string>> partition(string s) {
		 vector<vector<string>> ret;
		 vector<string> storage;
		 dfs(s, storage, ret);
		 return ret;
	 }
 };

 class Solution_longest {
 public:
	 string longestPalindrome(string s) {
		 int size = s.size();
		 int max = INT_MIN;
		 int start = 0;
		 bool table[1000][1000] = { false };
		 for (int i = size - 1; i >= 0; i--){
			 for (int j = i; j<size; j++){
				 if (s[i] == s[j] && (j - i<2 || table[i + 1][j - 1])){
					 table[i][j] = true;
					 if (j - i + 1>max)
						 max = j - i + 1;
					 start = i;
				 }
			 }
		 }
		 return s.substr(start, max);
	 }
 };

 class Solution_min {
public:
    int minCut(string s) {
		int map[3][3] = { 0 };
		int res[3] = { 0 };
        int size = s.size();
        for(int i=size-1;i>=0;i--){
            for(int j=i;j<size;j++){
                if(i==j)
                    map[i][j] = 1;
                else if(s[i]==s[j]){
                    if(j==i+1||map[i+1][j-1]==1)
                        map[i][j] = 1;
                }
            }
        }
        res[0]=0;
        int min = INT_MAX;
        for(int i=0;i<size;i++){
            if(map[0][i]==1){
                res[i] = 0;
                continue;
            }
            min = INT_MAX;
            for(int j=0;j<i;j++){
                if(map[j+1][i]==1){
                    if(res[j]+1<min)
                        min = res[j]+1;
                }
            }
            res[i] = min;
        }
        return res[size-1];
    }
};

 class Solution_wordsearch {
 public:
	 bool dfs(int i, int j, vector<vector<char> > &board, string word){
		 int size_i = board.size();
		 int size_j = board[0].size();
		 if (word.size() == 0)
			 return true;
		 //left
		 if (i - 1 >= 0 && board[i - 1][j] == word[0]){
			 char temp = board[i - 1][j];
			 board[i - 1][j] = '~';
			 bool r = dfs(i - 1, j, board, word.substr(1));
			 if (r)
				 return true;
			 board[i - 1][j] = temp;
		 }
		 //right
		 if (i + 1<size_i&&board[i + 1][j] == word[0]){
			 char temp = board[i + 1][j];
			 board[i + 1][j] = '~';
			 bool r = dfs(i + 1, j, board, word.substr(1));
			 if (r)
				 return true;
			 board[i + 1][j] = temp;
		 }
		 //up
		 if (j - 1 >= 0 && board[i][j - 1] == word[0]){
			 char temp = board[i][j - 1];
			 board[i][j - 1] = '~';
			 bool r = dfs(i, j - 1, board, word.substr(1));
			 if (r)
				 return true;
			 board[i][j - 1] = temp;
		 }
		 //down
		 if (j + 1 >= 0 && board[i][j + 1] == word[0]){
			 char temp = board[i][j + 1];
			 board[i][j + 1] = '~';
			 bool r = dfs(i, j + 1, board, word.substr(1));
			 if (r)
				 return true;
			 board[i][j + 1] = temp;
		 }
		 return false;
	 }
	 bool exist(vector<vector<char> > &board, string word) {
		 if (word.size() == 0)
			 return false;
		 int size_i = board.size();
		 int size_j = board[0].size();
		 int i = 0;
		 int j = 0;
		 bool jump = false;
		 for (; i<size_i; i++){
			 for (; j<size_j; j++){
				 if (board[i][j] == word[0]){
					 jump = true;
					 break;
				 }
			 }
			 if (jump)
				 break;
		 }
		 if (i == size_i || j == size_j)
			 return false;
		 board[i][j] = '~';
		 return dfs(i, j, board, word.substr(1));
	 }
 };



 class Solution_solve {
 public:
	 void solve(vector<vector<char>> &board) {
		 int row = board.size();
		 if (row == 0)
			 return;
		 int col = board[0].size();
		 queue<int> q_i;
		 queue<int> q_j;
		 vector<vector<bool>> table(row, vector<bool>(col));

		 for (int i = 0; i<col; i++){
			 if (board[0][i] == 'O'){
				 table[0][i] = true;
				 q_i.push(0);
				 q_j.push(i);
			 }
		 }

		 for (int i = 0; i<row; i++){
			 if (board[i][0] == 'O'){
				 table[i][0] = true;
				 q_i.push(i);
				 q_j.push(0);
			 }
		 }


		 for (int i = 0; i<col; i++){
			 if (board[row - 1][i] == 'O'){
				 table[row - 1][i] = true;
				 q_i.push(row - 1);
				 q_j.push(i);
			 }
		 }

		 for (int i = 0; i<row; i++){
			 if (board[i][col - 1] == 'O'){
				 table[i][col - 1] = true;
				 q_i.push(i);
				 q_j.push(col - 1);
			 }
		 }


		


		 while (!q_i.empty()){
			 int i = q_i.front();
			 int j = q_j.front();
			 q_i.pop();
			 q_j.pop();
			 if (i == 3&& j==2)
				 cout << "";
			 if (i - 1>0 && board[i - 1][j] == 'O'&&table[i - 1][j] == false){ 
				 table[i - 1][j] = true; q_i.push(i - 1); q_j.push(j); }
			 if (i + 1<row - 1 && board[i + 1][j] == 'O'&&table[i + 1][j] == false){ 
				 table[i + 1][j] = true; q_i.push(i + 1); q_j.push(j); }
			 if (j - 1>0 && board[i][j - 1] == 'O'&&table[i][j - 1] == false){ 
				 table[i][j - 1] = true; q_i.push(i); q_j.push(j - 1); }
			 if (j + 1<col - 1 && board[i][j + 1] == 'O'&&table[i][j + 1] == false){ 
				 table[i][j + 1] = true; q_i.push(i); q_j.push(j + 1); }
		 }
		 for (int i = 0; i<row; i++)
		 for (int j = 0; j<col; j++){
			 if (board[i][j] == 'O'&&table[i][j] == false)
				 board[i][j] = 'X';
		 }

	 }
 };

 class Solution_wordbreak {
 public:
	 void dfs(string s, string &res, unordered_set<string> dict, vector<string> &ret){
		 int size = s.size();
		 if (size == 0){
			 ret.push_back(res);
			 return;
		 }
		 for (int i = 1; i <= size; i++){
			 if (dict.find(s.substr(0, i)) != dict.end()){
				 string temp = res;
				 res = res + s.substr(0, i) + " ";
				 dfs(s.substr(i), res, dict, ret);
				 res = temp;
			 }
		 }
	 }
	 vector<string> wordBreak(string s, unordered_set<string> &dict) {
		 string res = "";
		 vector<string> ret;
		 if (s.size() == 0)
			 return ret;
		 dfs(s, res, dict, ret);
		 return ret;
	 }
 };

 char *strStr(char *haystack, char *needle) {
	 if (!haystack || !needle)
		 return NULL;

	 int len1 = strlen(haystack);
	 int len2 = strlen(needle);
	 int i;
	 int j;
	 for (i = 0; i < len1 - len2 + 1; i++)    {
		 for (j = 0; j < len2; j++)   {
			 if (*(haystack + i + j) != *(needle + j))
				 break;
		 }
		 if (j == len2)
			 return haystack + i;
	 }
	 return NULL;
 }

 class Solution_subset {
 public:
	 void DFS(vector<vector<int>> &ret, vector<int> &pass, vector<int> &S, int pos) {
		 ret.push_back(pass);

		 for (int i = pos; i < S.size(); i++) {
			 if (i != pos && S[i] == S[i - 1])
				 continue;
			 pass.push_back(S[i]);
			 DFS(ret, pass, S, i + 1);
			 pass.pop_back();
		 }
	 }
	 vector<vector<int> > subsetsWithDup(vector<int> &S) {
		 vector<vector<int>> ret;
		 vector<int> pass;

		 sort(S.begin(), S.end());
		 DFS(ret, pass, S, 0);

		 return ret;
	 }
 };

 class Solution_perumu {
 public:
	 void dfs(vector<vector<int>> &ret, vector<int> &pass, vector<int> &res)  {
		 if (res.size() == 0) {
			 ret.push_back(pass);
			 return;
		 }

		 int temp;
		 for (int i = 0; i < res.size(); i++) {
			 pass.push_back(res[i]);
			 temp = res[i];
			 res.erase(res.begin() + i);
			 dfs(ret, pass, res);
			 res.insert(res.begin() + i, temp);
		 }
	 }
	 vector<vector<int> > permute(vector<int> &num) {
		 vector<vector<int> > ret;
		 vector<int> pass;

		 dfs(ret, pass, num);

		 return ret;
	 }
 };

 class Solution_wordladder {
 public:
	 vector<string> get_vect(string target, unordered_set<string> &dict) {
		 int size = target.length();
		 vector<string> ret;

		 for (int i = 0; i < size; i++) {
			 for (char j = 'a'; j <= 'z'; j++) {
				 string temp = target;
				 temp[i] = j;
				 if (dict.find(temp) != dict.end() && temp != target)
					 ret.push_back(temp);
			 }
		 }

		 return ret;
	 }

	 bool valid(string s1, string s2) {
		 int count = 0;
		 int size = s1.size();

		 for (int i = 0; i < size; i++) {
			 if (s1[i] != s2[i]) {
				 count++;
				 if (count > 1)
					 return false;
			 }
		 }

		 return true;
	 }

	 int ladderLength(string start, string end, unordered_set<string> &dict) {
		 queue<string> q_1;
		 queue<string> q_2;
		 unordered_map<string, bool> past;
		 int count = 0;
		 q_1.push(start);
		 int enter = 0;

		 while (!q_1.empty() || !q_2.empty()) {
			 int min = INT_MIN;
			 while (!q_1.empty()) {
				 string temp = q_1.front();
				 q_1.pop();
				 if (temp == end)
					 return count;
				 if (valid(temp, end) && enter == 1)
					 min = count + 1;
				 enter = 1;
				 vector<string> stor = get_vect(temp, dict);
				 for (int i = 0; i < stor.size(); i++) {
					 if (past.find(stor[i]) == past.end()) {
						 q_2.push(stor[i]);
						 past[stor[i]] = true;
					 }
				 }
			 }
			 count++;

			 if (min != INT_MIN)
				 return min;

			 while (!q_2.empty()) {
				 string temp = q_2.front();
				 q_2.pop();
				 if (temp == end)
					 return count;
				 if (valid(temp, end))
					 min = count + 1;
				 vector<string> stor = get_vect(temp, dict);
				 for (int i = 0; i < stor.size(); i++) {
					 if (past.find(stor[i]) == past.end()) {
						 q_1.push(stor[i]);
						 past[stor[i]] = true;
					 }
				 }
			 }
			 count++;
			 if (min != INT_MIN)
				 return min;
		 }
		 return 0;
	 }

 };


 class Solution_search_range {
 public:
	 int binary_search(int A[], int start, int end, int target) {

		 while (start <= end) {
			 int mid = start + (end - start) / 2;
			 if (A[mid] == target)
				 return mid;
			 if (A[mid] > target)
				 end = mid - 1;
			 else
				 start = mid + 1;
		 }

		 return -1;
	 }
	 vector<int> searchRange(int A[], int n, int target) {
		 vector<int> ret;
		 if (n == 0)
			 return ret;

		 int index = binary_search(A, 0, n - 1, target);
		 if (index == -1) {
			 ret.push_back(-1);
			 ret.push_back(-1);
			 return ret;
		 }


		 int left = index;
		 int right = index;
		 while ((left = binary_search(A, 0, left - 1, target)) != -1) {
			 left = left;
		 }

		 while ((right = binary_search(A, right + 1, n - 1, target)) != -1) {
			 right = right;
		 }

		 ret.push_back(left);
		 ret.push_back(right);

		 return ret;

	 }
 };


 int first_occr(vector<int> array, int target) {
	 int start = 0;
	 int end = array.size() - 1;
	 while (start + 1 < end) {
		 int mid = start + (end - start) / 2;
		 if (array[mid] == target)
			 end = mid;
		 else if (array[mid] < target)
			 start = mid;
		 else
			 end = mid;
	 }
	 if (array[start] == target)
		 return start;
	 if (array[end] == target)
		 return end;
	 return -1;
 }

 int last_occr(vector<int> array, int target) {
	 int start = 0;
	 int end = array.size() - 1;
	 while (start + 1 < end) {
		 int mid = start + (end - start) / 2;
		 if (array[mid] == target)
			 start = mid;
		 else if (array[mid] < target)
			 start = mid;
		 else
			 end = mid;
	 }
	 if (array[start] == target)
		 return start;
	 if (array[end] == target)
		 return end;
	 return -1;
 }

 int find_peak(vector<int> array) {
	 if (array.size() < 4)
		 return -1;
	 int start = 1;
	 int end = array.size() - 2;
	 int mid;
	 while (start + 1 < end)
	 {
		 mid = start + (end - start) / 2;
		 if (array[mid] > array[mid - 1] && array[mid + 1] < array[mid])
			 return mid;
		 else if (array[mid] < array[mid - 1])
			 end = mid;
		 else
			 start = mid;
	 }

	 if (array[start] > array[start - 1] && array[start] > array[start + 1])
		 return start;
	 if (array[end] > array[end - 1] && array[end] > array[end + 1])
		 return end;
	 return -1;
 }

 void rotate_string(string& in, int offset) {

 }

 void main(){
	 vector<int> peak;
	 peak.push_back(1);
	 peak.push_back(2);
	 peak.push_back(3);
	 peak.push_back(4);
	 peak.push_back(5);
	 peak.push_back(6);
	 peak.push_back(8);
	 int f_peak = find_peak(peak);

	 vector<int> first_oc;
	 first_oc.push_back(1);
	 first_oc.push_back(2);
	 first_oc.push_back(2);
	 first_oc.push_back(2);
	 first_oc.push_back(2);
	 first_oc.push_back(2);
	 first_oc.push_back(3);
	 int wrong = first_occr(first_oc, 1);
	 wrong = last_occr(first_oc, 2);


	 Solution_search_range search_range;
	 int A[1] = { 1 };
	 search_range.searchRange(A, 1, 1);

	 string conver_test = "";
	 conver_test = conver_test + 'a';

	 Solution_wordladder wordladder;
	 unordered_set<string> word_set = { "hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot" };
	 int word_ladder_ans = wordladder.ladderLength("hot", "dog", word_set);

	 Solution_perumu perumu;
	 vector<int> test_perumu;
	 test_perumu.push_back(5);
	 test_perumu.push_back(4);
	 test_perumu.push_back(2);
	 test_perumu.push_back(6);
	 test_perumu.push_back(8);
	 vector<vector<int>> res_perumu = perumu.permute(test_perumu);

	 Solution_subset subset;
	 vector<int> test_sub;
	 test_sub.push_back(0);
	 test_sub.erase(test_sub.begin());
	 test_sub.insert(test_sub.begin(), 0);
	 subset.subsetsWithDup(test_sub);

	 char* ha = "mississippi";
	 char* nb = "mississippi";
	 char* sb = strStr(ha, nb);

	 Solution_wordbreak wordbreak;
	 unordered_set<string> sset = { "a", "aa" };
	 string sss = "aaa";
	 vector<string> wordbreak_ret = wordbreak.wordBreak(sss, sset);


	 Solution_solve solve;
	 vector<vector<char>> input(6,vector<char>(6,'O'));
	 input[0][4] = 'X';
	 input[0][5] = 'X';
	 input[2][1] = 'X';
	 input[2][3] = 'X';
	 input[3][1] = 'X';
	 input[3][4] = 'X';
	 input[4][1] = 'X';
	 input[4][3] = 'X';
	 input[5][1] = 'X';
	 solve.solve(input);

	 char* a = "";
	 char* b = "";
	 strStr(a,b);

	 Solution_wordsearch wordsearch;
	 vector<vector<char> > board;
	 board.resize(2);
	 board[0].push_back('a');
	 board[0].push_back('b');
	 board[1].push_back('c');
	 board[1].push_back('d');
	 wordsearch.exist(board, "cdba");

	 Solution_min minpart;
	 int min_part = minpart.minCut("cdd");

	 Solution_longest longest;
	 string end = longest.longestPalindrome("abb");

	 Solution_part part;
	 part.partition("abc");

	 ListNode* leet = new ListNode(1);
	 partition(leet, 2);

	 char* st = "-2147483647";
	 float sst = _atoi(st);

	 set<int> ss;
	 ss.insert(4);
	 ss.insert(8);
	 ss.insert(1);
	 ss.insert(2);
	 set<int>::iterator it = ss.begin();
	 while (it != ss.end())
		 it++;

	 ListNode* s1 = new ListNode(1);
	 s1->next = new ListNode(2);
	 s1->next->next = new ListNode(3);
	 Solution t;
	 t.reverseKGroup(s1, 2);


 }
	