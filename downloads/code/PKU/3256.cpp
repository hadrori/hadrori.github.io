#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int K, N, M, k, ans;
bool pos[1024];
vector<int> edge[1024];

int main(){
    scanf("%d%d%d", &K, &N, &M);
    k = K;
    for(int i = 0; i < K; i++){
        int t;
        scanf("%d", &t);
        if(pos[t]) k--;
        pos[t] = 1;
    }
    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edge[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        bool visited[1024] = {0};
        queue<int> que;
        que.push(i);
        int cnt = 0;
        while(!que.empty()){
            int p = que.front(); que.pop();
            if(visited[p]) continue;
            visited[p] = 1;
            if(pos[p]) cnt++;
            for(int i = 0; i < edge[p].size(); i++)
                que.push(edge[p][i]);
        }
        if(cnt == k) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
