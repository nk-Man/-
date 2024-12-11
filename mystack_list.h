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
	}//������ͷ����һ���ڵ�
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
//��stack��ʵ�ּ���ȫ������stlģ��������list
