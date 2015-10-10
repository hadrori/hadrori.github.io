#include <bits/stdc++.h>
using namespace std;
 
#define repi(i,l,r) for(int i=(int)(l); i<(int)(r); i++)
#define rep(i,n) repi(i,0,n)
 
struct node {
    int i, j, d, e;
    node(int i, int j, int d, int e) : i(i), j(j), d(d), e(e) {}
    bool operator<(const node &v) const { return e > v.e; }
};
 
const int di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};
 
int h, w, f[32][32][4], cst[32][32][4], dist[32][32];
 
int bfs(int i, int j) {
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,i,j));
    int d;
    while(!q.empty()) {
        tie(d,i,j) = q.front();
        q.pop();
        if(~dist[i][j]) continue;
        dist[i][j] = d;
        if(i == h-1 and j == w-1) return d;
        rep(k,4) if(f[i][j][k]) q.push(make_tuple(d+1,i+di[k],j+dj[k]));
    }
    if(~dist[0][0]) return -1;
    return 1145141919;
}
 
bool can(int x) {
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    int i, j, d;
    memset(dist,-1,sizeof(dist));
    while(!q.empty()) {
        tie(d,i,j) = q.front(); q.pop();
        if(~dist[i][j]) continue;
        dist[i][j] = 1;
        if(i == h-1 and j == w-1) return 1;
        rep(k,4) if(f[i][j][k] and d+cst[i][j][k] <= x) q.push(make_tuple(d+1,i+di[k],j+dj[k]));
    }
    return 0;
}
 
int solve() {
    memset(cst,-1,sizeof(cst));
    rep(i,h) rep(j,w) rep(d,4) if(f[i][j][d]) {
        f[i][j][d] = 0;
        cst[i][j][d] = bfs(i,j);
        if(cst[i][j][d] < 0) return -1;
        f[i][j][d] = 1;
    }
 
    int lb = -1, ub = 1145141919, mid;
    while(ub-lb > 1) {
        mid = (lb+ub)>>1;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}
 
bool input() {
    cin >> h >> w;
    if(!h and !w) return 0;
    memset(f,0,sizeof(f));
    rep(i,h) {
        int v;
        rep(j,w-1) {
            cin >> v;
            f[i][j][1] = f[i][j+1][3] = 1-v;
        }
        if(i < h-1) rep(j,w) {
            cin >> v;
            f[i][j][0] = f[i+1][j][2] = 1-v;
        }
    }
    return 1;
}
 
int main() {
    cin.tie(0);
    while(input()) cout << solve() << endl;
    return 0;
}