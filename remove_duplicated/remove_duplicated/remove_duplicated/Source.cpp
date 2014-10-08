#include<vector>
using namespace::std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i = 0;
		int j = 0;
		int count = 0;
		vector<int> temp;
		while (j<n)
		{
			if (A[j] != A[i])
			{
				if ((j - i) == 1)
				{
					//count++;
					temp.push_back(A[i]);
					i = j;
					continue;
				}
				else if ((j - i)>1)
				{
					//count+=2;
					temp.push_back(A[i]);
					temp.push_back(A[i]);
					i = j;
					continue;
				}
			}
			j++;
			if (j == n)
			{
				if ((j - i) == 1)
				{
					temp.push_back(A[i]);
					break;
				}
				else if ((j - i)>1)
				{
					temp.push_back(A[i]);
					temp.push_back(A[i]);
					break;
				}
			}
		}
		count = temp.size();
		int* B = new int[count];
		for (int i = 0; i<count; i++)
			B[i] = temp[i];
		A = B;
		return count;
	}
};


void main()
{
	int A[4] = { 1, 1, 1, 2 };
	Solution test;
	test.removeDuplicates(A, 4);
}