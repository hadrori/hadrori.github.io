#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

#define INF 10000000

typedef long long ll;

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<vector<int> > t(n,vector<int>(n+1));
        rep(i,n) rep(j,n+1) cin >> t[i][j];
        
        int dp[1<<16];
        rep(i,1<<16) dp[i] = INF;
        dp[0] = 0;
        rep(i,1<<n) rep(j,n){ 
            if(!(i & (1<<j))){
                dp[i+(1<<j)] = min(dp[i+(1<<j)],dp[i]+t[j][0]);
                rep(k,n){
                    if(i & (1<<k)) dp[i+(1<<j)] = min(dp[i+(1<<j)],dp[i]+t[j][k+1]);
                }
            }
        }
        cout << dp[(1<<n)-1] << endl;
    }
}
