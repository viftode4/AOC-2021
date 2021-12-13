#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
ifstream fin("in.in");
string s[10000];
set<string> a, b, c;
int n = 1, size, x, y;
int fr[20];

int main() {
    auto sstart = chrono::high_resolution_clock::now();
    while (fin >> s[n])
        n++;
    n--;
    for (int i = 1; i <= n; i++)
        a.insert(s[i]);
    c = a;
    while (a.size() > 1) {
        size++;
        int nr = 0;
        for (auto it: a)
            if (it[0] == '1')
                nr++;
        x = x << 1;
        if (nr >= (a.size() + 1) / 2) {
            x += 1;
            for (auto it: a)
                if (it[0] == '1')
                    b.insert(it.substr(1, 100));
        } else {
            for (auto it: a)
                if (it[0] == '0')
                    b.insert(it.substr(1, 100));
        }
        a = b;
        b.clear();
    }
    string t = *a.begin();
    for (int i = 0; i < t[i]; i++) {
        x = x << 1;
        if (t[i] == '1')
            y++;
    }
    a = c;
    while (a.size() > 1) {
        int nr = 0;
        for (auto it: a)
            if (it[0] == '0')
                nr++;
        y = y << 1;
        if (nr <= a.size() / 2) {

            for (auto it: a)
                if (it[0] == '0')
                    b.insert(it.substr(1, 100));
        } else {
            y += 1;
            for (auto it: a)
                if (it[0] == '1')
                    b.insert(it.substr(1, 100));
        }
        a = b;
        b.clear();
    }
    t = *a.begin();
    for (int i = 0; i < t[i]; i++) {
        y = y << 1;
        if (t[i] == '1')
            y++;
    }
    cout << x * y;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}
