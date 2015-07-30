#include <cstdio>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> pii;

const int inf = 1e9;
int N, ML, MD;
vector<pii> edge[1024];
int dist[1024]; // distance between 0 and i

int solve(){
    for(int cnt = 0; cnt < N; cnt++){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < edge[i].size(); j++)
                if(dist[edge[i][j].first] > dist[i]+edge[i][j].second)
                    dist[edge[i][j].first] = dist[i] + edge[i][j].second;
        if(dist[0] < 0) return -1;
    }
    if(dist[N-1] == inf) return -2;
    return dist[N-1];
}

int main(){
    scanf("%d%d%d", &N, &ML, &MD);
    for(int i = N-1; i > 0; i--){
        edge[i].push_back(pii(i-1, 0));
        dist[i] = inf;
    }
    for(int i = 0; i < ML; i++){
        int a, b, d; scanf("%d%d%d", &a, &b, &d);
        a--; b--;
        edge[a].push_back(pii(b, d));
    }
    for(int i = 0; i < MD; i++){
        int a, b, d; scanf("%d%d%d", &a, &b, &d);
        a--; b--;
        edge[b].push_back(pii(a,-d));
    }
    printf("%d\n", solve());
    return 0;
}
