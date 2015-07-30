#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g; // 1なら解あり
}

long long mod_inverse(long long a, long long m){
    long long x, y;
    if(extgcd(a, m, x, y) != 1) return 0; // unsolvable
    return (m + x % m) % m;
}

const ll m = 999979, n = 999983;

void calc(ll &mx, ll &nx, int o, int y){
    switch(o){
    case 1:
        mx = (mx + y) % m;
        nx = (nx + y) % n;
        break;
    case 2:
        mx = (mx - y + m) % m;
        nx = (nx - y + n) % n;
        break;
    case 3:
        mx = mx * y % m;
        nx = nx * y % n;
        break;
    case 4:
        mx = mx * mod_inverse(y,m) % m;
        nx = nx * mod_inverse(y,n) % n;
        break;
    }
}

int main(){
    int N;
    ll mx = 0, nx = 0;
    cin >> N;
    while(N--){
        ll o, y;
        cin >> o >> y;
        calc(mx,nx,o,y);
    }
    ll s, t;
    extgcd(m,n,s,t);
    ll x = (m * s * nx + n * t * mx) % (m * n);
    if(x >= 1LL<<31) x -= m * n; 
    cout << x << endl;
    return 0;
}
