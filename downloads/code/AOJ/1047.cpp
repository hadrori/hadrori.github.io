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

/* 円 */
struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};

/* 線分 */
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
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
        C circle[110];
        rep(i,n){
            double a, b, c;
            cin >> a >> b >> c;
            circle.pb(C(P(a,b), c));
        }
        double ans = 0;
        rep(i,n){
            vector<pair<double,double> > sect;
            sect.pb(mp(0,2*PI));
            repi(j,i+1,n){
                if(abs(circle[i].p-circle[j].p) < circle[j].r && !intersectCC(circle[i],circle[j])){
                    sect.clear();
                    break;
                }
                if(intersectCC(ciecle[i],circle[j])){
                    L l = crosspointCC(ciecle[i],circle[j]);
                    double x[2], y[2];
                    x[0] = l.a.real()-circle[i].p.real(); y[0] = l.a.imag()-circle[i].p.imag();
                    x[1] = l.b.real()-circle[i].p.real(); y[1] = l.b.imag()-circle[i].p.imag();
                    double rad[2];
                    rep(k,2){
                        if(x[k]==0) rad[k] = y[k]>0? PI/2: 3*PI/2;
                        else{
                            rad[k] = atan(y[k]/x[k]);
                        }
                    }
                    if(rad[1] == rad[0]) continue;
                    if(abs(circle[i].p-circle[j].p) < circle[j].r)
                }
            }
            rep(j,sect.size()){
                ans += circle[i].r*circle[i].r*(sect[j].second-sect[j].first);
            }
        }
    }
}
