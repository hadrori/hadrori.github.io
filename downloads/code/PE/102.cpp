#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
typedef vector<P> G;

inline double dot(const P& a, const P& b) { return real(conj(a)*b);}
inline double cross(const P& a, const P& b) { return imag(conj(a)*b);}

#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
enum { OUT, ON, IN };
int contains(const G& g, const P& p) {
    bool in = false;
    for (int i = 0; i < g.size(); ++i) {
        P a = curr(g,i) - p, b = next(g,i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b) and cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

int main(){
    G g(3);
    P p = P(0,0);
    int ans = 0;
    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf", 
                 &g[0].real(), &g[0].imag(),
                 &g[1].real(), &g[1].imag(),
                 &g[2].real(), &g[2].imag())){
        if(contains(g,p)) ans++;
    }
    cout << ans << endl;
}
