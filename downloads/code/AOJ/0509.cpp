#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
int n, q, h, w;
int f[2][10010];
vector<pair<int,int>> ps[100010];
 
void solve()
{
    int area = 0, length = 0;
    rep(i,h+2) {
        memset(f[1], 0, sizeof(f[1]));
        for(auto &p: ps[i]) f[1][p.first] += p.second;
        rep(j,w+1) {
            f[1][j+1] += f[1][j];
            f[1][j] += f[0][j];
        }
        rep(j,w+1) {
            if(f[1][j]) area++;
            if((f[0][j] > 0) != (f[1][j] > 0)) length++;
            if((f[1][j] > 0) != (f[1][j+1] > 0)) length++;      
        }
        swap(f[0], f[1]);
    }
 
    cout << area << endl;
    if(q == 2) cout << length << endl;
}
 
bool input()
{
    cin >> n >> q;
    memset(f,0,sizeof(f));
    rep(i,100010) ps[i].clear();
    h = w = 0;
    rep(i,n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        ps[b].push_back(make_pair(a,1));
        ps[b].push_back(make_pair(c,-1));
        ps[d].push_back(make_pair(a,-1));
        ps[d].push_back(make_pair(c,1));
        h = max(h, d);
        w = max(w, c);
    }
    return n;
}
 
int main()
{
    while(input()) solve();
    return 0;
}
