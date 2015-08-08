#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

template<int N> class FID {
    static const int bucket = 512, block = 16;
    static char popcount[];
    int n, B[N/bucket+1];
    unsigned short bs[N/block+1], b[N/block+1];

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
    bool operator[](int i) { return bs[i/block]>>(i%block)&1; }
};
template<int N> char FID<N>::popcount[1<<FID<N>::block];

template<class T, int N, int D> class wavelet {
public:
    int n, zs[D];
    FID<N> dat[D];

    wavelet(){}
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
};

const int N = 100100, D = 30;

wavelet<int,2*N,D> a, b;
int n, m, val[N], in[N], dep[N], par[N][20], idx, p[2*N], q[2*N], sz[N];
vector<int> G[N];

void euler_tour(int v)
{
    for (int k = 0; ~par[v][k] and ~par[par[v][k]][k]; k++)
        par[v][k+1] = par[par[v][k]][k];
    p[idx] = val[v];
    in[v] = idx++;
    for(int &w: G[v])
        if(w != par[v][0]) {
            par[w][0] = v;
            dep[w] = dep[v]+1;
            euler_tour(w);
        }
    q[idx++] = val[v];
}

void build()
{
    memset(par,-1,sizeof(par));
    euler_tour(n/2);
    a = wavelet<int,2*N,D>(2*n, p);
    b = wavelet<int,2*N,D>(2*n, q);
}

int lca(int u, int v)
{
    if(dep[u] > dep[v]) swap(u,v);
    int dif = dep[v] - dep[u];
    for (int i = 0; i < 18; i++)
        if(dif&(1<<i)) v = par[v][i];
    if(u == v) return u;
    for (int i = 17; i >= 0; i--)
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

int query(int v, int w, int k)
{
    int u = lca(v,w);
    k = dep[v]+dep[w]-2*dep[u]-k+1;
    int lva = in[u], lvb = in[u],
        rva = in[v]+1, rvb = in[v]+1,
        lwa = in[u]+1, lwb = in[u]+1,
        rwa = in[w]+1, rwb = in[w]+1,
        ret = 0;
    rep(d,D) {
        int lvac = a.dat[d].count(1,lva), lvbc = b.dat[d].count(1,lvb),
            rvac = a.dat[d].count(1,rva), rvbc = b.dat[d].count(1,rvb),
            lwac = a.dat[d].count(1,lwa), lwbc = b.dat[d].count(1,lwb),
            rwac = a.dat[d].count(1,rwa), rwbc = b.dat[d].count(1,rwb);
        int lc = lvac-lvbc+lwac-lwbc,
            rc = rvac-rvbc+rwac-rwbc;
        if(rc-lc > k) {
            lva = lvac+a.zs[d]; lvb = lvbc+b.zs[d];
            rva = rvac+a.zs[d]; rvb = rvbc+b.zs[d];
            lwa = lwac+a.zs[d]; lwb = lwbc+b.zs[d];
            rwa = rwac+a.zs[d]; rwb = rwbc+b.zs[d];
            ret |= 1ULL<<(D-d-1);
        }
        else {
            k -= rc-lc;
            lva -= lvac; lvb -= lvbc;
            rva -= rvac; rvb -= rvbc;
            lwa -= lwac; lwb -= lwbc;
            rwa -= rwac; rwb -= rwbc;
        }
    }
    return ret;
}

void solve()
{
    build();
    while(m--) {
        int v, w, l;
        scanf("%d%d%d", &v, &w, &l);
        printf("%d\n", query(v-1,w-1,l));
    }
}

void input()
{
    scanf("%d%d", &n, &m);
    rep(i,n) scanf("%d", val+i);
    rep(i,n-1) {
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

int main()
{
    input();
    solve();
    return 0;
}
