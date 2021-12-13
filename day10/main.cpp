#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
ifstream fin("in.in");

char s[100000], a[100000];
long long sol = 0;
char o[] = "[{<(", cl[] = "]}>)";
vector<long long>v;
int main() {
    auto sstart = high_resolution_clock::now();
    while (fin.getline(s, 10000)) {
        int n = -1, ok = 0;
        for (int i = 0; s[i]; i++) {
            a[++n] = s[i];
            if (strchr(cl, a[n])) {
                if (a[n - 1] == '<' && a[n] == '>' || a[n - 1] == '(' && a[n] == ')' ||
                    a[n - 1] == '{' && a[n] == '}' || a[n - 1] == '[' && a[n] == ']')
                    n -= 2;
                else if (a[n] == '>')
                    n -= 2, ok = 1;
                else if (a[n] == '}')
                    n -= 2, ok = 1;
                else if (a[n] == ']')
                    n -= 2, ok = 1;
                else if (a[n] == ')')
                    n -= 2, ok = 1;
                else n -= 2, ok = 1;
                if (ok)
                    break;
            }
        }
        sol = 0;

        if (!ok && n > -1) {
            while (n > -1) {
                if (a[n] == '(')
                    sol = sol * 5 + 1;
                else if (a[n] == '<')
                    sol = sol * 5 + 4;
                else if (a[n] == '[')
                    sol = sol * 5 + 2;
                else
                    sol = sol * 5 + 3;
                n--;
            }
            v.push_back(sol);
        }

    }
    sort(v.begin(), v.end());
    cout << v[(v.size())/2];
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;

}
