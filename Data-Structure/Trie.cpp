#include <bits/stdc++.h>
using namespace std;
#define K 26

struct Node
{
    Node *next[K];
    bool isEnd = false;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    Node *getNode()
    {
        return new Node();
    }
    void insert(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
            {
                cur->next[val] = getNode();
            }
            cur = cur->next[val];
        }
        cur->isEnd = true;
    }
    bool search(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
            {
                return false;
            }
            cur = cur->next[val];
        }
        return cur->isEnd;
    }
    bool isPrefix(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
            {
                return false;
            }
            cur = cur->next[val];
        }
        return true;
    }
};
int main()
{
    // type 1 = insert, type 2 = search for the word, type 3 = search fro prefix
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> word = {"hello", "help", "help", "hel", "hel"};
    int n = type.size();
    Trie T;

    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            T.insert(word[i]);
        }
        else if (type[i] == 2)
        {
            if (T.search(word[i]))
                cout << "Word found!\n";
            else
                cout << "Word not found!\n";
        }
        else
        {
            if (T.isPrefix(word[i]))
                cout << "Prefix found!\n";
            else
                cout << "Prefix not found\n";
        }
    }
}