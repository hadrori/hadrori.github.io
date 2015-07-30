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
        int n;
        cin >> n;
        vector<vector<int> > dp(a+1,vector<int>(b+1,1));
        rep(i,a+1) dp[i][0] = 0;
        rep(i,b+1) dp[0][i] = 0;
 
        rep(i,n){
            int x, y;
            cin >> x >> y;
            dp[x][y] = 0;
        }
        dp[1][0] = 1;
        repi(j,1,b+1) repi(i,1,a+1){
            if(dp[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        cout << dp[a][b] << endl;
    }
}
