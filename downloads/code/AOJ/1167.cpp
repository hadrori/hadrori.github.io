#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

#define pb push_back

using namespace std;

int main(){
    vector<int> ttr;
    int n = 1;
    
    while(1){
        int tr = n*(n+1)*(n+2) / 6;
        if(tr > 1000000) break;
        ttr.pb(tr);
        n++;
    }

    vector<int> dp(1000010,1000000);
    vector<int> dpo(1000010,1000000);
    dp[0] = dpo[0] = 0;
    
    rep(i,ttr.size()){
        rep(j,1000000-ttr[i]+1){
            dp[j+ttr[i]] = min(dp[j+ttr[i]], dp[j]+1);
            if(ttr[i] % 2) dpo[j+ttr[i]] = min(dpo[j+ttr[i]], dpo[j]+1);
        }
    }
    
    while(cin >> n, n){
        cout << dp[n] << ' ' << dpo[n] << endl;
    }
}