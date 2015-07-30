#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct edge{ int from, to, t, m, v;};

int N, T;
vector<edge> G[310];
edge G2[310][310];
edge seq[610];
bool visited[310];
int dp[610][10010];

inline void chmax(int &a, int b){ a = max(a, b);}

void dfs(int cur, int prev, int &k){
    if(cur != prev) seq[k++] = G2[prev][cur];
    for(int i = 0; i < G[cur].size(); i++){
        edge &e = G[cur][i];
        if(e.to == prev) continue;
        dfs(e.to, cur, k);
    }
    if(cur != prev) seq[k++] = G2[cur][prev];
    return;
}

int main(){
    cin >> N >> T;
    for(int i = 0; i < N-1; i++){
        int a, b, t, m, v;
        cin >> a >> b >> t >> m >> v;
        a--; b--;
        G[a].push_back(edge{a,b,t,m,v});
        G[b].push_back(edge{b,a,t,m,v});
        G2[a][b] = edge{a,b,t,m,v};
        G2[b][a] = edge{b,a,t,m,v};
    }
    int k = 0;
    dfs(0, 0, k);


    return 0;
}
