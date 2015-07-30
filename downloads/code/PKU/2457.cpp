#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, K;
vector<int> edge[1024];
int dist[1024];
int from[1024];

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
    }
    queue<pii> bfs;
    bfs.push(pii(1,0));
    while(!bfs.empty()){
        int pos = bfs.front().first;
        int ppos = bfs.front().second;
        bfs.pop();
        if(dist[pos] > 0) continue;
        dist[pos] = dist[ppos] + 1;
        from[pos] = ppos;
        for(int i = 0; i < edge[pos].size(); i++)
            bfs.push(pii(edge[pos][i], pos));
    }
    if(dist[K] == 0){
        puts("-1");
        return 0;
    }
    vector<int> ans;
    int cur = K;
    while(cur != 0){
        ans.push_back(cur);
        cur = from[cur];
    }
    printf("%d\n", (int)ans.size());
    for(int i = ans.size()-1; i >= 0; i--)
        printf("%d\n", ans[i]);
    return 0;
}
