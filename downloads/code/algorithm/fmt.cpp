int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int mod_inverse(int a, int m) {
    int x, y;
    if(extgcd(a, m, x, y) != 1) return 0;
    return (m + x % m) % m;
}

int pow_mod(int x, int k, int m) {
    int ret = 1;
    for(x%=m; k>0; x=1LL*x*x%m,k>>=1) if(k&1) ret = 1LL*ret*x%m;
    return ret;
}

const int mod = 7*17*(1<<23)+1;
vector<int> fmt(vector<int> f, bool inv) {
    int e, N = f.size();
    assert((N&(N-1))==0 and "f.size() must be power of 2");
    for(e=0;;e++) if(N == (1<<e)) break;
    rep(m,N){
        int m2 = 0;
        rep(i,e) if(m&(1<<i)) m2 |= (1<<(e-1-i));
        if(m < m2) swap(f[m], f[m2]);
    }
    for(int t=1; t<N; t*=2) {
        int r = pow_mod(3,(mod-1)/(t*2),mod);
        if(inv) r = mod_inverse(r,mod);
        for(int i=0; i<N; i+=2*t){
            int power = 1;
            rep(j,t){
                int x = f[i+j], y = 1LL*f[i+t+j]*power%mod;
                f[i+j] = (x+y)%mod;
                f[i+t+j] = (x-y+mod)%mod;
                power = 1LL*power*r%mod;
            }
        }
    }
    if(inv) for(int i=0,ni=mod_inverse(N,mod);i<N;i++) f[i] = 1LL*f[i]*ni%mod;
    return f;
}
