#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
bool check[10];

bool pand(i64 x) {
    memset(check,0,sizeof(check));
    rep(i,9) {
        if(check[x%10] or x%10 == 0) return 0;
        check[x%10] = 1;
        x /= 10;
    }
    return 1;
}

const int mod = 1e9;
const long double phi = log10(1.0+sqrt(5))-log10(2), d = log10(5)/2;

int solve() {
    i64 a = 0, b = 1, c;
    for (int i = 2; ; i++) {
        c = (a + b) % mod;
        if(pand(c)) {
            const long double lf = i * phi - d;
            if(pand(pow(10.0, lf - floor(lf) + 8))) return i;
        }
        a = b; b = c;
    }
    return -1;
}

int main() {
    cout << solve() << endl;
    return 0;
}
