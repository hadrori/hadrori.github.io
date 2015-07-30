#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N, R;
vector<pii> edge[5010];
int cnt[5010];

int main(){
    scanf("%d%d", &N, &R);
    for(int i = 0; i < R; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        edge[a].push_back(pii(c,b));
        edge[b].push_back(pii(c,a));
    }

    priority_queue<pii,vector<pii>, greater<pii> > que;
    que.push(pii(0,0));
    int ans = 0;
    while(!que.empty()){
        int pos = que.top().second;
        int dis = que.top().first;
        que.pop();
        if(cnt[pos] >= 2) continue;
        cnt[pos]++;
        if(pos == N-1) ans = dis;
        for(int i = 0; i < edge[pos].size(); i++)
            que.push(pii(dis+edge[pos][i].first, edge[pos][i].second));
    }
    
    printf("%d\n", ans);
    return 0;
}
