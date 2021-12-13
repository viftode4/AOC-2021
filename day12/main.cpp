#include <bits/stdc++.h>

#define ll long long
#define st first
#define nd second
#define pb push_back
using namespace std;
using namespace std::chrono;
ifstream fin("in.in");

char s[100000];
int a[10000], r[10000], ok, x;
int viz[10000], n;
vector<int> g[1000];
map<string, int> m;
map<int, string> rm;
long long sol = 0;
queue<pair<int, int>> q;
int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
int start, xend;
void dfs(int i);
bool isOk(string h);
int main() {
    n = 1;
    int k = 0;
    auto sstart = high_resolution_clock::now();
    while (fin.getline(s, 10000)) {
        char *p = strtok(s, "-");
        string a = p;
        if (!m[a]) {
            m[a] = ++k;
            rm[k] = a;
        }
        string b = strtok(NULL, "-");
        if (!m[b]) {
            m[b] = ++k;
            rm[k] = b;
        }
        g[m[a]].pb(m[b]);
        g[m[b]].pb(m[a]);
        if (a[0] >= 'A' && a[0] <= 'Z')
            r[m[a]] = 1;
        if (b[0] >= 'A' && b[0] <= 'Z')
            r[m[b]] = 1;
        n++;
    }
    start = m["start"];
    xend = m["end"];
    dfs(start);
    //print();
    cout<<sol;
    return 0;

}

void dfs(int i) {
    string aaaa = rm[i];
    if (!r[i])
        viz[i] = 1;
    if (i == xend) {
        sol++;
        viz[i] = 0;
        return;
    }

    for (auto it: g[i])
        if (!viz[it] || (viz[it]&&!ok&&isOk(rm[it]))) {
            if(viz[it]) {
                viz[it]=0;
                ok=1;
                dfs(it);
                ok=0;
                viz[it]=1;
            }
            else dfs(it);
        }
    viz[i] = 0;
}

bool isOk(string h) {
    if(h=="start"||h=="end"||(h[0]>='A'&&h[0]<='Z'))
        return false;
    return true;
}
