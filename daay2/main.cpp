#include <bits/stdc++.h>
using namespace  std;
ifstream fin("in.in");
string s;
int x, y, v, aim;
int main() {
    while(fin>>s)
    {
        fin>>v;
        if(s=="forward") {
            x += v;
            y+=v*aim;
        }
        else if(s=="down")
            aim+=v;
        else aim-=v;
    }
    cout<<x*y;
    return 0;
}
