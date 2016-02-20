#include <bits/stdc++.h>
 
namespace D2 {
const double eps = 1e-8;
struct point {
    double x, y;
    point():x(0),y(0) {}
    point(double x, double y):x(x),y(y) {}
 
    point operator+=(const point &p) { x+=p.x; y+=p.y; return *this; }
    point operator-=(const point &p) { x-=p.x; y-=p.y; return *this; }
    point operator+(const point &p) const { return point(*this)+=p; }
    point operator-(const point &p) const { return point(*this)-=p; }
 
    double norm() const { return x*x+y*y; }
    double abs() const { return sqrt(norm()); }
    double dot(const point &p) const { return x*p.x+y*p.y; }
    double cross(const point &p) const { return x*p.y-y*p.x; }
    point proj(const point &p) const { double k = dot(p)/norm(); return point(x*k,y*k); }
};
int ccw(point a, point b, point c) {
    b -= a, c -= a;
    if (b.cross(c) > eps)        return +1;
    if (b.cross(c) < -eps)       return -1;
    if (b.dot(c) < -eps)         return -2; // c -- a -- b
    if (b.norm() < c.norm()-eps) return +2; // a -- b -- c
    return 0;
}
struct line {
    point a, b;
    line(point a, point b) : a(a), b(b) {}
 
    point vec() const { return b-a; }
    double abs() const { return vec().abs(); }
    point proj(const point &p) const { return a+vec().proj(p-a); }
};
double dps(const point &p, const line &s) { return ccw(s.a,s.b,s.proj(p)) ? std::min((s.a-p).abs(), (s.b-p).abs()) : (s.proj(p)-p).abs(); }
}
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
 
typedef vector<vector<int>> graph;
class maximal_indsets {
    const int n;
    const graph &G;
    vector<vector<int>> ret;
    vector<int> cur, exists, deg, block;
    void erase(int v) {
        if (exists[v]) {
            exists[v] = 0;
            for (int nv : G[v]) --deg[nv];
        }
    }
    void restore(int v) {
        exists[v] = 1;
        for (int nv : G[v]) ++deg[nv];
    }
    void select(int v) {
        cur.push_back(v);
        ++block[v], erase(v);
        for (int nv : G[v]) ++block[nv], erase(nv);
    }
    void unselect(int v) {
        cur.pop_back();
        --block[v], restore(v);
        for (int nv : G[v]) {
            if (--block[nv] == 0) restore(nv);
        }
    }
    void dfs() {
        int mn = n, v = -1;
        rep(u, n) if (exists[u]) {
            if (deg[u] < mn) mn = deg[u], v = u;
        }
        if (v == -1) {
            ret.push_back(cur);
        } else {
            select(v), dfs(), unselect(v);
            for (int nv : G[v]) {
                if (exists[nv]) select(nv), dfs(), unselect(nv);
            }
        }
    }
public:
    maximal_indsets(const graph& G) : n(G.size()), G(G), exists(n, 1), deg(n), block(n) {
        rep(v, n) deg[v] = G[v].size();
        dfs();
    }
    const vector<vector<int>>& get() const { return ret; }
};
 
int n, col[64];
graph G;
vector<vector<D2::point>> H;
 
bool touch(vector<D2::point> &s, vector<D2::point> &t) {
    int a = s.size(), b = t.size();
    rep(i,a) rep(j,b) {
        const D2::line p(s[i],s[(i+1)%a]), q(t[j],t[(j+1)%b]);
        int cnt = (D2::dps(p.a,q) < D2::eps) + (D2::dps(p.b,q) < D2::eps) +
                  (D2::dps(q.a,p) < D2::eps) + (D2::dps(q.b,p) < D2::eps);
        if(cnt > 2) return 1;
        if(cnt == 2) {
            if((p.a-q.a).abs() < D2::eps or (p.b-q.a).abs() < D2::eps or
               (p.a-q.b).abs() < D2::eps or (p.b-q.b).abs() < D2::eps) continue;
            return 1;
        }
    }
    return 0;
}
 
int dfs(int v) {
    int ex = 0;
    for(int &w: G[v]) if(col[w] >= 0) {
            ex |= 1<<col[w];
        }
    if((ex&3) == 3) {
        col[v] = 3;
        return 3;
    }
    if(ex&1) col[v] = 1;
    else col[v] = 0;
    ex |= 1<<col[v];
    int ret = __builtin_popcount(ex&3);
    for(int &w: G[v]) if(col[w] < 0) {
            int tmp = dfs(w);
            if(tmp == 3) return 3;
            ret = max(ret, tmp);
        }
    return ret;
}
 
int solve() {
    rep(i,n) repi(j,i+1,n) if(touch(H[i], H[j])) {
        G[i].push_back(j);
        G[j].push_back(i);
    }
 
    int ans = 4;
    auto ids = maximal_indsets(G).get();
    for(auto &xs: ids) {
        memset(col, -1, sizeof(col));
        for(int &v: xs) col[v] = 2;
        int need = 0;
        rep(i,n) if(col[i] < 0) need = max(need, dfs(i));
        ans = min(ans, need+1);
    }
    return ans;
}
 
bool input() {
    cin >> n;
    G.assign(n,vector<int>());
    H.assign(n,vector<D2::point>());
    int m; double x, y;
    rep(i,n) {
        cin >> m;
        rep(j,m) {
            cin >> x >> y;
            H[i].push_back(D2::point(x,y));
        }
    }
    return n;
}
 
int main(){
    while(input()) { cout << solve() << endl; }
    return 0;
}
