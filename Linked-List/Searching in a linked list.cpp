#include<bits/stdc++.h>
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

   void add(int n)
   {
      Node *tmp = new Node;
      tmp->data = n;
      tmp->next = NULL;

      if (head == NULL)
      {
         head = tmp;
         tail = tmp;
      }
      else
      {
         tail->next = tmp;
         tail = tail->next;
      }
   }

};
bool Search(Node *p,int key)
{
   while(p!=NULL)
   {
      if(p->data == key)
         return true;
      p = p->next;
   }
   return false;
}
int main()
{
   linked_list L1;
   int t, n,key;

   cin >> t;

   while (t--)
   {
      cin >> n;
      L1.add(n);
   }
   Node *it = new Node;
   it = L1.head;

   cin >> key;

   if(Search(L1.head,key))
      cout << key <<" is present in the linked list.\n";
   else
      cout << key <<" is not present in the linked list.\n";
}
