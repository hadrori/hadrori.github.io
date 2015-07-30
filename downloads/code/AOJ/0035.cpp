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

/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

bool isConv(G g){
    int prev = 0;
    int n = g.size();
    rep(i,n){
	int t = ccw(g[i],g[(i+1)%n],g[(i+2)%n]);
	if(prev && prev != t) return false;
	prev = t;
    }
    return true;
}

int main(){
    double x[4], y[4];
    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
		 x, y, x+1, y+1, x+2, y+2, x+3, y+3)){
	G g;
	rep(i,4)g.pb(P(x[i],y[i]));
	cout << (isConv(g)? "YES": "NO") << endl;
    }
    return 0;
}
