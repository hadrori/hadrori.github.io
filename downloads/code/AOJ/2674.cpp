#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
 
template<int N> class FID {
    static const int bucket = 512, block = 16;
    static char popcount[];
    int n, B[N/bucket+10];
    unsigned short bs[N/block+10], b[N/block+10];
 
public:
    FID(){}
    FID(int n, bool s[]) : n(n) {
        if(!popcount[1]) for (int i = 0; i < (1<<block); i++) popcount[i] = __builtin_popcount(i);
 
        bs[0] = B[0] = b[0] = 0;
        for (int i = 0; i < n; i++) {
            if(i%block == 0) {
                bs[i/block+1] = 0;
                if(i%bucket == 0) {
                    B[i/bucket+1] = B[i/bucket];
                    b[i/block+1] = b[i/block] = 0;
                }
                else b[i/block+1] = b[i/block];
            }
            bs[i/block]   |= short(s[i])<<(i%block);
            b[i/block+1]  += s[i];
            B[i/bucket+1] += s[i];
        }
        if(n%bucket == 0) b[n/block] = 0;
    }
 
    int count(bool val, int r) { return val? B[r/bucket]+b[r/block]+popcount[bs[r/block]&((1<<(r%block))-1)]: r-count(1,r); }
    int count(bool val, int l, int r) { return count(val,r)-count(val,l); }
};
template<int N> char FID<N>::popcount[1<<FID<N>::block];
 
template<class T, int N, int D> class wavelet {
    int n, zs[D];
    FID<N> dat[D];
 
    int freq_dfs(int d, int l, int r, T val, T a, T b) {
        if(l >= r or val >= b) return 0;
        if(d == D) return a <= val ? r-l : 0;
        T nv = 1LL<<(D-d-1)|val, nnv = ((1ULL<<(D-d-1))-1)|nv;
        if(nnv < a) return 0;
        if(a <= val and nnv < b) return r-l;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        return freq_dfs(d+1,l-lc,r-rc,val,a,b) + freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
    }
public:
    wavelet() {}
    wavelet(int n, T seq[]) : n(n) {
        T f[N], l[N], r[N];
        bool b[N];
        memcpy(f, seq, sizeof(T)*n);
        for (int d = 0; d < D; d++) {
            int lh = 0, rh = 0;
            for (int i = 0; i < n; i++) {
                bool k = (f[i]>>(D-d-1))&1;
                if(k) r[rh++] = f[i];
                else l[lh++] = f[i];
                b[i] = k;
            }
            dat[d] = FID<N>(n,b);
            zs[d] = lh;
            swap(l,f);
            memcpy(f+lh, r, rh*sizeof(T));
        }
    }
    int freq(int l, int r, T a, T b) { return freq_dfs(0,l,r,0,a,b); }
};
 
const int base = 5e8;
wavelet<int,100100,30> wv;
int n, q, x[100010];
 
void solve() {
    wv = wavelet<int,100100,30>(n,x);
    int l, r, e;
    while(q--) {
        cin >> l >> r >> e;
        l--; r--;
        cout << wv.freq(l,r+1,0,min(x[l],x[r])-e)+wv.freq(l,r+1,max(x[l],x[r])+e+1,1e9) << endl;
    }
}
 
void input() {
    cin >> n;
    rep(i,n) {
        cin >> x[i];
        x[i] += base;
    }
    cin >> q;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}