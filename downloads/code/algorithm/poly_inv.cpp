vector<int> poly_inv(const vector<int> &f) {
    int N = f.size();
    vector<int> r(1,mod_inverse(f[0],mod));
    for(int k = 2; k <= N; k <<= 1) {
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
