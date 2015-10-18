#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
  
const int mod = 10000;
inline void add(int &x, int y) { (x+=y)%=mod; }
  
string A, B;
int N, M, dp[2][512][10][3][2][2][2]; // dp[pos][mod m][val][down, up, first][on A][on B][leading 0]
  
int solve() {
    N = B.size();
    A = string(N-A.size(), '0')+A;
    dp[0][0][0][2][1][1][1] = 1;
    rep(i,N) {
        memset(dp[1],0,sizeof(dp[1]));
        rep(j,M) rep(k,10) rep(l,3) rep(m,2) rep(n,2) rep(o,2) if(dp[0][j][k][l][m][n][o]) {
            rep(p,10) {
                int nj = (j*10+p)%M, nk = p, nl = o ? 2 : (l==2 ? k<p : 1-l), nm = m&(A[i]-'0'==p), nn = n&(B[i]-'0'==p), no = o&(p==0);
                if(!o) {
                    if(l == 0 and p <= k) continue;
                    if(l == 1 and p >= k) continue;
                    if(l == 2 and p and p == k) continue;
                }
                if(m and p < A[i]-'0') continue;
                if(n and p > B[i]-'0') continue;
                add(dp[1][nj][nk][nl][nm][nn][no], dp[0][j][k][l][m][n][o]);
            }
        }
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    rep(i,10) rep(j,3) rep(k,2) rep(l,2) add(ans, dp[0][0][i][j][k][l][0]);
    return ans;
}
  
void input() {
    cin >> A >> B >> M;
}
  
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}