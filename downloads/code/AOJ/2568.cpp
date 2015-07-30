#include <cstring>
#include <iostream>
#include <vector>

#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define INF 1e9

using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> sp;
bool checked[100010];
const int mod = INF + 7;

bool input(){
    cin >> N >> M;
    if(!N) return 0;
    sp.clear();
    sp.resize(N);
    int a, b;
    rep(i,M) {
        cin >> a >> b;
        a--; b--;
        sp[a].pb(b);
        sp[b].pb(a);
    }
    return 1;
}

int dfs(int i){
    if(checked[i]) return 0;
    checked[i] = 1;
    int ret = 1;
    rep(j,sp[i].size())
        ret += dfs(sp[i][j]);
    return ret;
}

int solve(){
    memset(checked, 0, sizeof(checked));
    int cnt = 0;
    bool cntall = 0;
    rep(i,N) if(!checked[i]){
        cnt++;
        if(dfs(i) > 1) cntall = 1;
    }
    int ans = 1;
    rep(i,cnt){
        ans <<= 1;
        ans %= mod;
    }
    return (ans + cntall) % mod;
}

signed main(){
    while(input()){ cout << solve() << endl; }
    return 0;
}
