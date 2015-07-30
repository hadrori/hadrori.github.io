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

double dp[100002][15];
double ans[100002];

int main(){
    dp[0][0] = 1;
    double expc = 0;
    rep(i,100001){
        rep(j,15){
            double rate = 1.0 / (1 << j);
            expc += dp[i][j] * rate;
            dp[i+1][j+1] += dp[i][j] * rate;
            dp[i+1][0] += dp[i][j] * (1.0 - rate);
        }
        ans[i] = expc;
    }
    int n;
    while(cin >> n, n){
        printf("%.8f\n", ans[n-1] );
    }
}