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

bool intersectCC(const C &c, const C &d){
    return (norm(c.p - d.p) - (c.r + d.r)*(c.r + d.r) < EPS) &&
        (norm(c.p - d.p) - (c.r - d.r)*(c.r - d.r) > -EPS);
}

L crosspointCC(const C &c1, const C &c2){ // 重なっているとnan
    double d = abs(c1.p - c2.p);
    double x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2.0*d);
    P v = sqrt(c1.r*c1.r - x*x)*(c1.p-c2.p)/abs(c1.p-c2.p)*P(0, 1);
    P h = c1.p + x * (c2.p - c1.p)/abs(c2.p - c1.p);
    return L(h - v, h + v);
}

int main(){
    int n;
    while(cin >> n, n){
        vector<P> points(n);
        int ans = 1;
        rep(i,n){
            double x, y;
            scanf("%lf,%lf", &x, &y);
            points[i] = P(x,y);
        }
        rep(i,n)repi(j,i+1,n){
            P a = points[i], b = points[j];
            C c = C(a,1), d = C(b,1);
            if(intersectCC(c, d)){
                L tmp = crosspointCC(c, d);
                P p[2];
                p[0] = tmp.a, p[1] = tmp.b;
                rep(k,2){
                    int cnt = 0;
                    rep(l,n){
                        if(abs(p[k]-points[l]) <= 1 + EPS) cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << endl;
    }
}
