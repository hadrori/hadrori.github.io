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
#define EPS 1e-6
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

/* 回転 */
P rotate(const P& a, double th){
    return a*polar(1.0, th);
}

/* 多角形の面積 */
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
double area2(const G& g) {
    double A = 0;
    for (int i = 0; i < g.size(); ++i) 
        A += cross(curr(g, i), next(g, i));
    return A;
}

/* 多角形の重心の座標 */
P centerG(const G& g){
    P p = (0,0);
    double ar = 0;
    int u = g.size()-1;
    for(int i = 0; i < g.size(); u=i++){
        double k = g[u].real()*g[i].imag()-g[i].real()*g[u].imag();
        ar += k;
        p.real() += (g[u].real()+g[i].real())*k;
        p.imag() += (g[u].imag()+g[i].imag())*k;
    }
    p /= (3*ar);
    return p;
}

/* 点対称な点 */
P reflectionP(const P &p1, const P &p2) {
    return 2.0 * p1 - p2;
}

int main(){
    int n;
    cin >> n;
    G g;
    rep(i,n){
        P p;
        cin >> p.real() >> p.imag();
        g.pb(p);
    }
    P cg = centerG(g);
    bool ok = true;
    rep(i,n){
        P rp = reflectionP(cg,g[i]);
        bool flag = false;
        rep(j,n){
            if(abs(g[j].real()-rp.real())<EPS && abs(g[j].imag()-rp.imag())<EPS){
                flag = true;
                break;
            }
        }
        if(!flag){
            ok = false;
            break;
        }
    }
    if(ok) printf("%.5f %.5f\n",cg.real(),cg.imag());
    else cout << "NA\n";
}
