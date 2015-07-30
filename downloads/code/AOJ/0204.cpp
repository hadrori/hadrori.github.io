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
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;

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
       || d1 > c.r + EPS && d2 < c.r - EPS ) return 1;
    P h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}

L crosspointCL(const C &c, const L &l) {
    P hp = projection(l, c.p);
    P h =  hp - c.p;
    double d2 = norm(h);
    P v = sqrt(c.r*c.r - d2)*(l.b-l.a)/abs(l.b-l.a);
    return L(hp - v, hp + v);
}

L crosspointCS(const C &c, const L &l) {
    if(intersectCS(c, l) == 2) return crosspointCL(c, l);
    L ret = crosspointCL(c, l);
    // 交点1つの場合は両方同じ点を返す
    if(dot(l.a - ret.a, l.b - ret.a) < 0) ret.b = ret.a; 
    else ret.a = ret.b;
    return ret;
}

struct UFO{
    C c;
    int v;
    double dis;
    bool inv;
    UFO(C c, int v):c(c),v(v),inv(false){
        dis = abs(c.p);
    }
    bool operator < (const UFO &u) const{
        return dis < u.dis + EPS;
    }
};

int R;

void nextUFO(UFO &ufo){
    double k = 1-ufo.v/ufo.dis;
    ufo.c.p.real() *= k;
    ufo.c.p.imag() *= k;
    ufo.dis -= ufo.v;
    if(ufo.dis < R + EPS){
        ufo.inv = true;
    }
    return;
}

int main(){
    int n;
    while(cin >> R >> n, R||n){
        vector<UFO> ufo;
        rep(i,n){
            double x, y, r, v;
            cin >> x >> y >> r >> v;
            ufo.pb(UFO(C(P(x, y), r), v));
        }
        int ans = 0;
        rep(i,ufo.size()){
            nextUFO(ufo[i]);
            if(ufo[i].inv){
                ufo.erase(ufo.begin()+i);
                i--;
                ans++;
            }
        }
        sort(all(ufo));

        while(ufo.size()){
            P tar = ufo[0].c.p;
            ufo.erase(ufo.begin());
            L l = L(P(0,0),P(tar.real()*1100, tar.imag()*1100));

            rep(i,ufo.size()){
                if(intersectCS(ufo[i].c, l)){
                    L p = crosspointCS(ufo[i].c,l);
                    if(abs(p.a) > R || abs(p.b) > R){
                        ufo.erase(ufo.begin()+i);
                        i--;
                    }
                }
            }
            rep(i,ufo.size()){
                nextUFO(ufo[i]);
                if(ufo[i].inv){
                    ufo.erase(ufo.begin()+i);
                    i--;
                    ans++;
                }
            }
            sort(all(ufo));
        }
        cout << ans << endl;
    }
}
