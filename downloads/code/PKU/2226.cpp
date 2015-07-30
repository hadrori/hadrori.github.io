#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int inf = 1e9;
int R, C, base;
bool table[64][64];
inline bool in(int i, int j){ return i >= 0 and i < R and j >= 0 and j < C;}
vector<int> G[5010];
int match[5010], used[5010];
void add_edge(int from, int to){
    G[from].push_back(to);
    G[to].push_back(from);
}
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
    for(int v = 0; v < 2*R*C; v++){
        if(match[v] < 0){
            memset(used, 0, sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &R, &C);
    base = R*C;
    for(int i = 0; i < R; i++){
        char c; scanf("%c", &c);
        for(int j = 0; j < C; j++){
            scanf("%c", &c);
            table[i][j] = (c =='*');
        }
    }
            
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(table[i][j]){
                int nj = j, ni = i;
                while(in(ni, j) and table[ni][j]) ni++;
                while(in(i, nj) and table[i][nj]) nj++;
                ni--; nj--;
                add_edge(i*C+nj, base+ni*C+j);
            }
    printf("%d\n", b_match());
    return 0;
}
