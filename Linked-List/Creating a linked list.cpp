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
	void add(int x)
	{
		Node *tmp = new Node;
		tmp->data = x;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp; //make tail->next point to tmp
			tail = tail->next; //move tail to tail->next (tmp)
		}
	}
};
int main()
{
	linked_list L1;
	int n, t; cin >> t;

	while (t--)
	{
		cin >> n;
		L1.add(n);
	}
	Node *p = new Node;
	p = L1.head;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}