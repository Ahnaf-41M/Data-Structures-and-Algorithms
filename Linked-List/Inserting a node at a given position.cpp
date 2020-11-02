#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linked_list
{
public:
	Node *head, *tail;

	linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int pos, int x)
	{
		if (pos == 0)
		{
			Node *tmp = new Node;
			tmp->data = x;
			tmp->next = head;
			head = tmp;
		}
		else
		{
			Node *tmp = new Node, *p;
			tmp->data = x;
			p = head;

			for (int i = 0; i < pos - 1 && p; i++)
				p = p->next;
			tmp->next = p->next;
			p->next = tmp;
		}
	}
};
int main()
{
	linked_list L;

	int t, n, pos, x;
	L.insert(0, 5);
	L.insert(1, 2);
	L.insert(2, 7);
	L.insert(2, 10);
	L.insert(0, 11);

	Node *p = new Node;
	p = L.head;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}