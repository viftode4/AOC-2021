#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
ifstream fin("in.in");
char s[100000], *p;
int a[100000], n, maxh;

int cautbin();
int cost(int h);
bool ok(int mid);

int main() {
    auto sstart = high_resolution_clock::now();
    fin.getline(s,100000);
    p=strtok(s,",");
    while(p)
    {
        a[++n]=stoi(p, nullptr);
        maxh=max(maxh,a[n]);
        p=strtok(NULL,",");
    }
    int sol=cautbin();
    cout<<cost(sol);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}

int cautbin(){
    int l=0, r=maxh+1;
    while(r-1>l)
    {
        int mid=(l+r)/2;
        if(ok(mid))
            r=mid;
        else l=mid;
    }
    return r;
}

bool ok(int mid) {
    if(cost(mid)<=cost(mid+1))
        return true;
    return false;
}

int cost(int h)
{
    int sol=0;
    for(int i=1;i<=n;i++) {
        int x = fabs(a[i] - h);
        sol+= x*(x+1)/2;
    }
    return sol;
}
