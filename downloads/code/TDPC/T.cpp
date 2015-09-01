#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1000000007;
typedef vector<int> poly;

int K, N;

poly mul(const poly &a, const poly &b) {
    poly c(2*K,0);
    rep(i,K) rep(j,K) (c[i+j] += 1LL*a[i]*b[j]%mod) %= mod;
    for(int i = 2*K-2; i >= K; i--) repi(j,i-K,i) (c[j] += c[i]) %= mod;
    c.resize(K);
    return c;
}

int solve() {
    poly a(K,0), b = a;
    a[1] = b[0] = 1;
    for(int i = N-1; i > 0; i >>= 1, a = mul(a,a)) if(i&1) b = mul(a,b);
    int ans = 0;
    rep(i,K) (ans += b[i]) %= mod;
    return ans;
}

void input() {
    cin >> K >> N;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
