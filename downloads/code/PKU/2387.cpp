#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int T, N;
int way[1024][1024];
vector<int> edge[1024];
bool visited[1024];


int main(){
    scanf("%d%d", &T, &N);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            way[i][j] = 1e9;
    for(int i = 0; i < T; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        if(way[a][b] == 1e9){
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        way[a][b] = way[b][a] = min(way[a][b], c);
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > que;
    que.push(make_pair(0,0));
    while(!que.empty()){
        pair<int,int> p = que.top(); que.pop();
        int from = p.second, dist = p.first;
        if(visited[from]) continue;
        visited[from] = 1;
        if(from == N-1){
            printf("%d\n", dist);
            break;
        }
        for(int i = 0; i < edge[from].size(); i++)
            que.push(make_pair(dist+way[from][edge[from][i]], edge[from][i]));
    }
    
    return 0;
}
