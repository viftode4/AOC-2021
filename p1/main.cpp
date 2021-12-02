#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("in.in");

int n=0;
int a[100005];
int main() {

    int  ant=-1,x, nr=0;
    while(fin>>x)
        a[n++]=x;
    n--;
    for(int i=1;i<n;i++)
    {
        x = a[i-1]+a[i]+a[i+1];
        if(ant==-1)
        {ant=x;
        continue;}
        if(x>ant)
            nr++;
        ant=x;
    }
    cout<<nr;
    return 0;
}
