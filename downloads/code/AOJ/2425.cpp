#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1e9;
const int dx[] = {0,1,1,0,-1,-1,0};
const int dy[][7] = {{1,0,-1,-1,-1,0,0},
                     {1,1,0,-1,0,1,0}};
const int base = 128;
struct node{
    int x, y, t, d;
    bool operator<(const node &n)const{ return d > n.d;}
};
int sx, sy, gx, gy, lx, ly, n;
int fur[256][256], dist[256][256][8];
inline bool in(int x, int y){ return abs(x) <= lx and abs(y) <= ly;}

int solve(){
    memset(dist, -1, sizeof(dist));
    priority_queue<node> que;
    que.push((node){sx,sy,0,0});
    while(!que.empty()){
        node n = que.top(); que.pop();
        if(dist[base+n.x][base+n.y][n.t%6] >= 0) continue;
        dist[base+n.x][base+n.y][n.t%6] = n.d;
        if(n.x == gx and n.y == gy) return n.d;
        int op = abs(n.x*n.y*n.t)%6;
        rep(d,7) {
            int nx = n.x+dx[d], ny = n.y+dy[abs(n.x)%2][d];
            if(in(nx,ny) and !fur[base+nx][base+ny])
                que.push((node){nx,ny,n.t+1,n.d+(d!=op)});
        }
    }
    return -1;
}

void input(){
    cin >> sx >> sy >> gx >> gy;
    cin >> n;
    rep(i,n){
        int x, y; cin >> x >> y;
        fur[base+x][base+y] = 1;
    }
    cin >> lx >> ly;
}
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


