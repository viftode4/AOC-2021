#include <bits/stdc++.h>

#define ll long long
#define st first
#define nd second
#define pb push_back
using namespace std;
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
vector<string> res;
vector<string> ssol;
void dfs(int i);
////
////int interior(int i, int j) {
////    if (i < 1 || i > n || j < 1 || j > n)
////        return 0;
////    return 1;
////}
//
//void print() {
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++)
//            cout << a[i][j];
//        cout << endl;
//    }
//}
//
//int ok() {
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            if (a[i][j] != 0)
//                return 1;
//
//    return 0;
//}

bool isOk(string h);

int main() {
    n = 1;
    int k = 0;
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
    cout<<ssol.size();
    sort(ssol.begin(),ssol.end());
    ssol.erase( unique( ssol.begin(),  ssol.end() ),  ssol.end() );

    return 0;

}

void dfs(int i) {
    res.pb(rm[i]);
    string aaaa = rm[i];
    if (!r[i])
        viz[i] = 1;
    if (i == xend) {
        sol++;
        string k="";
        for(auto it:res)
            k += it + " ";

        ssol.pb(k);
        res.pop_back();
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
    res.pop_back();
    viz[i] = 0;
}

bool isOk(string h) {
    if(h=="start"||h=="end"||(h[0]>='A'&&h[0]<='Z'))
        return false;
    return true;
}
