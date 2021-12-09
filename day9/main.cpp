#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back

using namespace std;

ifstream fin("in.in");


int n=0, m=0, a[10000][10000];
int di[]={0,1,-1,0};
int dj[]={1,0,0,-1};
int res, size;

int viz[10000][10000];
vector<int> sol;
int interior(int i, int j);
void dfs(int i, int j)
{
    size++;
    viz[i][j]=1;
    for(int d=0;d<4;d++)
        if(a[i+di[d]][j+dj[d]]>a[i][j]&&a[i+di[d]][j+dj[d]]!=9&&interior(i+di[d],j+dj[d])&&!viz[i+di[d]][j+dj[d]])
            dfs(i+di[d],j+dj[d]);
}
int main() {
    char s[100005];
    char c;

    while(fin.getline(s,10000))
    {
        n++;
        int size = strlen(s);
        m=max(m,size);
        for(int i=0;s[i];i++)
            a[n][i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int ok=1;
            for(int d=0;d<4;d++)
                if(a[i+di[d]][j+dj[d]]<=a[i][j]&&interior(i+di[d],j+dj[d]))
                    ok=0;
            if(ok&&!viz[i][j]&&a[i][j]!=9)
            {
                size=0;
                dfs(i,j);
                sol.push_back(size);
                size=0;
            }
        }
    sort(sol.begin(),sol.end());
        int x=sol.back();
    sol.pop_back();
    int y=sol.back();
    sol.pop_back();
    int z=sol.back();
    cout<<x*y*z;
    return 0;
}
int interior(int i, int j)
{
    if(i>n||i<1||j>m||j<1)
        return 0;
    return 1;
}


