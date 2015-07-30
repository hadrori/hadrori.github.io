#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
const ull d = ULLONG_MAX/1024;
const ull llm = LLONG_MAX;

int n, k, x0, cnt[1024];

void rnd(ull &x){
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
}

ll solve(){
    if(!x0) return 0;
    ull x = x0;
    rep(i,n){
        cnt[(ull)(x+llm)/d]++;
        rnd(x);
    }
    int sum = 0, pos = 0;
    rep(i,1024){
        if(sum+cnt[i] >= k){
            pos = i;
            k -= sum+1;
            break;
        }
        sum += cnt[i];
    }
    vector<ll> a;
    x = x0;
    rep(i,n){
        if((ull)(x+llm)/d == (ull)pos) a.pb(x);
        rnd(x);
    }
    sort(all(a));
    return a[k];
}

int main(){
    cin >> n >> k >> x0;
    cout << solve() << endl;
    return 0;
}


