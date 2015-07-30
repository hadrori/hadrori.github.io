#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N, M, W;
vector<pii> edge[512];
int dist[512];

int main(){
    int F;
    scanf("%d", &F);
    while(F--){
        scanf("%d%d%d", &N, &M, &W);
        for(int i = 0; i < N; i++) edge[i].clear();

        for(int i = 0; i < M; i++){
            int a, b, t;
            scanf("%d%d%d", &a, &b, &t);
            a--; b--;
            edge[a].push_back(pii(t,b));
            edge[b].push_back(pii(t,a));
        }
        for(int i = 0; i < W; i++){
            int a, b, t;
            scanf("%d%d%d", &a, &b, &t);
            a--; b--;
            edge[a].push_back(pii(-t,b));
        }

        bool ok = false;
        for(int i = 0; i < N; i++) dist[i] = int(1e9);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < edge[j].size(); k++){
                    int to = edge[j][k].second;
                    if(dist[to] > dist[j] + edge[j][k].first){
                        dist[to] = dist[j] + edge[j][k].first;
                        if(i == N-1){
                            ok = 1;
                            goto end;
                        }
                    }
                }
    end:
        if(ok) puts("YES");
        else puts("NO");
    }
}
