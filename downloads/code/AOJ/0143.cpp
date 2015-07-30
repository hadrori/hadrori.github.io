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

/* 線分 */
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};

/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

bool intersectSP(const L &s, const P &p) {
    return abs(s.a-p)+abs(s.b-p)-abs(s.b-s.a) < EPS; // 三角不等式
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

int intersectGS(const G &g, const L &l){
    // 2: 包含 1: 交差 0: それ以外
    if(intersectGP(g, l.a) == 2 && intersectGP(g, l.b) == 0
       || intersectGP(g, l.b) == 2 && intersectGP(g, l.a) == 0) return 1;
    if(intersectGP(g, l.a) == 2) return 2;
    return 0;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        G g;
        rep(i,3){
            double x, y;
            cin >> x >> y;
            g.pb(P(x,y));
        }
        double xk, yk, xs, ys;
        cin >> xk >> yk >> xs >> ys;
        L l = L(P(xk,yk), P(xs,ys));
        cout << (intersectGS(g, l) == 1? "OK": "NG") << endl;
    }
}
