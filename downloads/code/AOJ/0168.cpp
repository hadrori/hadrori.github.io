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
    int dp[35] = {0};
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    repi(i,3,31){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    int n;
    while(cin >> n, n){
        int ans = (dp[n]%10)? dp[n]/10 + 1: dp[n]/10;
        ans = (ans%365)? ans/365 + 1: ans/365;
        cout << ans << endl;
    }
}
