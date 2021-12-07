#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.in");
long long a[10], n, x, timer=256;
long long sol;
char in[100000];

void print();

int main() {

    fin.getline(in,1000);
    char *p = strtok(in,",");
    while(p)
    {
        x=stoi(p, nullptr);
        a[x]++;
        p=strtok(NULL,",");
    }
    while(timer>0)
    {
        x=0;
        for(int i=8;i>0;i--)
        {
            long long tmp = a[i];
            a[i]=x;
            x=tmp;
        }
        a[6]+=a[0];
        a[8]+=a[0];
        a[0]=x;
        timer--;
    }
    long long sol=0;
    for(int i=0;i<=8;i++)
        sol+=a[i];
    cout<<sol;
    return 0;
}

void print()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

