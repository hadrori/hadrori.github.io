#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
typedef long long ll;
const int MAX = 21;
ll fact[MAX];

ll comb(int n, int k){
    return fact[n]/fact[k]/fact[n-k];
}
int main(){
    string str;
    cin >> str;
    int cnt[26] = {0};
    rep(i,str.size()) cnt[str[i]-'a']++;
    int o = 0;
    rep(i,26){
        if(cnt[i] % 2) o++;
        cnt[i] /= 2;
    }
    if((!(str.size()%2) && o) || (str.size()%2 && o > 1)){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1, res = str.size()/2;
    fact[0] = 1;
    repi(i,1,MAX) fact[i] = fact[i-1] * i;
    rep(i,26)if(cnt[i]){
        ans *= comb(res,cnt[i]);
        res -= cnt[i];
    }
    cout << ans << endl;
    return 0;
}
