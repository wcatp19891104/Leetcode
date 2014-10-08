#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace::std;

class Solution {
public:
	int maxProfit_1(vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
		int m = prices[0];
		int p = 0;
		for (int i = 0; i<prices.size(); i++)
		{
			m = min(m, prices[i]);
			p = max(p, prices[i] - m);
		}
		return p;
	}
	int maxProfit_2(vector<int> &prices) {
		int profit = 0;
		if (prices.size() == 0)
			return 0;
		for (int i = 0; i<prices.size() - 1; i++)
		{
			if (prices[i]<prices[i + 1])
				profit += prices[i + 1] - prices[i];
		}
		return profit;
	}
private:
	//map<int, int> data;
};

void main()
{
	vector<int> t;
	
	/*t.push_back(4);
	t.push_back(1);
	t.push_back(2);*/
	Solution test;
	cout<<test.maxProfit_2(t);
}