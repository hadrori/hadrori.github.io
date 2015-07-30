#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
typedef unsigned long long ull;
const ull b = 1000000007;
int N, M, l, r;
string s;
ull powb[300010], shash[300010], S[300010];

int solve(){
    powb[0] = 1;
    rep(i,N) {
        powb[i+1] = powb[i]*b;
        shash[i+1] = shash[i]*b+s[i];
    }
    r = 1;
    rep(i,M){
        cin >> s;
        if(s=="R++") r++;
        else if(s=="R--") r--;
        else if(s=="L++") l++;
        else l--;
        S[i] = shash[r]-shash[l]*powb[r-l];
    }
    sort(S,S+M);
    return unique(S,S+M)-S;
}

signed main(){
    cin >> N >> M >> s;
    cout << solve() << endl;
    return 0;
}


