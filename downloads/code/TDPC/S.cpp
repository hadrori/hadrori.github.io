#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1e9+7;
inline void add(int &x, int y) { x=(x+y)%mod; }

struct union_find {
    int par[8], rnk[8];
    union_find() {
        memset(par,0,sizeof(par));
        memset(rnk,0,sizeof(rnk));
        rep(i,8) { par[i] = i; rnk[i] = 1; }
    }

    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(rnk[x] < rnk[y]) par[x] = y;
        else {
            par[y] = x;
            if(rnk[x] == rnk[y]) rnk[x]++;
        }
    }
};

int h, w, dp[2][118000], pw[8];

int solve() {
    pw[0] = 1;
    rep(i,7) pw[i+1] = pw[i]*7;

    rep(i,1<<h) if(i&1) {
        int f = 1, p = 1;
        repi(j,1,h) {
            if(i>>j&1) f += p*pw[j];
            else if(i>>(j-1)&1) p++;
        }
        dp[0][f] = 1;
    }

    rep(i,w-1) {
        memset(dp[1],0,sizeof(dp[1]));
        rep(j,pw[h]) if(dp[0][j]) {
            rep(k,1<<h) {
                union_find uf;
                int p[8];
                memset(p,0,sizeof(p));
                rep(l,h) if(k>>l&1) {
                    if(j/pw[l]%7 == 1) p[l] = 1;
                    repi(m,l+1,h) if(k>>m&1) {
                        if(m == l+1) uf.unite(l,m);
                        else {
                            int u = j/pw[l]%7, v = j/pw[m]%7;
                            if(u and u == v) uf.unite(l,m);
                        }
                    }
                }
                rep(l,h) if(p[l] == 1) p[uf.find(l)] = 1;
                int nj = 0, f = 2;
                rep(l,h) if(k>>l&1) {
                    int u = uf.find(l);
                    if(!p[u]) p[u] = f++;
                    nj += pw[l]*p[u];
                }
                add(dp[1][nj], dp[0][j]);
            }
        }
        swap(dp[0], dp[1]);
    }

    int ans = 0;
    rep(i,pw[h]) if(i/pw[h-1]%7 == 1) add(ans, dp[0][i]);

    return ans;
}

void input() {
    cin >> h >> w;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
