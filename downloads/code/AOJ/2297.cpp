#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
typedef pair<int,int> pii;
vector<pii> stmp;
int dist[1<<16], col[4][4], N;

int solve(){
    memset(dist, -1, sizeof(dist));
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(v == (1<<16)-1) return dist[v];
        rep(k,N)repi(i,-stmp[k].first+1, 4)repi(j,-stmp[k].second+1,4)rep(c,3){
            int u = v;
            repi(ni,max(i,0),min(i+stmp[k].first,4))
                repi(nj,max(j,0),min(j+stmp[k].second,4))
                    u = (u^(((u>>(ni*4+nj))&1)<<(ni*4+nj))) | ((c==col[ni][nj])<<(ni*4+nj));
            if(dist[u] < 0){
                dist[u] = dist[v]+1;
                que.push(u);
            }
        }
    }
    return 0;
}

void input(){
    cin >> N;
    rep(i,N){
        int h, w;
        cin >> h >> w;
        stmp.pb(pii(h,w));
    }
    rep(i,4)rep(j,4){
        char c; cin >> c;
        col[i][j] = c=='R'? 0: c=='G'? 1: 2;
    }
}
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


