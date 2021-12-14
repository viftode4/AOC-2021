#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
ifstream fin("in.in");
string c;
char s[100000];
map<string, string> f;
map<string, long long> m;
map<string, long long> tmp;
map<char,long long> xfr;
int main() {
    auto start = high_resolution_clock::now();
    fin >> c;
    for(auto it:c)
        xfr[it]++;
    fin.get();
    fin.get();
    while (fin.getline(s, 100000)) {
        char *p = strtok(s, " -> ");
        string a, b;
        a = p;
        b = strtok(NULL, " -> ");
        f[a] = b;
    }
    for (int i = 0; i < c.size()-1; i++) {
        string a = c.substr(i,2);
        if(!f.count(a))
            continue;
        m[a]++;
    }
    int t = 40;
    while (t--) {
        for (auto it: m) {
            if(it.second==0)
                continue;
            string a = it.first;
            long long fr = it.second;
            string x = f[a];
            xfr[x[0]]+=fr;
            string l = a[0] + x;
            string r = x + a[1];
            tmp[l] += fr;
            tmp[r] += fr;
        }
        m.clear();
        for(auto it:tmp)
            m[it.first]=it.second;
        tmp.clear();
    }
    long long mini = 1000000000000000000, maxi = 0;
    for (auto it: xfr) {
            mini = min(mini, it.second);
        maxi = max(maxi, it.second);
    }
    cout<<maxi-mini;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"TIME:"<<duration.count();
    return 0;
}
