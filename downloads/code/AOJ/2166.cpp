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
    int T;
    while(cin>>T,T){
        vi t(T);
        rep(i,T) cin >> t[i];
        int N;
        cin >> N;
        int Md = 0;
        vi job(128,INF);
        rep(i,N){
            int d, m;
            cin >> d >> m;
            d--;
            Md = max(Md, d);
            job[d] = min(job[d],m);
        }
        vector<vi> dp(128,vi(T,INF));
        dp[0][0] = 0;
        rep(i,Md)rep(j,T){
//            cout << dp[i][j] << (j==T-1? '\n':' ');
/*
            printf("%10d", dp[i][j]);
            cout << (j==T-1? '\n':' ');
*/
            if(j==T-1) dp[i+1][0] = min(dp[i+1][0],dp[i][j]);
            else if(t[j+1]>job[i+1]) dp[i+1][0] = min(dp[i+1][0],dp[i][j]+1);
            else {
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
                dp[i+1][0] = min(dp[i+1][0],dp[i][j]+1);
            }
        }
/*
        rep(j,T){
            printf("%10d", dp[Md][j]);
            cout << (j==T-1? '\n':' ');
        }
*/
        int ans = INF;
        rep(i,T) ans = min(ans, dp[Md][i]);
        cout << ans << endl;
    }
}
