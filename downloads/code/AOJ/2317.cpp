#include <bits/stdc++.h>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define INF 1e9

using namespace std;

typedef long long ll;

ll N, M;
ll p[100010], oncnt[100010], offcnt[100010];
ll s[100010], t[100010];

int main(){
    cin >> N >> M;
    M += 2;
    rep(i,N) cin >> s[i] >> t[i];
    rep(i,M-2) cin >> p[i];
    p[M-1] = INF;
    p[M-2] = 0;
    sort(p, p+M);
    ll ans = 0;
    rep(i,N){
        ll tmp = 0;
        if(s[i] > t[i]){
            ll *lb = lower_bound(p,p+M,s[i]), *lb2 = lower_bound(p,p+M,t[i]);
            lb--; lb2--;
            tmp = lb - lb2;
            ans -= *(lb+1) - s[i];
            offcnt[lb + 1 - p]--;
            if(tmp % 2){
                oncnt[lb2 + 1 - p]++;
            }
            else {
                ans -= t[i] - *lb2;
                oncnt[lb2 - p]++;
            }
        }
        else{
            ll *lb = lower_bound(p,p+M,t[i]), *lb2 = lower_bound(p,p+M,s[i]);
            lb--; lb2--;
            tmp = lb - lb2;
            ans -= s[i] - *lb2;
            oncnt[lb2 - p]++;
            if(tmp % 2){
                offcnt[lb - p]--;
            }
            else{
                ans -= *(lb+1) - t[i];
                offcnt[lb + 1 - p]--;
            }
        }
    }
    ll on = 0, off = 0;
    on += oncnt[0];
    repi(i,1,M){
        ans += on * (p[i] - p[i-1]);
        on += offcnt[i];
        swap(on, off);
        on += oncnt[i];
    }
    cout << ans << endl;
    return 0;
}
