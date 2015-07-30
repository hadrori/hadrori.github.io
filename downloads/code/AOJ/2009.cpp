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

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
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

bool intersectSS(const L &s, const L &t) {
    return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b) < -EPS &&
	ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b) < -EPS;
}

P crosspointLL(const L &l, const L &m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS) return m.a; // 重なっている
    if (abs(A) < EPS) return P(INF, INF); // 交差しない
    return m.a + B / A * (m.b - m.a);
}

int main(){
    int n;
    while(cin >> n, n){
	vector<L> e;
	int ans = 1;
	while(n--){
	    int x[2], y[2];
	    rep(i,2) cin >> x[i] >> y[i];
	    P s = P(x[0],y[0]), t = P(x[1],y[1]);
	    L l = L(s, t);
	    G cps;
	    rep(i,e.size()){

		if(intersectSS(l,e[i])){
		    P cp = crosspointLL(l, e[i]);
		    bool ok = true;
		    rep(j,cps.size()){
			if(abs(cps[j]-cp) < EPS) ok = false;
		    }
		    if(ok){
			cps.pb(cp);
			ans++;
		    }
		}
	    }
	    e.pb(l);
	    ans++;
	}
	cout << ans << endl;
    }
}
