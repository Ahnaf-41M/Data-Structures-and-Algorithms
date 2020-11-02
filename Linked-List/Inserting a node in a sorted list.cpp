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
	void insert(Node *tmp)
	{
		if (head == NULL) { //if the list is empty
			head = tmp;
			tail = tmp;
		}
		else {
			Node *p = new Node, *q = new Node;
			p = head; q = NULL;

			//move p until a greater value is found
			while (p && p->data < tmp->data) { 
				q = p;
				p = p->next;
			}
			if (p == head) {
				tmp->next = p;
				head = tmp;
			}
			else {
				tmp->next = q->next;
				q->next = tmp;
			}
		}
	}
};

linked_list L;

void Create(int a[], int n)
{
	Node *tmp = new Node;
	tmp->data = a[0];
	tmp->next = NULL;
	L.insert(tmp);

	for (int i = 1; i < n; i++) {
		tmp = new Node;
		tmp->data = a[i];
		tmp->next = NULL;
		L.insert(tmp);
	}
}
void Display()
{
	Node *move = L.head;
	while (move)
	{
		cout << move->data << " ";
		move = move->next;
	}
}
int main()
{
	int a[] = {2, 5, 6, 8, 9, 10};
	int n = sizeof(a) / sizeof(a[0]);
	Create(a, n);

	int Q, x; cin >> Q;

	while (Q--)
	{
		cin >> x;
		Node *tmp = new Node;
		tmp->data = x;
		tmp->next = NULL;
		L.insert(tmp);
	}
	cout << "Sorted list:\n";
	Display();
}