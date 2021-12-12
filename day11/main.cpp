#include <bits/stdc++.h>

#define ll long long
#define st first
#define nd second
#define pb push_back
using namespace std;
ifstream fin("in.in");

char s[100000];
int a[10000][10000], n;
long long sol = 0;
queue<pair<int, int>> q;
int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};

int interior(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n)
        return 0;
    return 1;
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
        cout << endl;
    }
}
int ok()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]!=0)
                return 1;

            return 0;
}
int main() {
    n = 1;
    while (fin.getline(s, 10000)) {
        for (int i = 0; s[i]; i++) {
            a[n][i + 1] = s[i] - '0';
        }
        n++;
    }
    n--;
    int t = 0;
    while (ok()) {
        t++;
        q = queue<pair<int, int>>();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                a[i][j]++;
                if (a[i][j] > 9)
                    q.push({i, j});
            }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.st, y = it.nd;
            if(a[x][y]==0)
                continue;
            sol++;
            a[x][y] = 0;
            for (int d = 0; d < 8; d++)
                if (a[x + di[d]][y + dj[d]] != 0 && interior(x + di[d], y + dj[d])) {
                    a[x + di[d]][y + dj[d]]++;
                    if (a[x + di[d]][y + dj[d]] > 9) {
                        q.push({x + di[d], y + dj[d]});
                    }
                }
        }
    }
    print();
    cout << t;
    return 0;

}
