#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int N, M;
vector<pii> edge[2048];
bool visited[2048];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        a--; b--;
        edge[a].push_back(pii(b,l));
        edge[b].push_back(pii(a,l));
    }
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push(pii(0,0));

    int ans = 0;
    while(!que.empty()){
        int l = que.top().first;
        int pos = que.top().second;
        que.pop();
        if(visited[pos]) continue;
        visited[pos] = 1;
        ans = max(ans, l);
        for(int i = 0; i < edge[pos].size(); i++)
            que.push(pii(max(l, edge[pos][i].second), edge[pos][i].first));
    }
    
    printf("%d\n", ans);
    return 0;
}
