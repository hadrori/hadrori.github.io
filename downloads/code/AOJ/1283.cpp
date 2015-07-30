#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const double inf = 1e6;
const double eps = 1e-8;
const double pi = acos(-1.0);
typedef complex<double> point;
struct line{
    point a, b;
    line(point a, point b):a(a),b(b){}
};
inline double dot(const point &a, const point &b){ return real(conj(a)*b);}
inline double cross(const point &a, const point &b){ return imag(conj(a)*b);}
int ccw(point a, point b, point c) {
    b -= a; c -= a;
    if (cross(b, c) > eps)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < -eps)   return -1;       // -1 : 時計回り
    if (dot(b, c) < -eps)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)-eps) return -2;       // -2 : 線上(a--b--c)
    return 0;
}
point crosspointLL(const line &l, const line &m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < eps && abs(B) < eps) return m.a; // 重なっている
    if (abs(A) < eps) return point(inf, inf); // 交差しない
    return m.a + B / A * (m.b - m.a);
}
vector<point> convex_cut(const vector<point> &g, const line &l) {
    vector<point> Q;
    rep(i, g.size()) {
        point A = g[i], B = g[(i+1)%g.size()];
        if (ccw(l.a, l.b, A) != -1) Q.pb(A);
        if (ccw(l.a, l.b, A)*ccw(l.a, l.b, B) < 0) Q.pb(crosspointLL(line(A, B), l));
    }
    return Q;
}

int N;
vector<point> G;

line gen_line(int i, double d){
    int j = (i+1)%N;
    point v = G[j]-G[i];
    v = v*polar(d/abs(v),pi/2);
    return line(G[i]+v,G[j]+v);
}
bool can(double d){
    vector<point> H;
    H.pb(point(inf,inf)); H.pb(point(-inf,inf));
    H.pb(point(-inf,-inf)); H.pb(point(inf,-inf));
    rep(i,N) H = convex_cut(H,gen_line(i,d));
    return H.size() > 0;
}

double solve(){
    double lb = 0., ub = inf;
    rep(_,100){
        double mid = (lb+ub)/2.;
        if(can(mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}

bool input(){
    cin >> N;
    G.clear();
    rep(i,N){
        int x, y; cin >> x >> y;
        G.pb(point(x,y));
    }
    return N;
}
int main(){
    while(input()) printf("%.8f\n", solve());
    return 0;
}


