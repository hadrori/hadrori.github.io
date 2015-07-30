#include <cstdio>
#include <cstring>
#include <vector>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back

using namespace std;

typedef vector<int> vi;

int N, M, maxId;
int v[1024], id[1024], nim[1024];
vi edge[1024];

void input() {
    scanf("%d%d", &N, &M);
    rep(i,N) scanf("%d", v+i);
    rep(i,M){
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edge[a].pb(b);
    }
    memset(id,-1,sizeof(id));
}

int build_id(int u){
    if(id[u] >= 0) return id[u];
    bool used[1024] = {0};
    rep(i,edge[u].size()) used[build_id(edge[u][i])] = 1;
    int k = 0;
    while(used[k++]);
    maxId = max(maxId, k);
    return id[u] = --k;
}

int solve() {
    rep(i,N) build_id(i);
    rep(i,maxId)
        rep(j,N) if(id[j] == i)
            nim[i] ^= v[j];
    rep(i,maxId)
        if(nim[i]) return 1;
    return 2;
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
