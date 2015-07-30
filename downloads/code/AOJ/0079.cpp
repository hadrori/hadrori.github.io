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

/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

/* 多角形の面積 */
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
double areaG(const G& g) {
    double A = 0;
    for (int i = 0; i < g.size(); ++i) 
        A += cross(curr(g, i), next(g, i));
    return abs(A/2.0);
}

int main(){
    G g;
    double x, y;
    while(~scanf("%lf,%lf", &x, &y)){
        g.pb(P(x,y));
    }
    printf("%.8f\n",areaG(g));
}
