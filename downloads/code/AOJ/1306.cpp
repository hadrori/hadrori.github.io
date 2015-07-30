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
    int n;
    while(cin>>n,n){
        vector<pii> pt(n+1);
        rep(i,n) cin >> pt[i].first >> pt[i].second;
        pt[n] = mp(0,INF);
        vector<vi> dp(n+2,vi(4,INF));
        dp[0][0] = 0;
        int cur = 0;
        int t = 0;
        int fail = 0;
        rep(i,n+1){
            int p = pt[i].first;
            int res = pt[i].second - t;
            rep(j,4){
                if(!j){
                    if(res-abs(p-cur)>=0)dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(p-cur));
                }else if(j==3){
                    if(res-cur*(j+1)-p>=0)dp[i+1][1] = min(dp[i+1][1], dp[i][j] + cur + p);
                }else{
                    if(res-cur*(j+1)-p>=0)dp[i+1][1] = min(dp[i+1][1], dp[i][j] + cur + p);
                    if(res-abs(p-cur)*(j+1)>=0)dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(p-cur));
                }
            }
            bool flag = false;
            rep(j,4)if(dp[i+1][j]!=INF){
                flag = true;
                break;
            }
            if(!flag){
                fail = i+1;
                break;
            }
            cur = p;
            t = pt[i].second;
        }
        if(fail) cout << "NG " << fail << endl;
        else{
            int ans = INF;
            rep(i,4) ans = min(dp[n+1][i], ans);
            cout << "OK " << ans << endl;
        }
    }
}
