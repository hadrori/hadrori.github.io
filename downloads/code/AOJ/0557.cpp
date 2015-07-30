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
    int n;
    cin >> n;
    int st, rs;
    vector<int> dg(n-2);
    cin >> st;
    rep(i,n-2) cin >> dg[i]; 
    cin >> rs;
    
    vector<vector<ll> > dp(n-1,vector<ll>(21,0));
    dp[0][st] = 1;
    rep(i,n-2) rep(j,21){
        if(dp[i][j]){
            if(j + dg[i] < 21) dp[i+1][j+dg[i]] += dp[i][j];
                if(j - dg[i] >= 0) dp[i+1][j-dg[i]] += dp[i][j];
        }
    }
    cout << dp[n-2][rs] << endl;
}
