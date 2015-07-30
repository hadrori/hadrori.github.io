#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}
/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}
/* 線分 */
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};
/* 円 */
struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};
/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}
/* 正射影(Lがスクリーン) */
P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}
bool intersectSP(const L &s, const P &p) {
    return abs(s.a-p)+abs(s.b-p)-abs(s.b-s.a) < EPS; // 三角不等式
}
double distanceLP(const L &l, const P &p) {
    return abs(p - projection(l, p));
}
double distanceSP(const L &s, const P &p) {
    const P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
int intersectCS(const C &c, const L &l){ // 交点数を返す
    if(norm(projection(l, c.p) - c.p) - c.r*c.r > EPS) return 0;
    double d1 = abs(c.p - l.a);
    double d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS
       || d1 > c.r + EPS && d2 < c.r - EPS ) return 1;
    P h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}
int intersectGP(const G &g, const P &p){
    // 2: 包含 1: 線上 0:それ以外
    int ccw0 = ccw(g[0], g[1], p);
    rep(i, g.size()){
	if(intersectSP(L(g[i], g[(i+1)%g.size()]), p)) return 1;
	if(ccw(g[i], g[(i+1)%g.size()], p) != ccw0) return 0;
    }
    return 2;
}

G tri;
C c;

void solve(){
    bool in = true;
    rep(i,3)if(abs(tri[i]-c.p) > c.r){
	in = false;
	break;
    }
    if(in){
	cout << "b\n";
	return;
    }
    in = true;
    int ccwt = ccw(tri[2],tri[0],c.p);
    rep(i,2) if(ccwt != ccw(tri[i], tri[i+1], c.p)){
	in = false;
	break;
    }
    double dist = INF;
    rep(i,3) dist = min(dist, distanceSP(L(tri[i], tri[(i+1)%3]), c.p));
//				  distanceLP(L(tri[(i+1)%3], tri[i]), c.p)));
    if(in && dist >= c.r){
	cout << "a\n";
	return;
    }
    if(!in && dist > c.r){
	cout << "d\n";
	return;
    }
    cout << "c\n";
    return;
}

int main(){
    int x, y, r;
    while(cin >> x >> y, x || y){
	tri.clear();
	tri.pb(P(x,y));
	rep(i,2){
	    cin >> x >> y;
	    tri.pb(P(x,y));
	}
	cin >> x >> y >> r;
	c = C(P(x,y),r);
	solve();
    }
    
    return 0;
}
