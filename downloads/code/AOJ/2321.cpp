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

int n;
vi sat, sche, dp;

int saiki(int S){
//    cout << S << endl;
    if(dp[S] >= 0) return dp[S];
    int ret = 0;
    rep(i,n){
        if((S & sche[i]) == sche[i]){
            ret = max(ret, sat[i] + dfs(S-sche[i]));
        }
    }
    return dp[S] = ret;
}

int main(){
    while(cin>>n, n){
        sat.clear(); sat.resize(n);
        sche.clear(); sche.resize(n);
        dp.clear(); dp.resize(1<<17,-1);
        rep(i,n){
            int m, l;
            cin >> m >> sat[i];
            sche.pb(0);
            while(m--){
                int s, t;
                cin >> s >> t;
                s -= 6;
                t -= 6;
                repi(j,s,t) sche[i] |= 1<<j;
            }
        }
//        rep(i,n) rep(j,16) cout << ((sche[i]>>j)&1? 1: 0) << (j==15? '\n': ' ');
/*
        int ans = 0;
        repd(S,(1<<17)-1,0)rep(i,n){
            if(S & sche[i] == sche[i]){
                dp[S-sche[i]] = max(dp[S-sche[i]], sat[i]+dp[S]);
                ans = max(ans, dp[S-sche[i]]);
            }
        }
*/
//        cout << ans << endl;
        cout << saiki((1<<17)-1) << endl;
    }
}
