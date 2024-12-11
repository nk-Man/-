#pragma once
//stack:1 push_back(x)
//      2  pop()
//      3  top()
//      4  empty()
// //   5  size()
//当我创建对象时，应该生成一个数组stack，执行push操作会向数组末端加入元素
#include<iostream>
using namespace std;
class mystack_array
{
private:
	int Top = -1;
	int len;
public:
	mystack_array(size_t N)//传入初始长度len
	{
		 len = N;
	}
	mystack_array()
	{
		len = 0;
	}
	int* c = new int[len];
	void push_back(int x)
	{
		if (Top == len - 1)//满数组
		{
			static int* d = new int[2 * len];
			for (int i = 0; i <= Top; i++)
			{
				d[i] = c[i];
			}
			d[++Top] = x;
		}
		else c[++Top] = x;
	}
	void pop()
	{
		if (Top == -1)
			throw "Error!";
		else Top--;
	}
	int top() const
	{
		if (Top == -1)
			throw "Error!";
		else return c[Top];
	}
	bool empty()
	{
		if (Top == -1) return 1;
		else return 0;
	}
	int size() const
	{
		if (Top == -1)
			throw"Error!";
		else return Top + 1;
	}
};
//我的基于数组实现的stack：它拥有动态内存分配功能，并且拥有常见stack的5项功能
//缺点：没有实现stack之间的拷贝

