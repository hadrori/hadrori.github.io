#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

int K, N, p;
int sum[16], p10[16];

string solve(){
    for(p = 0; sum[p] <= N; p++);
    int n = (N-sum[p-1])/p+p10[p], m = (N-sum[p-1])%p;
    string ans = to_string(n++).substr(m, min(K, p-m));
    while(K > ans.size()){
        string s = to_string(n++);
        ans += s.substr(0,min(K-(int)ans.size(), (int)s.size()));
    }
    return ans;
}

void init(){
    sum[0] = 0, p10[0] = 0;
    int t = 1;
    repi(i,1,10){
        sum[i] = sum[i-1] + i*(10*t-(t<2? 0: t));
        p10[i] = t==1? 0: t;
        t *= 10;
    }
}

bool input(){
    cin >> N >> K;
    return K | N;
}
signed main(){
    init();
    while(input()) cout << solve() << endl;
    return 0;
}


