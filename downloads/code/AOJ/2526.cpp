#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define PI acos(-1.0)
typedef complex<double> P;

int r, x, y, n, sum;
P prev, moved;
double prevang, movedang;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

int calc(int rate){
    double cirArea = 1.0 * rate / 100 *  r * r *  PI;
    P s = prev;
    double sang = prevang;
    double tang = sang - 1.0 * rate / 50 * PI;
    prevang = tang;
    P t = s * polar(1.0,tang-sang);
    prev = t;
    double bArea = abs(s.real() * t.imag() - s.imag() * t.real()) / 2;
    P ts = s - moved;
    P tt = t - moved;
    double aArea = abs(ts.real() * tt.imag() - ts.imag() * tt.real()) / 2;

    if(ccw(s,t,P(0,0)) == 1) bArea *= -1;
    if(ccw(s,t,moved) == 1) aArea *= -1;
    return (int)(abs(cirArea - bArea + aArea) / cirArea * 100);
}

int main(){
    sum = 0;
    cin >> r >> x >> y >> n;
    moved = P(x,y);
    prev = P(0,100);
    prevang = PI / 2;
    rep(i,n){
        int rate;
        cin >> rate;
        cout << calc(rate) << (i==n-1? '\n': ' ');
        sum += rate;
    }
    return 0;
}
