struct segtree {
    int N, dat[2*MAX];
    segtree() {}
    segtree(int n) {
        N = 1;
        while(N < n) N *= 2;
        for(int i = 0; i < 2*N-1; i++)
            dat[i] = inf;
    }
    // update k th element
    void update(int k, int a) {
        k += N-1; // leaf
        dat[k] = a; 
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // min [a, b)
    int query(int a, int b) { return query(a, b, 0, 0, N); }
    int query(int a, int b, int k, int l, int r) {
        if(r <= a or b <= l) return inf;
        if(a <= l and r <= b) return dat[k];
        int m = (l + r) / 2;
        return min(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
    }
};
