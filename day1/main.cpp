#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

ifstream fin("in.in");

int n=0;
int a[100005];
int main() {
    auto sstart = chrono::high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}
