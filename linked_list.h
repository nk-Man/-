#pragma once
#include<iostream>
using namespace std;
class linked_list
{
	//I wanna create a data structure called"linked list"
//its features are as follwed:
//1. Insert a node at any position;
//2. Rand access
//3. modify any node's data by index;
//4. print all nodes'data;
//5. Reverse
//链表和数组，都作为一种创建一系列存储同种类型数据的列表来使用，它们各有优势

	static class Node
	{
	public:
		int data;
		Node* next;

		Node() = default;
	};

	Node* Head = nullptr;//全局变量，表头head,这将是我们创建链表的第一件事

	 void insert(int position, int data)
	{
		//创建内存块
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;

		//
		Node* head = Head;
		if (Head == nullptr)
		{
			Head = temp;
			return;
		}
		for (int i = 0; i < position - 1; i++)//循环position-1次
		{
			head = head->next;
		}
		temp->next = head->next;
		head->next = temp;
	}//8bytes，最坏O(n)

	 void modify(int position, int data)
	{
		Node* move = Head;
		for (int i = 0; i < position; i++)
		{
			move = move->next;
		}
		move->data = data;
	}

	 void Delete(int position)
	{

		if (position == 1)
		{
			Node* prev = Head;
			Head = Head->next;
			delete[] prev;
			return;
		}

		Node* move = Head;
		for (int i = 0; i < position - 2; i++)
		{
			move = move->next;
		}
		Node* prev = move;//prev前往第position-1位置
		move = move->next;//move前往第position位置
		prev->next = move->next;
		delete[] move;
	}

	 void reverse()//迭代方法反转链表
	{

		Node* prev, * current, * next;//12bytes
		prev = nullptr;
		current = Head;
		while (current != nullptr)
		{
			next = current->next;//保存下一个节点的地址
			current->next = prev;//改变链接
			prev = current;//移动
			current = next;//移动

		}
		Head = prev;//最终，头指针等于最后一个节点的地址
	}
	// 空间：12bytes(3ptrs) 时间: O(n)
	 void Reverse(Node* head)//递归方式反转链表
	{
		if (head->next == nullptr)
		{
			Head = head;
			return;
		}
		Reverse(head->next);
		head->next->next = head;
		head->next = nullptr;

	}
	 void Print()//迭代方式，正向打印效率比递归高
	{
		Node* mover = Head;
		while (mover != nullptr)
		{
			cout << mover->data << " ";
			mover = mover->next;
		}
		cout << endl;
	}//4bytes,O(n)

	 void PrintT(Node* move)//递归方式逆序打印链表，逆序打印效率差不多
	{

		if (move == nullptr)
		{
			return;
		}
		PrintT(move->next);
		cout << move->data << " ";
	}//O(2n),调用函数会在stack占据额外内存，时间也有开销
};
//insert(position,x) 插入函数
//Delete(position) 删除函数
//reverse() 迭代方式反转链表
//Reverse() 递归方式反转链表
//Print()正序打印
//PrintT()逆序打印

