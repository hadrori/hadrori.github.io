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
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int N, T, L, B;

int next(int cur, int dice){
    if(cur + dice <= N) return cur+dice;
    return 2*N - (cur+dice);
}

int main(){
    while(cin>>N>>T>>L>>B,N||T||L||B){
        vector<int> LB(N+1,0);
        rep(i,L){
            int t;
            cin >> t;
            LB[t] = 1;
        }
        rep(i,B){
            int t;
            cin >> t;
            LB[t] = 2;
        }
        vector<vector<double> > dp(T+1,(vector<double>(N+1,0)));
        dp[0][0] = 1;
        repi(i,1,T+1)rep(j,N)repi(k,1,7){
            int ne = next(j,k);
            if(LB[ne] == 1 && i<T) dp[i+1][ne] += dp[i-1][j]/6;
            else if(LB[ne] == 2) dp[i][0] += dp[i-1][j]/6;
            else dp[i][ne] += dp[i-1][j]/6; 
            
        }
        double ans = 0;
        rep(i,T+1) ans += dp[i][N];
        printf("%.6f\n",ans);
    }
}
