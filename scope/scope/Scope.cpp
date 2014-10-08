#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace::std;

bool is_scopestart(char in)
{
	if ((in == '('))
		return true;
	if ((in == '['))
		return true;
	if ((in == '{'))
		return true;
	return false;
}

bool is_scopeend(char in)
{
	if ((in == ')'))
		return true;
	if ((in == ']'))
		return true;
	if ((in == '}'))
		return true;
	return false;
}

char n_mark(char mark)
{
	if (mark == '(')
		return ')';
	if (mark == '[')
		return ']';
	if (mark == '{')
		return '}';
}

bool scope(string in)
{
	vector<char> store;
	vector<char> pars;
	char mark = ' ';
	for (size_t i = 0; i < in.size(); i++)
	{
		if (is_scopestart(in[i])||is_scopeend(in[i]))
			store.push_back(in[i]);
	}
	size_t size = store.size();
	if (size == 0)
		return false;
	int count = size;
	for (size_t i = 0; i < size; i++)
	{
		if (is_scopestart(store[i]))
		{
			mark = store[i];
			pars.push_back(mark);
		}
		else if (is_scopeend(store[i]))
		{
			if (n_mark(mark) == store[i])
			{
				count--;
				count--;
				if (count == 0)
					return true;
				pars.pop_back();
				if (pars.size() == 0)
					continue;
				mark = pars.back();
			}
			else
				return false;
		}
	}
	if (count != 0)
		return false;
}


bool isvalid(string s)
{
	if ((s.size()>1) && (s[0] == '0'))
		return false;
	if (s.size()>3)
		return false;
	if ((stoi(s) >= 0) && (stoi(s) <= 255))
		return true;
	return false;
}
vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	if (s.size()<4 || s.size()>12)
		return res;
	for (int i = 1; i<4; i++)
	{
		string first = s.substr(0, i);
		if (!isvalid(first))
			continue;
		for (int j = 1; i + j<s.size() && j<4; j++)
		{
			string second = s.substr(i, i + j);
			if (!isvalid(second))
				continue;
			for (int k = 1; i + j + k<s.size() && k<4; k++)
			{
				string third = s.substr(i + j, i + j + k);
				string fouth = s.substr(i + j + k);
				if (isvalid(third) && (isvalid(fouth)))
				{
					res.push_back(first + "." + second + "." + third + "." + fouth);
				}
			}
		}
	}
	return res;
}

bool wordBreak(string s, unordered_set<string> &dict) {
	int start = 0;
	int step = 1;
	int size = s.size();
	int count = 0;
	while (start + step <= size)
	{
		if (dict.find(s.substr(start, step)) != dict.end())
		{
			start = start + step;
			count += step;
			step = 1;
		}
		else
			step++;
	}
	if (count != size)
		return false;
	return true;
}

void main()
{
	string test = "(1+2)+{[3*4+(5-6)]}";
	bool ans = scope(test);
	istringstream a("5");
	int k;
	a >> k;
	ostringstream b;
	b << 3;
	string x = b.str();

	restoreIpAddresses("0000");
	unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aaa");
	wordBreak("aaaaaaa", dict);
}