#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> G[10010];
vector<int> rG[10010];
int visited[10010];
vector<vector<int> > scc;
vector<int> V;

void dfs(int v){
    visited[v] = 1;
    for(int i = 0; i < G[v].size(); i++)
        if(!visited[G[v][i]]) dfs(G[v][i]);
    V.push_back(v);
}

void rdfs(int v){
    scc.back().push_back(v);
    visited[v] = 1;
    for(int i = 0; i < rG[v].size(); i++)
        if(!visited[rG[v][i]]) rdfs(rG[v][i]);
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    for(int i = 0; i < N; i++)
        if(!visited[i]) dfs(i);
    int ans = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = N-1; i >= 0; i--)
        if(!visited[V[i]]){
            scc.push_back(vector<int>());
            rdfs(V[i]);
            if(scc.back().size() >= 2) ans++;
        }
    printf("%d\n", ans);
    return 0;
}
