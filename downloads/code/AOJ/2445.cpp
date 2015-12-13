#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
typedef int64_t i64;
 
i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
const int mod = 1e9+9;
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};
int fact[1<<21];
inline int mul(int x, int y) { return 1LL*x*y%mod; }
inline int add(int &x, int y) { return x = (x+y)%mod; }
inline int sub(int &x, int y) { return x = (x-y+mod)%mod; }
inline int inv(int a) { i64 x, y; extgcd(a,mod,x,y); return (x%mod+mod)%mod; }
inline int binom(int n, int k) { return mul(fact[n],inv(mul(fact[k], fact[n-k]))); }
inline bool in(int lx, int ly, int rx, int ry, int x, int y) { return lx <= x and x <= rx and ly <= y and y <= ry; }
 
int n, m;
vector<pair<int,int>> vs;
 
int calc(pair<int,int> l, pair<int,int> r) {
    const int lx = l.first, ly = l.second, rx = r.first, ry = r.second;
    vector<pair<int,int>> tvs;
    for(auto &e: vs) if(in(lx,ly,rx,ry,e.first,e.second)) tvs.push_back(e);
    tvs.push_back(r);
    sort(begin(tvs),end(tvs));
    int dp[64]; memset(dp, 0, sizeof(dp));
    rep(i,tvs.size()) {
        const int x = tvs[i].first, y = tvs[i].second;
        dp[i] = binom(x-lx+y-ly, x-lx);
        rep(j,i) {
            const int tx = tvs[j].first, ty = tvs[j].second;
            if(in(lx,ly,x,y,tx,ty)) sub(dp[i], mul(dp[j], binom(x-tx+y-ty,x-tx)));
        }
    }
    return dp[(int)tvs.size()-1];
}
 
int dp1[64][64], dp2[64][64];
vector<pair<int,int>> cs1, cs2;
 
int bfs(int l, int r, int s, int t, int b, vector<pair<int,int>> &cand, int dp[64][64]) {
    queue<pair<int,int>> q;
    int d, x, y, dist[64][64], md = 114514;
    l -= b; r -= b; s -= b;
    q.emplace(s,s);
    memset(dist, -1, sizeof(dist)); memset(dp, 0, sizeof(dist));
    dist[s][s] = 0; dp[s][s] = 1;
 
    while(!q.empty()) {
        x = q.front().first; y = q.front().second; q.pop();
        d = dist[x][y];
        if(abs(s-x) + abs(s-y) == t) {
            if(md > d-abs(s-x)-abs(s-y)) {
                cand.clear();
                md = d-abs(s-x)-abs(s-y);
            }
            if(md == d-abs(s-x)-abs(s-y)) cand.emplace_back(x+b,y+b);
        }
        rep(k,4) {
            bool ok = 1;
            const int nx = x+di[k], ny = y+dj[k];
            for(auto &e: vs) if(e.first-b == nx and e.second-b == ny) ok = 0;
            if(!in(l,l,r,r,nx,ny) or !ok) continue;
            if(dist[nx][ny] < 0) dist[nx][ny] = d+1, q.emplace(nx,ny);
            if(dist[nx][ny] == d+1) add(dp[nx][ny], dp[x][y]);
        }
    }
    return dp[r][r];
}
 
int solve() {
    if(n <= 200) return bfs(0,n-1,0,-1,0,cs1,dp1);
    const int M = 50;
    bfs(0,M-1,0,M-1,0,cs1,dp1);
    bfs(n-M,n-1,n-1,M-1,n-M,cs2,dp2);
    int ans = 0;
    for(auto &e: cs1)
        for(auto &f: cs2)
            add(ans,
                mul(dp1[e.first][e.second],
                    mul(dp2[f.first-n+M][f.second-n+M],
                        calc(e,f))));
    return ans;
}
 
void input() {
    cin >> n >> m;
    int x, y;
    rep(i,m) {
        cin >> x >> y;
        vs.push_back(make_pair(x-1,y-1));
    }
}
 
int main() {
    fact[0] = 1;
    repi(i,1,1<<21) fact[i] = mul(fact[i-1], i);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
