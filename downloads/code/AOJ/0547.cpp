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

typedef long long ll;

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b, a || b){
        int dp[128][128][4] = {0};
        rep(i,a) dp[i][0][2] = 1;
        rep(i,b) dp[0][i][0] = 1;
        dp[0][0][0] = 0;
        repi(j,1,b)repi(i,1,a){
            dp[i][j][0] = (dp[i][j-1][0] + dp[i][j-1][1]) % 100000;
            dp[i][j][1] = dp[i][j-1][2] % 100000;
            dp[i][j][2] = (dp[i-1][j][2] + dp[i-1][j][3]) % 100000;
            dp[i][j][3] = dp[i-1][j][0] % 100000;
        }

        int ans = 0;
        rep(i,4) ans += dp[a-1][b-1][i];
        ans %= 100000;
        cout << ans << endl;
    }
}
