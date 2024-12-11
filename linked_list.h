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
//��������飬����Ϊһ�ִ���һϵ�д洢ͬ���������ݵ��б���ʹ�ã����Ǹ�������

	static class Node
	{
	public:
		int data;
		Node* next;

		Node() = default;
	};

	Node* Head = nullptr;//ȫ�ֱ�������ͷhead,�⽫�����Ǵ�������ĵ�һ����

	 void insert(int position, int data)
	{
		//�����ڴ��
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
		for (int i = 0; i < position - 1; i++)//ѭ��position-1��
		{
			head = head->next;
		}
		temp->next = head->next;
		head->next = temp;
	}//8bytes���O(n)

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
		Node* prev = move;//prevǰ����position-1λ��
		move = move->next;//moveǰ����positionλ��
		prev->next = move->next;
		delete[] move;
	}

	 void reverse()//����������ת����
	{

		Node* prev, * current, * next;//12bytes
		prev = nullptr;
		current = Head;
		while (current != nullptr)
		{
			next = current->next;//������һ���ڵ�ĵ�ַ
			current->next = prev;//�ı�����
			prev = current;//�ƶ�
			current = next;//�ƶ�

		}
		Head = prev;//���գ�ͷָ��������һ���ڵ�ĵ�ַ
	}
	// �ռ䣺12bytes(3ptrs) ʱ��: O(n)
	 void Reverse(Node* head)//�ݹ鷽ʽ��ת����
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
	 void Print()//������ʽ�������ӡЧ�ʱȵݹ��
	{
		Node* mover = Head;
		while (mover != nullptr)
		{
			cout << mover->data << " ";
			mover = mover->next;
		}
		cout << endl;
	}//4bytes,O(n)

	 void PrintT(Node* move)//�ݹ鷽ʽ�����ӡ���������ӡЧ�ʲ��
	{

		if (move == nullptr)
		{
			return;
		}
		PrintT(move->next);
		cout << move->data << " ";
	}//O(2n),���ú�������stackռ�ݶ����ڴ棬ʱ��Ҳ�п���
};
//insert(position,x) ���뺯��
//Delete(position) ɾ������
//reverse() ������ʽ��ת����
//Reverse() �ݹ鷽ʽ��ת����
//Print()�����ӡ
//PrintT()�����ӡ

