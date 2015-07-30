#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
typedef long long ll;

string ntos(ll num){
    string ret = "";
    while(num){
        int t = num % 10;
        ret += (t + '0');
        num /= 10;
    }
    reverse(all(ret));
    return ret;
}

int main(){
    ll s;
    cin >> s;
    ll pret = 0, len = 0;
    int dig;
    repi(i,1,18){
        ll t = pow(10.0,i)-1;
        ll l = i*(t-t/3-t/5+t/15-pret+pret/3+pret/5-pret/15)+4*(t/3+t/5-pret/3-pret/5);
        if(len+l<s) len += l;
        else {
            dig = i;
            break;
        }
        pret = t;
    }
    ll lb = pret+1, ub = lb*10-1;
    ll m, mlen;
    while(lb < ub){
        m = (lb + ub) / 2;
        mlen = len + dig*(m-m/3-m/5+m/15-pret+pret/3+pret/5-pret/15)+4*(m/3+m/5-pret/3-pret/5);
        if(mlen > s) ub = m - 1;
        else if(mlen < s) lb = m + 1;
        else {
            lb = m;
            ub = m;
        }
    }
    ll t = lb;
    mlen = len + dig*(lb-lb/3-lb/5+lb/15-pret+pret/3+pret/5-pret/15)+4*(lb/3+lb/5-pret/3-pret/5);
    if(!(lb % 3)) mlen -= 4;
    if(!(lb % 5)) mlen -= 4;
    if(lb%3 && lb%5) mlen -= dig;
    ll w = s - mlen;
    string ans = "";
    ll cur = lb;

    while(ans.size() <= 20 + w){
        if(!(cur % 3)) ans += "Fizz";
        if(!(cur % 5)) ans += "Buzz";
        if(cur%3 && cur%5) ans += ntos(cur);
        cur++;
    }
    rep(i,20) cout << ans[i+w-1];
    cout << endl;
    return 0;
}
