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

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

bool intersectSS(const L &s, const L &t) {
    return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b) <= 0 &&
	ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b) <= 0;
}

P crosspointLL(const L &l, const L &m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS) return m.a; // 重なっている
    if (abs(A) < EPS) return P(INF, INF); // 交差しない
    return m.a + B / A * (m.b - m.a);
}

/* 多角形の面積 */
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
double areaG(const G& g) {
    double A = 0;
    for (int i = 0; i < g.size(); ++i)
	A += cross(curr(g, i), next(g, i));
    return abs(A)/2.0;
}

G tri;
vector<L> l;
void solve(){
    rep(i,3)if(!intersectSS(l[i], l[(i+1)%3])){
	cout << "kyo\n";
	return;
    }
    rep(i,3)repi(j,i+1,3){
	tri.pb(crosspointLL(l[i], l[j]));
//	cerr << tri[i] << endl;
    }

    double area = areaG(tri);
    if(area >= 1900000)
	cout << "dai-kichi\n";
    else if(area >= 1000000)
	cout << "chu-kichi\n";
    else if(area >= 100000)
	cout << "kichi\n";
    else if(area > 0)
	cout << "syo-kichi\n";
    else cout << "kyo\n";

    return;
}

int main(){
    int x1, y1, x2, y2;
    while(cin>>x1>>y1>>x2>>y2,x1||y1||x2||y2){
	tri.clear(); l.clear();
	l.pb(L(P(x1,y1),P(x2,y2)));
	rep(i,2){
	    cin>>x1>>y1>>x2>>y2;
	    l.pb(L(P(x1,y1),P(x2,y2)));
	}
	solve();
    }
    return 0;
}
