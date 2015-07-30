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
#define P pair<int,int>
#define vec vector<int>
#define mat vector<vec>

using namespace std;

int main(){
    int x, y, z;
    while(cin >> x >> y >> z, x || y || z){
        vec v(x);
        vector<P> e(y,P(0,0));
        rep(i,x) cin >> v[i];
        rep(i,z){
            int n, E, a;
            cin >> n >> E >> a;
            e[n] = P(E,a);
        }
        vector<vector<double> > dp(y+1,(vector<double>(5000,0)));
        double ans = 0;
        dp[0][0] = 1;
        rep(i,y)rep(j,5000){
            rep(k,x){
                if(i+v[k] >= y) dp[y][j] += dp[i][j]/x;
                else if(e[i+v[k]].first == 1) dp[min(y,i+v[k]+e[i+v[k]].second)][j] += dp[i][j]/x;
                else if(e[i+v[k]].first == 2) dp[i+v[k]][j+e[i+v[k]].second] += dp[i][j]/x;
                else if(e[i+v[k]].first == 3) dp[i+v[k]][max(0, j-e[i+v[k]].second)] += dp[i][j]/x;
                else dp[i+v[k]][j] += dp[i][j]/x;
            }
        }
        rep(i,5000) ans += dp[y][i] * i;
        cout << (int)ans << endl;
    }
}
