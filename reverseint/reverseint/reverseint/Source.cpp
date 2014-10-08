#include<vector>
using namespace::std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return 0;
		int a;
		int ret;
		if (x<0)
		{
			a = -1;
			ret = -x;
		}
		else
		{
			a = 1;
			ret = x;
		}

		if (ret / 10 == 0)
			return a*ret;
		else
		{
			int flag = 1;
			//int count = 0;
			while (ret / flag != 0)
			{
				//ret = ret / flag;
				flag = flag * 10;
				//count++;
			}
			flag = flag / 10;
			while (flag != 0)
			{
				int k = ret / flag;
				sto.push_back(k);
				ret = ret - flag*k;
				flag = flag / 10;
			}
			ret = 0;
			flag = 1;
			for (int i = 0; i<sto.size(); i++)
			{
				if (sto[i] == 0)
				{
					flag = flag * 10;
					continue;
				}
				else
				{

					ret += flag*sto[i];
					flag = flag * 10;
				}
			}
			return a*ret;
		}
	}
private:
	vector<int> sto;
};


void main()
{
	Solution test;
	test.reverse(123);
}