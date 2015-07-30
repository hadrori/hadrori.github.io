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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

#define INF 1e8

int fit(int a){
    if(a<0) return 0;
    if(a>255) return 255;
    return a;
}

int main(){
    int n, m;
    while(cin>>n>>m,n||m){
        vec c(m);
        vec x(n);
        rep(i,m) cin >> c[i];
        rep(i,n) cin >> x[i];

        mat dp(2,vec(256,INF));
        dp[1][128] = 0;
        int l;
        rep(i,n){
            rep(j,256) dp[i%2][j] = INF;
            rep(j,256)rep(k,m){
                int t = fit(j+c[k]);
                dp[i%2][t] = min(dp[i%2][t],dp[(i+1)%2][j]+(x[i]-t)*(x[i]-t));
            }
            l = i%2;
        }
        
        cout << *min_element(dp[l].begin(),dp[l].end()) << endl;
    }
}
