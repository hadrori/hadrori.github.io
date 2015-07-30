#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int N, M, X;
int dist[1024][1024];
vector<pii> edge[1024];

int main(){
    scanf("%d%d%d", &N, &M, &X);
    --X;
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[--a].push_back(pii(--b, c));
    }

    for(int s = 0; s < N; s++){
        priority_queue<pii, vector<pii>, greater<pii> > que;
        que.push(pii(0, s));
        bool visited[1024] = {};
        while(!que.empty()){
            int cst = que.top().first;
            int pos = que.top().second;
            que.pop();
            if(visited[pos]) continue;
            dist[s][pos] = cst;
            if(s != X && pos == X) break;

            visited[pos] = 1;
            for(int i = 0; i < edge[pos].size(); i++)
                que.push(pii(cst+edge[pos][i].second, edge[pos][i].first));
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, dist[i][X]+dist[X][i]);
    printf("%d\n", ans);
    return 0;
}
