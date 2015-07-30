#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define EPS 1e-10
#define PI acos(-1.0)
typedef complex<double> P;
typedef vector<P> G;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b);}
inline double dot(const P& a, const P& b) { return real(conj(a)*b);}

struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

P crosspointLL(const L &l, const L &m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS) return m.a; // 重なっている
    if (abs(A) < EPS) return P(INF, INF); // 交差しない
    return m.a + B / A * (m.b - m.a);
}

G convex_cut(const G& g, const L& l) {
    G Q;
    rep(i, g.size()) {
        P A = g[i], B = g[(i+1)%g.size()];
        if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
        if (ccw(l.a, l.b, A)*ccw(l.a, l.b, B) < 0) Q.push_back(crosspointLL(L(A, B), l));
    }
    return Q;
}

#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
double areaG(const G& g) {
    double A = 0;
    for (int i = 0; i < g.size(); ++i) 
        A += cross(curr(g, i), next(g, i));
    return A/2.0;
}

int main(){
    int n;
    while(cin >> n, n){
        G g;
        rep(i,n){
            double x, y;
            cin >> x >> y;
            g.pb(P(x,y));
        }
        double S = areaG(g) / 2;
        double lb = 0, ub = PI;
        double th, tS;

        if(tS = areaG(convex_cut(g, L(P(0,0), P(1,0)))) + EPS > S){
            ub = 0; lb = PI;
        }

        while(abs(tS-S) >= EPS){
            th = (lb + ub) / 2;
            tS = areaG(convex_cut(g, L(P(0,0), P(cos(th),sin(th)))));
            if(abs(tS-S) < EPS) break;
            else if(tS - S > 0) ub = th;
            else lb = th;
        }
        printf("%.15f %.15f\n", cos(th), sin(th));
    }
    return 0;
}
