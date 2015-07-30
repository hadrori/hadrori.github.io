#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, M;
vector<pii> edge[10010];
bool used[50010];

void dfs(int p){
    for(int i = 0; i < edge[p].size(); i++){
        int nxt = edge[p][i].first, id = edge[p][i].second;
        if(used[id]) continue;
        used[id] = 1;
        printf("%d\n", nxt+1);
        dfs(nxt);
        printf("%d\n", p+1);
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        edge[a].push_back(pii(b,i));
        edge[b].push_back(pii(a,i));
    }

    printf("1\n");
    dfs(0);
    return 0;
}
