#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
#define INF 1e9
#define EPS 1e-8
#define PI acos(-1.0)
using namespace std;
typedef complex<double> P;
typedef vector<P> G;

namespace std {
    bool operator < (const P& a, const P& b){
        return abs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
    }
}

inline double angle( P &a,  P &b){ return arg(conj(a)*b); }
inline P rotate( P& a, double th){ return a*polar(1.0, th); }

int main(){
    int n;
    while(cin >> n, n){
        G g1(n), g2(n);
        rep(i,n) cin >> g1[i].real() >> g1[i].imag();
        rep(i,n) cin >> g2[i].real() >> g2[i].imag();
        P c1 = P(0,0), c2 = P(0,0);
        rep(i,n){
            c1 += g1[i];
            c2 += g2[i];
        }
        c1 /= n;
        c2 /= n;
        rep(i,n){
            g1[i] -= c1;
            g2[i] -= c2;
        }
        sort(all(g1));
        double ans = INF;
        rep(i,n){
            G tg = g2;
            double th = angle(tg[i],g1[0]);
            rep(j,n) tg[j] = rotate(tg[j],th);
            sort(all(tg));
            bool ok = true;
            rep(j,n)if(abs(g1[j]-tg[j]) > EPS){
                ok = false;
                break;
            }
            if(ok){
                th = abs(th);
                if(th > PI) th = 2*PI - th;
                ans = min(ans, th);
            }
        }
        printf("%.11f\n", ans);
    }
    return 0;
}
