#pragma once
#include<iostream>
#include<list>
using namespace std;
class mystack_list
{
private:
	list<int> S;
	int len;
	int Top = -1;
public:
	mystack_list(int N)
	{
		len = N;
	}
	mystack_list()
	{
		len = 0;
	}
	void push_back(int x)
	{
		S.insert(S.begin(), x);
		Top++;
	}//在链表头插入一个节点
	void pop()
	{
		if (S.empty()) return;
		S.pop_front();
		Top--;
	}
	int top() const
	{
		if (!S.empty()) return S.back();
		else throw"Error!";
		return NULL;
	}
	bool empty() const
	{
		if (Top == -1) return 1;
		else return 0;
	}
	int size() const
	{
		if (Top == -1) throw"Error!";
		else return Top + 1;
	}
};
//本stack的实现几乎全部基于stl模板库的链表list
//事实上，我完全可以使用另一个头文件linked_list.h里的链表结构来完成这件事
