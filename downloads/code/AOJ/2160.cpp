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

/* 点の進行方向 (a->b->c) */
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

/* 凸多角形の分割(左を残す) */
G convex_cut(const G& g, const L& l) {
    G Q;
    rep(i, g.size()) {
        P A = g[i], B = g[(i+1)%g.size()];
        if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
        if (ccw(l.a, l.b, A)*ccw(l.a, l.b, B) < 0) Q.push_back(crosspointLL(L(A, B), l));
    }
    return Q;
}

/* 垂直二等分線 */
L bisector(P a, P b) {
    P A = (a+b)*P(0.5,0);
    return L(A, A+(b-a)*P(0, PI/2));
}

/* k番目の点のボロノイ領域(g:外枠, v:点集合) O(n(n+m))*/
G voronoi_cell(G g, G v, int k) {
    rep(i, v.size()) if (i!=k) g = convex_cut(g, bisector(v[k], v[i]));
    return g;
}

/* 多角形の面積 */
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
double areaG(const G& g) {
    double A = 0;
    for (int i = 0; i < g.size(); ++i) 
        A += cross(curr(g, i), next(g, i));
    return A/2.0;
}
int main(){
    int n, m;
    while(cin>>n>>m,n||m){
        G v(n);
        G g(m);
        rep(i,n){
            int x, y;
            cin >> x >> y;
            v[i] = P(x, y);
        }
        rep(i,m){
            int x, y;
            cin >> x >> y;
            g[i] = P(x,y);
        }
        rep(i,m){
            printf("%.5f\n", areaG(voronoi_cell(v, g,i)));
        }
    }
}
