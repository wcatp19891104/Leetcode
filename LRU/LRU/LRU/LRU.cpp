#include<iostream>
#include<queue>
#include<deque>
using namespace::std;

//class LRUCache{
//public:
//	LRUCache(int capacity) {
//		key_start = new int[capacity];
//		value_start = new int[capacity];
//		mark_start = new int[capacity];
//		for (int i = 0; i<capacity; i++)
//		{
//			key_start[i] = -1;
//			value_start[i] = -1;
//			mark_start[i] = 0;
//		}
//		_capacity = capacity;
//		mark = 0;
//		count = 0;
//	}
//	int find_LRU()
//	{
//		int min = 0;
//		for (int i = 0; i<_capacity; i++)
//		{
//			if (mark_start[i] == 0)
//				return i;
//			if (mark_start[min]>mark_start[i])
//				min = i;
//		}
//		return min;
//	}
//	int get(int key) {
//		for (int i = 0; i<_capacity; i++)
//		{
//			if (key == key_start[i])
//			{
//
//				mark++; 
//				mark_start[i] = mark;
//				return value_start[i];
//			}
//		}
//		//mark = -1;
//		return -1;
//	}
//	int get_label(int key)
//	{
//		for (int i = 0; i<_capacity; i++)
//		{
//			if (key == key_start[i])
//				return i;
//		}
//		return -1;
//	}
//	void set(int key, int value) {
//		if (count == _capacity)
//		{
//			int label = find_LRU();
//			key_start[label] = key;
//			value_start[label] = value;
//			mark_start[label] = mark;
//			mark++;
//		}
//		if (get_label(key) != -1)
//		{
//			value_start[get_label(key)] = value;
//			mark_start[get_label(key)] = mark;
//			mark++;
//			//count++;
//			return;
//		}
//		else
//		{
//			key_start[count] = key;
//			value_start[count] = value;
//			mark_start[count] = mark;
//			mark++;
//			count++;
//			return;
//		}
//	}
//	void display()
//	{
//		cout << count << endl;
//		for (int i = 0; i < _capacity; i++)
//		{
//			cout << key_start[i] << "--" << value_start[i] << "--" << mark_start[i] << endl;
//		}
//	}
//private:
//	int mark;
//	int count;
//	int _capacity;
//	int* key_start;
//	int* value_start;
//	int* mark_start;
//};

class LRUCache{
public:
	LRUCache(int capacity) {
		for (int i = 0; i<capacity; i++)
		{
			key_start.push_back(-1);
			value_start.push_back(-1);
		}
		_capacity = capacity;
	}
	int get(int key) {
		for (int i = 0; i<_capacity; i++)
		{
			if (key == key_start[i])
			{
				int temp = value_start[i];
				key_start.erase(key_start.begin() + i);
				value_start.erase(value_start.begin() + i);
				key_start.push_front(key);
				value_start.push_front(temp);
				return temp;;
			}
		}
		//mark = -1;
		return -1;
	}
	void set(int key, int value) {
		if (key_start.size() == _capacity)
		{
			key_start.pop_back();
			value_start.pop_back();
			key_start.push_front(key);
			value_start.push_front(value);
			return;
		}
		if (get(key) != -1)
		{
			value_start[0] = value;
			return;
		}
		else
		{
			key_start.push_front(key);
			value_start.push_front(value);
			return;
		}
	}
private:
	int _capacity;
	deque<int> key_start;
	deque<int> value_start;
};


void main()
{
	LRUCache test(2);
	test.set(2,1);
	test.set(2, 2);
	cout << test.get(2) << ", ";
	test.set(1, 1);
	test.set(4, 1);
	cout<<test.get(2);
}