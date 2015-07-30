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
    rep(z,n){
        int gx, gy, p;
        bool mata[16][16][16][16] = {false};
        cin >> gx >> gy >> p;
        rep(i,p){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            mata[a][b][c][d] = true;
            mata[c][d][a][b] = true;
        }
        int dp[16][16] = {0};
        
        rep(i,gx+1){
            if(i>0 && mata[i-1][0][i][0]) break;
            dp[i][0] = 1;            
        }
        rep(i,gy+1){
            if(i>0 && mata[0][i-1][0][i]) break;
            dp[0][i] = 1;
        }
        repi(j,1,gy+1)repi(i,1,gx+1){
            if(!mata[i-1][j][i][j]) dp[i][j] += dp[i-1][j];
            if(!mata[i][j-1][i][j]) dp[i][j] += dp[i][j-1];
        }
        if(!dp[gx][gy]) cout << "Miserable Hokusai!" << endl;
        else cout << dp[gx][gy] << endl;
    }
}
