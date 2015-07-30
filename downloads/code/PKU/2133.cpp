#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int B, E, goal;
int bin[128];
int dist[150000];

int main(){
    scanf("%d%d", &B, &E);
    char c; scanf("%c", &c);
    for(int i = 0; i < B; i++){
        scanf("%c", &c);
        goal <<= 1;
        goal += c-'0';
    }
    scanf("%c", &c);
    
    for(int i = 0; i < E; i++){
        for(int j = 0; j < B; j++){
            scanf("%c", &c);
            bin[i] <<= 1;
            bin[i] += c-'0';
        }
        scanf("%c", &c);
    }
    memset(dist,-1,sizeof(dist));
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        if(now == goal && dist[now] >= 0) break;
        for(int i = 0; i < E; i++){
            int next = now ^ bin[i];
            if(dist[next] >= 0) continue;
            que.push(next);
            dist[next] = dist[now]+1;
        }
    }
    for(int i = 0; i < E; i++)
        dist[bin[i]] = 2 - (dist[0]==0);
    int ans, dif = 128;
    for(int i = 0; i < 1<<B; i++)
        if(dist[i] >= 0){
            int cnt = __builtin_popcount(i^goal);
            if(cnt < dif){
                ans = i;
                dif = cnt;
            }
            else if(cnt == dif && dist[i] < dist[ans]) ans = i;
        }

    printf("%d\n", dist[ans]);
    for(int i = B-1; i >= 0; i--)
        printf("%d", 1&(ans>>i));
    printf("\n");
    return 0;
}
