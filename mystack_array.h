#pragma once
//stack:1 push_back(x)
//      2  pop()
//      3  top()
//      4  empty()
// //   5  size()
//���Ҵ�������ʱ��Ӧ������һ������stack��ִ��push������������ĩ�˼���Ԫ��
#include<iostream>
using namespace std;
class mystack_array
{
private:
	int Top = -1;
	int len;
public:
	mystack_array(size_t N)//�����ʼ����len
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
		if (Top == len - 1)//������
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
//�ҵĻ�������ʵ�ֵ�stack����ӵ�ж�̬�ڴ���书�ܣ�����ӵ�г���stack��5���
//ȱ�㣺û��ʵ��stack֮��Ŀ���

