#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.in");
vector<int> v;
int a[1000][7][7], m, x;
int win[1000];
int viz[1000][7][7];
int numbers[100000], n;
char s[100000], *p;
void bingo(int x);
int verif(int i, int j, int k);
int main() {
    fin.getline(s, 10000);
    p = strtok(s, ",");
    while (p) {
        numbers[++n] = stoi(p, nullptr);
        p = strtok(NULL, ",");
        cout << numbers[n] << ' ';
    }
    while (fin >> x) {
        a[++m][1][1] = x;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
                if (i != 1 || j != 1)
                    fin >> a[m][i][j];
    }
    cout<<endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++)
                cout<<a[i][j][k]<<' ';
            cout<<'\n';
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++) {
        //cout<<numbers[i]<<' ';
        bingo(numbers[i]);
    }
    cout<<v.back();
    return 0;
}
void bingo (int x){
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++)
                if(a[i][j][k]==x)
                {
                    viz[i][j][k]=1;
                    if(verif(i,j,k))
                    {
                        int sum=0;
                        for(int x=1;x<=5;x++)
                            for(int y=1;y<=5;y++)
                                if(viz[i][x][y]==0)
                                    sum+=a[i][x][y];
                        if(!win[i])
                        {v.push_back(x*sum); win[i]=1;}

                    }
                }
        }
    }
}
int verif(int x, int y, int z)
{
    int ok=0;
    for(int i=1;i<=5;i++)
        if(viz[x][y][i]==0)
            ok=1;
    if(!ok)
        return 1;
    ok=0;
    for(int i=1;i<=5;i++)
        if(viz[x][i][z]==0)
            ok=1;
    if(!ok)
        return 1;
    return 0;
}
