#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> G[1024];
int N, K;
int match[1024], used[1024];

bool dfs(int v){
    used[v] = 1;
    for(int i = 0; i < G[v].size(); i++){
        int u = G[v][i], w = match[u];
        if(w < 0 or !used[w] and dfs(w)){
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}
int b_match(){
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < 2*N; v++){
        if(match[v] < 0){
            memset(used, 0, sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < K; i++){
        int r, c; scanf("%d%d", &r, &c);
        r--; c--;
        G[r].push_back(N+c);
        G[N+c].push_back(r);
    }
    printf("%d\n", b_match());
    return 0;
}
