#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
inline int add(int a, int b) { return (a+b)%mod;}
inline int sub(int a, int b) { return (a-b+mod)%mod;}
inline int mul(int a, int b) { return 1LL*a*b%mod;}

struct warp
{
        int sx, sy, tx, ty;
        bool operator<(const warp &w) const {
                if(sx != w.sx) return sx < w.sx;
                return sy < w.sy;
        }
};

int extgcd(int a, int b, int &x, int &y)
{
        int g = a; x = 1; y = 0;
        if(b != 0) g = extgcd(b,a%b,y,x), y -= a/b*x;
        return g;
}
int inv(int a) {
        int x, y; extgcd(a,mod,x,y);
        return (mod+x%mod)%mod;
}
int fact[200010];
inline int nck(int n, int k) { return mul(mul(fact[n], inv(fact[n-k])), inv(fact[k]));}


int n, m, k, dp[100010];
// dp[i] := i番目のワープホールの入り口までの場合の数
vector<warp> warps;

inline int calc(int sx, int sy, int tx, int ty)
{
        if(tx < sx or ty < sy) return 0;
        return nck(tx-sx+ty-sy, tx-sx);
}

int solve()
{
        memset(dp,0,sizeof(dp));
        sort(begin(warps),end(warps));
        warps.push_back((warp){n,m, n+1, m+1});
        for (int i = 0; i <= k; i++) {
                dp[i] = nck(warps[i].sx+warps[i].sy, warps[i].sy);
                for (int j = 0; j < i; j++) {
                        dp[i] = add(dp[i], mul(dp[j], sub(calc(warps[j].tx, warps[j].ty, warps[i].sx,warps[i].sy),
                                                          calc(warps[j].sx, warps[j].sy, warps[i].sx,warps[i].sy))));
                }
        }
        return dp[k];
}

bool input()
{
        warps.clear();
        cin >> n >> m >> k;
        n--; m--;
        int a, b, c, d;
        for (int i = 0; i < k; i++) {
                cin >> a >> b >> c >> d;
                warps.push_back((warp){a-1,b-1,c-1,d-1});
        }
        return n+1 or m+1 or k;
}

int main()
{
        fact[0] = 1;
        for (int i = 0; i < 200000; i++) fact[i+1] = mul(fact[i], i+1);
        while(input()) cout << solve() << endl;
        return 0;
}
