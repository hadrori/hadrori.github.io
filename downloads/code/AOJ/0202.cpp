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

vector<int> prime;
int p[1000001] = {false};

void pcalc(){
    repi(i,2,1000001) p[i] = true;
    rep(i,1001)if(p[i]){
        prime.pb(i);
        for(int j=i*2; j < 1000001; j += i) p[j] = false;
    }
}

int main(){
    pcalc();
    int n, x;
    while(cin >> n >> x, n || x){
        vector<bool> dp(x+1,false);
        int ans = 0;
        dp[0] = true;
        rep(z,n){
            int dish;
            cin >> dish;
            repi(i,dish,x+1) if(dp[i-dish]){
                dp[i] = true;
                if(p[i]) ans = max(ans,i);
            }
        }
        if(!ans) cout << "NA" << endl;
        else cout << ans << endl;
    }
}
