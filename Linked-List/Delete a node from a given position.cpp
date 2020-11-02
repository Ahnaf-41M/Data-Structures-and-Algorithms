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
			tail->next = tmp;
			tail = tmp;
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
void Delete(int indx)
{
	Node *p = new Node, *q = NULL;
	p = L.head;
	if (indx == 1) {
		Node *tmp = L.head;
		L.head = tmp->next;
		delete tmp;
	}
	else {
		for (int i = 0; i < indx - 1 && p; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
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
	int a[] = {5, 2, 6, 1, 7, 3};
	int n = sizeof(a) / sizeof(a[0]);
	Create(a, n);

	Delete(3);
	Display(); //5 2 1 7 3
}