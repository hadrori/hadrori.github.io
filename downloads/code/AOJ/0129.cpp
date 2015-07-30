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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
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

/* 正射影(Lがスクリーン) */
P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}

int intersectCS(const C &c, const L &l){ // 交点数を返す
    if(norm(projection(l, c.p) - c.p) - c.r*c.r > EPS) return 0;
    double d1 = abs(c.p - l.a);
    double d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS
       || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    P h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}

int main(){
    int n;
    while(cin >> n, n){
        vector<C> g;
        rep(i,n){
            double x, y, r;
            cin >> x >> y >> r;
            g.pb(C(P(x,y),r));
        }
        int m;
        cin >> m;
        rep(i,m){
            double tx, ty, sx, sy;
            cin >> tx >> ty >> sx >> sy;
            L l = L(P(tx,ty),P(sx,sy));
            bool danger = true;
            rep(i,n){
                if(intersectCS(g[i], l)){
                    danger = false;
                    break;
                }
            }
            cout << (danger? "Danger": "Safe") << endl;
        }
    }
}
