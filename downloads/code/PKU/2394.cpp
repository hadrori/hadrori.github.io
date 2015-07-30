#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
int F, P, C, M;
vector<pii> edge[512];
int pos[128];
int dist[512];

int main(){
    scanf("%d%d%d%d", &F, &P, &C, &M);
    for(int i = 0; i < P; i++){
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        a--; b--;
        edge[a].push_back(pii(b,t));
        edge[b].push_back(pii(a,t));
    }
    
    for(int i = 0; i < C; i++){
        scanf("%d", pos+i);
        pos[i]--;
    }
    
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push(pii(0,0));
    memset(dist, -1, sizeof(dist));
    while(!que.empty()){
        int cst = que.top().first;
        int p = que.top().second;
        que.pop();
        if(dist[p] >= 0) continue;
        dist[p] = cst;
        for(int i = 0; i < edge[p].size(); i++)
            que.push(pii(cst+edge[p][i].second, edge[p][i].first));
    }
    vector<int> ans;
    for(int i = 0; i < C; i++)
        if(dist[pos[i]] <= M && dist[pos[i]] >= 0) ans.push_back(i+1);

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}
