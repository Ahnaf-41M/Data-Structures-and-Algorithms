/*We have to find a and b where n = a^2 - b^2 ...*/
#include<bits/stdc++.h>
using namespace std;

void fermat(int n)
{
    int a = ceil(sqrt(n));
    int b2 = a*a-n;
    int b = round(sqrt(b2));

    while(b*b != b2)
    {
        a+=1;
        b2 = a*a-n;
        b = round(sqrt(b2));
    }
    cout<<a<<' '<<b<<endl;
}
int main()
{
    int n = 23;
    fermat(n);
}

