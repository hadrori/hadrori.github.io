#include <cstdio>

#define int long long
using namespace std;

int N, M;

int fact(int n, int p){
    if(!n) return 1;
    return (n*fact(n-1,p))%p;
}

int mod_fact(int n, int p, int &e){
    e = 0;
    if(!n) return 1;
    int res = mod_fact(n/p, p, e);
    e += n / p;
    if(n/p%2) return res * (p-fact(n%p,p)) % p;
    return res * fact(n%p,p) % p;
}
int extgcd(int a, int b, int &x, int &y){
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int mod_inv(int a, int m){
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int mod_pow(int n, int e, int m){
    if(e==0) return 1;
    if(e%2) return n*mod_pow(n,e-1,m)%m;
    return mod_pow(n*n%m,e/2,m);
}

int solve(){
    M = N - M;
    int a2, a5, e2, e5,
        ma2, ma5, me2, me5;
    ma2 = mod_fact(M,2,me2);
    a2 = mod_fact(N,2,e2);
    e2 -= me2;
    ma5 = mod_fact(M,5,me5);
    a5 = mod_fact(N,5,e5);
    e5 -= me5;
    int e10 = e2>e5? e5: e2;
    e2 -= e10; e5 -= e10;
    a2 = e2 > 0? 0: a2*mod_inv(ma2,2)*mod_inv(mod_pow(5,e10,2),2)%2;
    a5 = e5 > 0? 0: a5*mod_inv(ma5,5)*mod_inv(mod_pow(2,e10,5),5)%5;
    for(int i = 1; i < 10; i++)
        if(i%2==a2 and i%5==a5) return i;
    return 0;
}

signed main(){
    while(~scanf("%lld%lld", &N, &M))
        printf("%lld\n", solve());
    return 0;
}
