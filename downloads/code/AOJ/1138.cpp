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

int main(){
    int n, m, p, a, b;
    while(cin>>n>>m>>p>>a>>b,n||m||p||a||b){
        vi t(n);
        rep(i,n) cin >> t[i];
        vector<vi> path(m,vi(m,-1));
        rep(i,p){
            int x, y, z;
            cin >> x >> y >> z;
            x--; y--;
            path[x][y] = z;
            path[y][x] = z;
        }
        vector<vector<double> > dp(1<<n,vector<double> (m,INF));
        dp[(1<<n)-1][a-1] = 0;
        double ans = INF;
        repd(S,(1<<n)-1,0){
            ans = min(ans, dp[S][b-1]);
            rep(v,m)rep(i,n)rep(u,m){
                if(((S>>i) & 1) && path[v][u] != -1){
                    dp[S-(1<<i)][u] = min(dp[S-(1<<i)][u], dp[S][v] + 1.0*path[v][u]/t[i]);
                }
            }
        }
        if(ans == INF) cout << "Impossible\n";
        else printf("%.4f\n",ans);
    }
}
