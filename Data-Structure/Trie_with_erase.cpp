#include <bits/stdc++.h>
using namespace std;
#define K 26

struct Node
{
    Node *next[K];
    int cntEndwith = 0;
    int cntPrefix = 0;
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
                cur->next[val] = getNode();

            cur = cur->next[val];
            cur->cntPrefix++;
        }
        cur->cntEndwith++;
    }

    int cntEqualWords(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
                return 0;
            cur = cur->next[val];
        }
        return cur->cntEndwith;
    }

    int cntPrefixes(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
                return 0;
            cur = cur->next[val];
        }
        return cur->cntPrefix;
    }

    void erase(string s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int val = ch - 'a';
            if (cur->next[val] == NULL)
                return;
            cur = cur->next[val];
            cur->cntPrefix--;
        }
        cur->cntEndwith--;
    }
};
int main()
{
    Trie T;
    T.insert("good");
    T.insert("good");

    cout << "Number of words starts with prefix 'go': " << T.cntPrefixes("go") << "\n"; // 2

    T.insert("cste");
    T.erase("good");

    cout << "Number of words equal to 'good': " << T.cntEqualWords("good") << "\n"; // 1
    cout << "Number of words equal to 'cste': " << T.cntEqualWords("cste") << "\n"; // 1
}