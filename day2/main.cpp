#include <bits/stdc++.h>
using namespace  std;
using namespace  std::chrono;
ifstream fin("in.in");
string s;
int x, y, v, aim;
int main() {
    auto sstart = chrono::high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}
