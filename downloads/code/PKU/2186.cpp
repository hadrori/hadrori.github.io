#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> E[10010], rE[10010];
vector<vector<int> > scc;
int group[10010];
bool visited[10010];
vector<int> vs;

void dfs(int s){
    visited[s] = 1;
    for(int i = 0; i < E[s].size(); i++)
        if(!visited[E[s][i]]) dfs(E[s][i]);
    vs.push_back(s);
}

void rdfs(int s, int k){
    visited[s] = 1;
    group[s] = k;
    scc.back().push_back(s);
    for(int i = 0; i < rE[s].size(); i++)
        if(!visited[rE[s][i]]) rdfs(rE[s][i], k);
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        E[a].push_back(b);
        rE[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
        if(!visited[i]) dfs(i);
    
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i = 0; i < N; i++)
        if(!visited[vs[N-i-1]]){
            scc.push_back(vector<int>());
            rdfs(vs[N-i-1], cnt++);
        }
    
    int ans = -1;
    for(int i = 0; i < scc.size(); i++){
        int g = group[scc[i][0]];
        bool exist = 0;
        for(int j = 0; j < scc[i].size(); j++){
            for(int k = 0; k < E[scc[i][j]].size(); k++)
                if(g != group[E[scc[i][j]][k]]) {
                    exist = 1;
                    break;
                }
            if(exist) break;
        }
        if(!exist and ans >= 0) {
            ans = 0;
            break;
        }
        if(!exist) ans = scc[i].size();
    }

    printf("%d\n", ans);
    return 0;
}
