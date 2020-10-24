#include<bits/stdc++.h>
using namespace std;

void modBig(string s,int b)
{
    int mod=0;
    vector<int> v;

    for(int i = 0; i < s.size(); i++)
    {
        int digit = s[i] - 48, quotient;

        mod = mod*10 + digit;

        quotient = mod/b;
        v.push_back(quotient);

        mod %= b;
    }
    cout<<"Remainder: "<<mod<<endl;
    cout<<"Quotient: ";

    bool lead_zero = true;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]==0 && lead_zero)
            continue;

        lead_zero = false;
        cout<<v[i];
    }
    cout<<endl;
}
int main()
{
    int b = 487;
    string a = "14598499948265358486";

    modBig(a,b);

}
