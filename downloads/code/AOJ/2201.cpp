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

/* 円 */
struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};

/* 円の接線 */
L tangent(C c, double t){
    P p = c.p + polar(c.r, t);
    P d = polar(c.r, t) * P(0, 1);
    return L(p - d, p + d);
}

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

/* 正射影(Lがスクリーン) */
P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}

double distanceLP(const L &l, const P &p) {
    return abs(p - projection(l, p));
}

/* 円の共通接線 */
vector<L> common_tangents(C c1, C c2) {
    vector<L>  ret;
    double t = arg(c2.p - c1.p);
    double d = acos((c1.r - c2.r) / abs(c2.p - c1.p));
    double dst = abs(c2.p - c1.p);
  
    if(abs(c2.r - c1.r) < dst) {
        //外接線
        ret.push_back(tangent(c1, t - d));
        ret.push_back(tangent(c1, t + d));
    }
    d = acos((c1.r + c2.r) / abs(c2.p - c1.p));
    if(abs(c2.r + c1.r) < dst){
        //内接線
        ret.push_back(tangent(c1, t - d));
        ret.push_back(tangent(c1, t + d));
    }
    return ret;
}

struct S{
    C c;
    int m;
    S(C c, int m):c(c),m(m){}
};


int n;

int solve(){
    vector<S> juel;
    rep(i,n){
        int x, y, r, m;
        cin >> x >> y >> r >> m;
        juel.pb(S(C(P(x, y), r), m));
    }
    int ans = 1;
    rep(i,n)repi(j,i+1,n){
        S j1 = juel[i], j2 = juel[j];
        C c1 = j1.c;
        C c2 = j2.c;
        S j3 = juel[i], j4 = juel[j];
        C c3 = C(j3.c.p, j3.c.r+j3.m);
        C c4 = C(j4.c.p, j4.c.r+j4.m);
        vector<L> l1 = common_tangents(c1, c2);
        vector<L> l2 = common_tangents(c3, c4);

        rep(a,l1.size()){
            int cnt = 0;
            rep(b,n){
                double dis = distanceLP(l1[a],juel[b].c.p);
                if(dis+EPS>juel[b].c.r && dis<juel[b].c.r+juel[b].m+EPS){
//                    cerr << "LINE: " << l[a].a << l[a].b << endl;
//                    cerr << juel[b].c.p << endl;
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        rep(a,l2.size()){
            int cnt = 0;
            rep(b,n){
                double dis = distanceLP(l2[a],juel[b].c.p);
                if(dis+EPS>juel[b].c.r && dis<juel[b].c.r+juel[b].m+EPS){
//                    cerr << "LINE: " << l[a].a << l[a].b << endl;
//                    cerr << juel[b].c.p << endl;
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}


int main(){
    while(cin >> n, n){
        cout << solve() << endl;
    }
}
