#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int inf = 1e9;
int N, Q;
vector<int> ch[100010];
int marked[100010];

void dfs(int v, int a){
    if(marked[v] == v or marked[v] == a) return;
    marked[v] = a;
    rep(i,ch[v].size()) dfs(ch[v][i], a);
}

int solve(){
    memset(marked, 0, sizeof(marked));
    int ans = 0;
    while(Q--){
        char c; int v;
        cin >> c >> v;
        v--;
        if(c == 'Q') ans += marked[v]+1;
        else dfs(v, v);
    }
    return ans;
}

bool input(){
    cin >> N >> Q;
    if(!N and !Q) return 0;
    rep(i,N) ch[i].clear();
    rep(i,N-1) {
        int a; cin >> a;
        ch[a-1].pb(i+1);
    }
    return 1;
}
signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}


