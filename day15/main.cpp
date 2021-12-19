#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define st first
#define nd second
#define pb push_back
#define ins insert
ifstream fin("in.in");
char s[1000];
int a[6000][6000], n, m;
int v[6000][6000];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
priority_queue<pair<int, pair<int, int> > > q;

int interior(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m)
        return 0;
    return 1;
}

int main() {

    while (fin.getline(s, 1000)) {
        n++;
        for (int i = 0; s[i]; i++) {
            a[n][i + 1] = s[i] - '0';
            m = i + 1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 2; k <= 5; k++) {
                a[(k - 1) * n + i][j] = (a[(k - 2) * n + i][j] + 1) % 10;
                if (a[(k - 1) * n + i][j] == 0)
                    a[(k - 1) * n + i][j] = 1;
            }
        }
    n = n * 5;


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 2; k <= 5; k++) {
                a[i][(k - 1) * m + j] = (a[i][(k - 2) * m + j] + 1) % 10;
                if (a[i][(k - 1) * m + j] == 0)
                    a[i][(k - 1) * m + j] = 1;
            }
        }
    m = m * 5;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v[i][j] = INT_MAX;

    v[1][1] = 0;
    q.push({0, {1, 1}});

    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        int val = -top.st;
        int x = top.nd.st, y = top.nd.nd;
        //cout<<val<<'\n';
        if (val > v[x][y])
            continue;
        for (int d = 0; d < 4; d++) {
            int dx = x + di[d], dy = y + dj[d];
            if (interior(dx, dy) && v[dx][dy] > val + a[dx][dy]) {
                v[dx][dy] = a[dx][dy] + val;
                q.push({-v[dx][dy], {dx, dy}});
            }
        }
    }
    cout << v[n][m] << '\n';
    return 0;
}
