/*Spiral of equilateral triangles with side lengths which follow the Padovan sequence*/
/*1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37,...*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int pad[500];

     pad[0] = pad[1] = pad[2] = 1;

     for(int i = 3; i < 500; i++)
          pad[i] = pad[i-2] + pad[i-3]; /*This is the formula*/
     cout<<pad[5]<<endl;
}
