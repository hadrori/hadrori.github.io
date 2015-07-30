vector<int> poly_mul(vector<int> f, vector<int> g)
{
        int N = max(f.size(),g.size())*2;
        f.resize(N); g.resize(N);
        f = fmt(f,0); g = fmt(g,0);
        for(int i=0;i<N;++i) f[i] = 1LL*f[i]*g[i]%mod;
        f = fmt(f,1);
        return f;
}

vector<int> poly_inv(const vector<int> &f)
{
        int N = f.size();
        vector<int> r(1,mod_inverse(f[0],mod));
        for(int k = 2; k <= N; k <<= 1){
                vector<int> nr = poly_mul(poly_mul(r,r), vector<int>(f.begin(),f.begin()+k));
                nr.resize(k);
                for(int i=0;i<k/2;++i) {
                        nr[i] = (2*r[i]-nr[i]+mod)%mod;
                        nr[i+k/2] = (mod-nr[i+k/2])%mod;
                }
                r = nr;
        }
        return r;
}

const int inv2 = (mod+1)/2;
vector<int> poly_sqrt(const vector<int> &f)
{
        int N = f.size();
        vector<int> s(1,1);
        for(int k = 2; k <= N; k <<= 1){
                s.resize(k);
                vector<int> ns = poly_mul(poly_inv(s), vector<int>(f.begin(),f.begin()+k));
                ns.resize(k);
                for(int i=0;i<k;++i) s[i] = 1LL*(s[i]+ns[i])*inv2%mod;
        }
        return s;
}
