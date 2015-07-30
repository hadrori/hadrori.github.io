#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
int D, ds[512];
set<tuple<int,int,int>> done;

bool dfs(int cl, int d, int cnt){
    if(d<D and cl&ds[d]) return 0;
    auto v = make_tuple(cl,d,cnt);
    if(done.count(v)) return 0;
    done.insert(v);
    rep(i,16){
        int c = (cnt>>(i*3))&7;
        cnt ^= c<<(i*3);
        if(cl&(1LL<<i)) c = 0;
        else c++;
        if(c == 7) return 0;
        cnt ^= c<<(i*3);
    }
    if(d == D) return 1;
    rep(i,2) {
        if(dfs(cl,d+1,cnt)) return 1;
        if(!((4369<<i)&cl) and dfs(cl>>(i+1), d+1, cnt)) return 1; // left
        if(!((34952>>i)&cl) and dfs(cl<<(i+1), d+1, cnt)) return 1; // right
        if(!((15<<(i*4))&cl) and dfs(cl>>((i+1)*4), d+1, cnt)) return 1; // up
        if(!((61440>>(i*4))&cl) and dfs(cl<<((i+1)*4), d+1, cnt)) return 1; // down
    }
    return 0;
}

int solve(){
    done.clear();
    return dfs(1632, 0, 0);
}

bool input(){
    cin >> D;
    if(!D) return 0;
    rep(i,D){
        int b = 0;
        rep(j,16) {
            int a; cin >> a;
            b |= a << j;
        }
        ds[i] = b;
    }
    return 1;
}
signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}


