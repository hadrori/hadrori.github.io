#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;

const int mod = 100000007;
const int MAX = 1024;
int dr[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dc[] = {1, 1, 1, 0, -1, -1, -1, 0};

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g; // 1なら解あり
}

ll mod_inverse(ll a, ll m){
    ll x, y;
    if(extgcd(a, m, x, y) != 1) return 0; // unsolvable
    return (m + x % m) % m;
}

ll fact[MAX];
ll mod_fact(ll n, ll m, ll& e){
    e = 0;
    if(!n) return 1;
    ll res = mod_fact(n / m, m, e);
    e += n / m;
    if(n / m % 2) return res * (m - fact[n % m]) % m;
    return res * fact[n % m] % m;
}

ll mod_comb(ll n, ll k, ll m){
    if(n < 0 || k < 0 || n < k) return 0;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, m, e1), a2 = mod_fact(k, m, e2), a3 = mod_fact(n - k, m, e3);
    if(e1 > e2 + e3) return 0; // m で割り切れる
    return a1 * mod_inverse(a2 * a3 % m, m) % m;
}

int main(){
    fact[0] = 1;
    repi(i,1,MAX) fact[i] = fact[i-1] * i % mod;
    int r, c;
    complex<int> a, b;
    vector<complex<int> > d;
    cin >> r >> c >> a.real() >> a.imag() >> b.real() >> b.imag();
    d.pb(b);
    rep(i,8){
        complex<int> t;
        t.real() = b.real() + dr[i] * r;
        t.imag() = b.imag() + dc[i] * c;
        if(norm(d[0]-a) > norm(t-a)){
            d.clear();
            d.pb(t);
        }
        else if(norm(d[0]-a) == norm(t-a)) d.pb(t);
    }
    ll ans = 0;
    rep(i,d.size()){
        complex<int> t;
        t = d[i] - a;
        t.real() = abs(t.real());
        t.imag() = abs(t.imag());
        ans += mod_comb(t.real()+t.imag(),t.real(),mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
