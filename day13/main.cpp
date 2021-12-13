#include <bits/stdc++.h>

#define ll long long
#define st first
#define nd second
#define pb push_back
using namespace std;
using namespace std::chrono;
ifstream fin("in.in");

char s[100000];
int v[10000][10000], n, m;

void vertical(int coord);

void hor(int coord);

int main() {
    auto start = high_resolution_clock::now();
    while (fin.getline(s, 10000)) {
        string a, b;
        char *p;
        if(s[0]=='f')
        {

            cout<<endl;
            p=strtok(s," ");
            p=strtok(NULL," ");
            p= strtok(NULL, " ");
            char *a=p;
            b=strtok(a,"=");
            string c = strtok(NULL,"=");
            int coord = stoi(c, nullptr)+1;
            if(b[0]=='x')
                vertical(coord);
            else hor(coord);
            continue;
        }
        p = strtok(s, ",");
        a = p;
        b = strtok(NULL, ",");
        int x = stoi(a, nullptr)+1;
        int y = stoi(b, nullptr)+1;
        swap(x,y);
        v[x][y]=1;
        n=max(x,n);
        m=max(y,m);
    }
    int nr=0;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j])
                nr++;
            if(v[i][j]==1)
        cout<<'#';
            else cout<<'.';
        }
    cout<<endl;
    }
            cout<<nr;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"time:"<<duration.count();
    return 0;

}

void hor(int coord) {
    for(int i=1+coord;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i][j]==1)
                v[max(coord-(i-coord),0)][j]=1;
    n-=coord;
}

void vertical(int coord) {
    for(int i=1;i<=n;i++)
        for(int j=coord+1;j<=m;j++)
            if(v[i][j]==1)
                v[i][max(coord-(j-coord),0)]=1;
    m-=coord;
}