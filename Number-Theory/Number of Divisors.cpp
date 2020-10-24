#include<bits/stdc++.h>

using namespace std;
int main()
{
     int n = 12,i,NOD=0;

     for(i = 1; i <= sqrt(n); i++)
     {
          if(n%i == 0)
          {
               if(n/i == i)
                    NOD++;
               else
                    NOD += 2;
          }
     }
     //including 1 and n itself
     cout<<"Number of divisor of "<<n<<" is: "<<NOD<<endl;

     return 0;
}

