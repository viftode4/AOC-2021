#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back

using namespace std;
using namespace std::chrono;

ifstream fin("in.in");
int sol;
map<char,int> m;
map<int,char>rm;
map<char,int>fr;
vector<string> v[10];
string a;
string ha[10];
map<string,int> fi;

string charToString(char* a)
{
    string s="";
    for(int i=0;a[i];i++) {
        s += a[i];
        fr[a[i]]++;
    }
    return s;
}
int bcd[10][10]={
        {1,2,3,4,5,6},
        {2,3},
        {1,2,7,5,4},
        {1,2,3,4,7},
        {2,3,6,7},
        {1,6,7,3,4},
        {1,3,4,5,6,7},
        {1,2,3},
        {1,2,3,4,5,6,7},
        {1,2,3,4,6,7}
};


/*            1
 *          *****
 *       6  *   * 2
 *          * 7 *
 *          *****
 *       5  *   * 3
 *          *   *
 *          *****
 *            4
 */
int main() {
    auto sstart = high_resolution_clock::now();
    char s[100005],*p,*c, *d;
    char f[10];

    while(fin.getline(s,10000))
    {
        p=strtok(s,"|");
        d=strtok(NULL,"|");
        c=p;
        p=strtok(c," ");
        rm.clear();
        m.clear();
        fr.clear();
        for(int i=0;i<10;i++)
            v[i].clear();
        fi.clear();
        while(p){
            string s= charToString(p);
            v[s.size()].push_back(s);
            p=strtok(NULL," ");
        }
        // BCD 3, 4, 5, 6
        for(auto it: fr)
        {
            if(it.nd==4)
                m[it.st]=5,rm[5]=it.st;
            else if(it.nd==6)
                m[it.st]=6,rm[6]=it.st;
            else if(it.nd==9)
                m[it.st]=3,rm[3]=it.st;
        }
        a = v[2].back();
        // BCD 2 from 1 encoding
        for(auto it:a)
        {
            if(it!=rm[3])
            {
                m[it]=2;
                rm[2]=it;
                break;
            }
        }
        //BCD 1 from 7 encoding
        a= v[3].back();
        for(auto it : a)
        {
            if(it!=rm[3]&&it!=rm[2])
            {
                m[it]=1;
                rm[1]=it;
                break;
            }
        }
        //BCD 7 from 4 encoding
        a=v[4].back();
        for(auto it:a)
        {
            if(it!=rm[2]&&it!=rm[6]&&it!=rm[3])
            {
                m[it]=7;
                rm[7]=it;
                break;
            }
        }
        //BCD 4 is the one that remained
        for(char x='a';x<='g';x++)
        {
            if(!m[x])
            {
                m[x]=4;
                rm[4]=x;
                break;
            }
        }
        for(int i=0;i<=9;i++)
        {
            string x="";
            for(int j=0;bcd[i][j];j++)
                x+=rm[bcd[i][j]];
            sort(x.begin(),x.end());
            fi[x]=i;
        }
        // second part of input
        p=d;
        c=p;
        p=strtok(c," ");
        int x = 0;
        while(p)
        {
            a = charToString(p);
            sort(a.begin(),a.end());
            x=x*10+fi[a];
            p=strtok(NULL," ");
        }
        sol+=x;
    }
    cout<<sol;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-sstart);
    cout<<"time:"<<duration.count();
    return 0;
}


