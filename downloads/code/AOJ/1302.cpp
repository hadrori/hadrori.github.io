#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
int get_bin(){
    string s; cin >> s;
    int ret = 0;
    rep(i,s.size()) ret = ret*2+s[i]-'0';
    return ret;
}
int N, M, obj[128];
int memo[2048][2048];

int rec(int used, int yn){
    if(memo[used][yn] >= 0) return memo[used][yn];
    int cnt = 0;
    rep(i,M) if((obj[i]&used)==yn) cnt++;
    if(cnt < 2) return memo[used][yn] = 0;
    int ret = N;
    rep(i,N){
        int nu = used | (1<<i);
        if(nu == used) continue;
        ret = min(ret, max(rec(nu, yn|(1<<i)), rec(nu, yn))+1);
    }
    return memo[used][yn] = ret;
}

int solve(){
    memset(memo, -1, sizeof(memo));
    return rec(0,0);
}

bool input(){
    cin >> N >> M;
    rep(i,M) obj[i] = get_bin();
    return N or M;
}
int main(){
    while(input()) cout << solve() << endl;
    return 0;
}


