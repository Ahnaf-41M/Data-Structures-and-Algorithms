#include<bits/stdc++.h>
using namespace std;
#define MAX 5000005
int phi[MAX];
void find_phi()
{
    int i,j;
    for(i=2; i<=MAX; i++)
        phi[i]=i;
    for(i=2; i<=MAX; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=MAX; j+=i)
                phi[j]-=phi[j]/i; //Inclusion_Exclusion Law used
        }
    }
}
int main()
{
    find_phi();
    int n;

    while(true)
    {
        cin>>n;
        cout<<phi[n]<<endl;
    }
}
