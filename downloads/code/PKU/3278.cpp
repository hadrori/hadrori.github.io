#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int N, K;
int dist[200010];
const int dx[] = {-1,1};
inline bool in(int x){ return x >= 0 && x < 200000;}

int main(){
    scanf("%d%d", &N, &K);
    memset(dist, -1, sizeof(dist));
    dist[N] = 0;
    queue<int> que;
    que.push(N);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        if(pos == K) break;
        for(int i = 0; i < 2; i++)
            if(in(pos + dx[i]) && dist[pos+dx[i]] == -1){
                dist[pos+dx[i]] = dist[pos] + 1;
                que.push(pos+dx[i]);
            }
        if(pos < K && in(pos*2) && dist[pos*2] == -1){
            dist[pos*2] = dist[pos] + 1;
            que.push(pos*2);
        }
    }
    printf("%d\n", dist[K]);
    return 0;
}
