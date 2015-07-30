#include <bits/stdc++.h>
using namespace std;

struct point
{
        int x, y, dir, dist;
        bool operator<(const point &p) const { return x!=p.x? x < p.x: y < p.y;}
        bool operator==(const point &p) const { return x == p.x and y == p.y;}
};

const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n, t, sx, sy, f[64][64][4];
int d[128], p[128], done[64][64][4][16];
vector<point> cand, ans;

void simulate(int dist, int edir)
{
        queue<point> q;
        for(auto &e: cand) if(!e.dist) q.push(e);
        for(auto &e: cand) if(e.dist) q.push(e);
        cand.clear();
        memset(done,0,sizeof(done));
        while(!q.empty()) {
                point v = q.front(); q.pop();
                if(done[v.x][v.y][v.dir][v.dist]) continue;
                done[v.x][v.y][v.dir][v.dist] = 1;
                if(v.dist == dist and v.dir == edir) cand.push_back((point){v.x,v.y,edir,0});
                for (int i = 0; i < 4; i++) {
                        if((v.dir+2)%4 == i or !f[v.x][v.y][i]) continue;
                        int nx = v.x+dx[i], ny = v.y+dy[i];
                        if(v.dist == dist) {
                                if(i == edir) cand.push_back((point){nx,ny,edir,1});
                                else continue;
                        }
                        q.push((point){nx,ny,i,v.dist+1});
                }
        }
}

void solve()
{
        cand.push_back((point){sx,sy,0,0});
        cand.push_back((point){sx,sy,2,0});
        for (int i = 0; i < t; i++) simulate(d[i], p[i]);
        for(auto &e: cand) {
                if(e.dist) ans.push_back((point){e.x-dx[e.dir],e.y-dy[e.dir],e.dir,0});
                else ans.push_back(e);
        }
        sort(begin(ans),end(ans));
        ans.erase(unique(begin(ans),end(ans)),end(ans));
        for(auto &e: ans) cout << e.x << " " << e.y << endl;
}

void input()
{
        cin >> n >> sx >> sy >> t;
        int x1, y1, x2, y2;
        for (int i = 0; i < n; i++) {
                cin >> x1 >> y1 >> x2 >> y2;
                if(x1 == x2) for (int y = min(y1,y2); y < max(y1,y2); y++) f[x1][y][0] = f[x1][y+1][2] = 1;
                else for (int x = min(x1,x2); x < max(x1,x2); x++) f[x][y1][1] = f[x+1][y1][3] = 1;
        }
        const string dir = "NESW";
        char c;
        for (int i = 0; i < t; i++) {
                cin >> d[i] >> c;
                p[i] = dir.find(c);
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
