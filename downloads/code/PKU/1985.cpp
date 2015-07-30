#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int N, M;

bool done[40010];
vector<pii> edge[40010];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, c; char d;
        scanf("%d %d %d %c", &a, &b, &c, &d);
        a--; b--;
        edge[a].push_back(pii(c,b));
        edge[b].push_back(pii(c,a));
    }


    priority_queue<pii> que;
    que.push(pii(0,0));
    memset(done, 0, sizeof(done));
    int dis = 0, a = 0;
    while(!que.empty()){
        int dist = que.top().first;
        int pos = que.top().second;
        que.pop();
        if(done[pos]) continue;
        done[pos] = 1;
        if(dis < dist){
            dis = dist;
            a = pos;
        }
        for(int i = 0; i < edge[pos].size(); i++)
            que.push(pii(dist+edge[pos][i].first, edge[pos][i].second));
    }

    que.push(pii(0,a));
    memset(done, 0, sizeof(done));
    int ans = 0;
    while(!que.empty()){
        int dist = que.top().first;
        int pos = que.top().second;
        que.pop();
        if(done[pos]) continue;
        done[pos] = 1;
        ans = max(ans, dist);
        for(int i = 0; i < edge[pos].size(); i++)
            que.push(pii(dist+edge[pos][i].first, edge[pos][i].second));
    }

    printf("%d\n", ans);
    return 0;
}
