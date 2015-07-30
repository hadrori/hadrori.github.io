#include <cstdio>
#include <map>
#include <queue>

using namespace std;

const int MAX = 1024;
const int base = 512;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

bool mud[MAX][MAX];
int dist[MAX][MAX];
int N, X, Y;

inline bool in(int x, int y) { return x >= 0 && x < MAX && y >= 0 && y < MAX;}

int main(){
    scanf("%d%d%d", &X, &Y, &N);
    X += base; Y += base;
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dist[i][j] = 1e9;
    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        mud[x+base][y+base] = 1;
    }
    queue<pair<int,int> > bfs;
    bfs.push(make_pair(base,base));
    dist[base][base] = 0;
    while(!bfs.empty()){
        int x = bfs.front().first, y = bfs.front().second;
        bfs.pop();
        if(x == X && y == Y) break;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(in(nx, ny) && !mud[nx][ny] && dist[nx][ny] == 1e9){
                dist[nx][ny] = dist[x][y] + 1;
                bfs.push(make_pair(nx,ny));
            }
        }
    }
    printf("%d\n", dist[X][Y]);
    return 0;
}
