#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

const int mod = 1000000007;
typedef int number;
typedef vector<number> arr;
typedef vector<arr> mat;

inline void add(int &x, int y) { x = (x+y)%mod; }

mat mul(const mat &A, const mat &B)
{
    mat C(A.size(), arr(B[0].size()));
    for(int i = 0; i < (int)C.size(); ++i)
        for(int j = 0; j < (int)C[i].size(); ++j)
            for(int k = 0; k < (int)A[i].size(); ++k)
                add(C[i][j], (1LL*A[i][k]*B[k][j])%mod);
    return C;
}

mat pow(mat A, long m)
{
    const int n = A.size();
    mat B(n, arr(n));
    rep(i, n) B[i][i] = 1;
    do {
        if (m & 1) B = mul(B, A);
        A = mul(A, A);
    } while (m >>= 1);
    return B;
}

int h, r, g[16][16], dp[1<<16][16];
mat f;

int solve()
{
    f.assign(r,arr(r,0));
    rep(i,r) {
        memset(dp, 0, sizeof(dp));
        dp[1<<i][i] = 1;
        rep(j,1<<r) rep(k,r) if(dp[j][k]) {
            add(f[i][k], dp[j][k]);
            rep(l,r) if(g[k][l] and !(j>>l&1)) add(dp[1<<l|j][l], dp[j][k]);
        }
    }
    return pow(f,h)[0][0];
}

void input()
{
    cin >> h >> r;
    rep(i,r) rep(j,r) cin >> g[i][j];
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
