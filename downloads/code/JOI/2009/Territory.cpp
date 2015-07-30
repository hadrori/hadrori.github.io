#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const string dir = "NESW";
const int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};

map<pii,int> ps;

void add_edge(int &x, int &y, char c)
{
        int d = dir.find(c);
        ps[pii(x,y)] |= 1<<d;
        x += dx[d]; y += dy[d];
        ps[pii(x,y)] |= 1<<((d+2)%4);
}

int solve()
{
        char c;
        int x = 0, y = 0;
        while(cin>>c, c!='Q') add_edge(x,y,c);
        x = begin(ps)->first.first; y = begin(ps)->first.second;
        int tx = x, ty = y, ans = 0, d = 1;
        do {
                if((ps[pii(x,y)]>>d)&1) {
                        if(d%2) ans += y*(d-2);
                        x += dx[d];
                        y += dy[d];
                        d = (d+3)%4;
                }
                else d = (d+1)%4;
        } while(x != tx or y != ty or d != 1);
        return ans;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        cout << solve() << endl;
        return 0;
}
