#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
ifstream fin("in.in");
int a[5000][5000];
int x, y, xx, yy;
char s[1005];
void print();
int main() {
    auto sstart = high_resolution_clock::now();
    while (fin.getline(s, 1000)) {
        char *p = strtok(s, " -> ");
        char *q = strtok(NULL, " -> ");

        p = strtok(p, ",");
        x = stoi(p, nullptr, 10);
        p = strtok(NULL, ",");
        y = stoi(p, nullptr, 10);
        q = strtok(q, ",");
        xx = stoi(q, nullptr, 10);
        q = strtok(NULL, ",");
        yy = stoi(q, nullptr, 10);
        swap(x,y);
        swap(xx, yy);
        if (yy == y)
            for (int i = min(x, xx); i <= max(x, xx); i++)
                a[i][y]++;
        else if (xx == x)
            for (int i = min(y, yy); i <= max(y, yy); i++)
                a[x][i]++;
        else {
            int sx = 0, sy = 0;
            if (x < xx && y < yy)
                sx = 1, sy = 1;
            else if (x < xx && y > yy)
                sx = 1, sy = -1;
            else if (x > xx && y < yy)
                sx = -1, sy = 1;
            else sx = -1, sy = -1;
            while (x != xx && y != yy) {
                a[x][y]++;
                x += sx;
                y += sy;
            }
            a[xx][yy]++;
        }
    }
    int sol = 0;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if (a[i][j] > 1)
                sol++;
    cout << sol;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}

void print() {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}