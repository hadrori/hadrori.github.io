#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e4;

int main(){
    int n, k;
    cin >> n >> k;
    int dp[128][3][3] = {0};
    int plan[128];
    rep(i,n) plan[i] = -1;
    rep(i,k){
        int a, b;
        cin >> a >> b;
        a--; b--;
        plan[a] = b;
    }
    if(plan[0] != -1) dp[0][plan[0]][0] = 1;
    else {
        rep(i,3){
            dp[0][i][0] = 1;
        }
    }
    rep(d,n-1)rep(p,3)rep(s,2){
        if(plan[d+1] != -1){
            if(p!=plan[d+1] || s!=1){
                if(p == plan[d+1]){
                    dp[d+1][plan[d+1]][s+1] += dp[d][p][s];
                    dp[d+1][plan[d+1]][s+1] %= mod;
                }else{
                    dp[d+1][plan[d+1]][0] += dp[d][p][s];
                    dp[d+1][plan[d+1]][0] %= mod;
                }
            }
        }else{
            if(s == 1){
                dp[d+1][(p+1)%3][0] += dp[d][p][s];
                dp[d+1][(p+1)%3][0] %= mod;
                dp[d+1][(p+2)%3][0] += dp[d][p][s];
                dp[d+1][(p+2)%3][0] %= mod;
            }else if(s == 0){
                dp[d+1][p][1] += dp[d][p][s];
                dp[d+1][p][1] %= mod;
                dp[d+1][(p+1)%3][0] += dp[d][p][s];
                dp[d+1][(p+1)%3][0] %= mod;
                dp[d+1][(p+2)%3][0] += dp[d][p][s];
                dp[d+1][(p+2)%3][0] %= mod;
            }
        }        
    }
    int ans = 0;
    rep(p,3) rep(s,2){
        ans += dp[n-1][p][s];
        ans %= mod;
    }
    cout << ans << endl;
}
