#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
int dim[128], door[128][64], cnt[128], depth[128];

void dfs(int &idx, int dep){
    int id = idx, nxt;
    depth[dep] = id;
    while(cnt[id] < dim[id]){
        cin >> nxt;
        if(nxt > 0) {
            door[id][cnt[id]++] = ++idx;
            door[idx][cnt[idx]++] = id;
            dim[idx] = nxt;
            dfs(idx, dep+1);
        }
        if(nxt < 0) {
            int nid = depth[nxt+dep];
            door[nid][cnt[nid]++] = id;
            door[id][cnt[id]++] = nid;
        }
    }
}

void solve(){
    memset(dim, -1, sizeof(dim));
    memset(door, -1, sizeof(door));
    memset(cnt, 0, sizeof(cnt));
    cin >> dim[0];
    int idx = 0;
    dfs(idx,0);
    cin >> cnt[0];
    rep(i,idx+1) {
        cout << i+1 << ' ';
        sort(door[i], door[i]+dim[i]);
        rep(j,dim[i]) cout << door[i][j]+1 << (j==dim[i]-1? '\n': ' ');
    }
}

signed main(){
    int T; cin >> T;
    while(T--) solve();
    return 0;
}


