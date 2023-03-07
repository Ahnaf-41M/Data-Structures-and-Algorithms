#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;

int trie[MAXN][26], nxt = 1, ans;
bool isleaf[MAXN];

void insert(string s)
{
    int root = 1;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!trie[root][c]) {
            trie[root][c] = ++nxt;
        }
        root = trie[root][c];
    }

    isleaf[root] = true;
}
bool search(string s)
{
    int root = 1;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!trie[root][c]) {
            return false;
        }
        root = trie[root][c];
    }
    return isleaf[root];
}
int main()
{
    insert("hello");
    insert("help");
    insert("hel");
    insert("hello");

    if(search("help")) cout << "found\n";
    else cout << "not found!\n";
}

