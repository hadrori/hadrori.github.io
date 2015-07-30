#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <vector>

#define myuni(u) (u).erase(unique((u).begin(), (u).end()), (u).end())

using namespace std;

typedef pair<int,int> pii;

const int inf = int(1e9);
int N, M;
int G[310][310];

int main(){
    scanf("%d%d", &N, &M);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            G[i][j] = inf;
    
    for(int i = 0; i < M; i++){
        int t; scanf("%d", &t);
        int tmp[310];
        for(int j = 0; j < t; j++){
            scanf("%d", tmp+j);
            tmp[j]--;
        }
        for(int j = 0; j < t; j++)
            for(int k = j+1; k < t; k++){
                G[tmp[j]][tmp[k]] = 1;
                G[tmp[k]][tmp[j]] = 1;
            }
    }
    int ans = inf;
    for(int s = 0; s < N; s++){
        bool visited[310] = {0};
        priority_queue<pii, vector<pii>, greater<pii> > que;
        que.push(pii(0,s));
        int av = 0;
        while(!que.empty()){
            int cst = que.top().first;
            int pos = que.top().second;
            que.pop();
            if(visited[pos]) continue;
            av += cst;
            visited[pos] = 1;
            for(int i = 0; i < N; i++)
                if(G[pos][i] != inf) que.push(pii(cst+1,i));
        }
        ans = min(ans, int(100. * av / (N-1)));
    }
    printf("%d\n", ans);
    return 0;
}
