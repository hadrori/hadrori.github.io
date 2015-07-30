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

  int c = 1;
  int m, n;
  while(cin >> m >> n, m){
    vector<int> v(n+1);
    vector<int> w(n+1);
    
    rep(i,n){
      scanf("%d,%d", &v[i+1],&w[i+1]);
    }
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));

    
    rep(i,n){
      rep(j,m+1){
	if(j >= w[i+1]) dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i+1]] + v[i+1]);
	dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      }
    }
    int ans_v = -1, ans_w = 0;
    rep(i, dp[0].size()){
      if(dp[n][i] > ans_v){
	ans_v = dp[n][i];
	ans_w = i;
      }
    }
    cout << "Case " << c++ << ":\n";
    cout << ans_v << endl << ans_w << endl;
  }
}
