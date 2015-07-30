#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int inf = int(1e9);
const int MAX = 310;
const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};

inline bool in(int x, int y){ return x >= 0 && y >= 0 && x < MAX && y < MAX;}

struct point{
    int x, y, t;
    point(){}
    point(int x, int y, int t):x(x),y(y),t(t){}
    bool operator<(const point &m)const{ return t < m.t;}
};

int M;
int field[MAX][MAX];
point meteor[50010];

int main(){
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        meteor[i] = point(x, y, t);
    }
    sort(meteor, meteor+M);
    memset(field, -1, sizeof(field));
    queue<point> bfs;
    int mcnt = 0;
    bfs.push(point(0,0,0));
    while(!bfs.empty()){
        point p = bfs.front(); bfs.pop();
        while(mcnt < M && meteor[mcnt].t <= p.t){
            for(int i = 0; i < 5; i++){
                int nx = meteor[mcnt].x + dx[i], ny = meteor[mcnt].y + dy[i];
                if(in(nx, ny)) field[nx][ny] = inf;
            }
            mcnt++;
        }
        if(field[p.x][p.y] >= 0) continue;
        field[p.x][p.y] = p.t;
        for(int i = 0; i < 4; i++){
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if(in(nx, ny)) bfs.push(point(nx, ny, p.t+1));
        }
    }
    while(mcnt < M){
        for(int i = 0; i < 5; i++){
            int nx = meteor[mcnt].x + dx[i], ny = meteor[mcnt].y + dy[i];
            if(in(nx, ny)) field[nx][ny] = inf;
        }
        mcnt++;
    }
    int ans = inf;
    for(int x = 0; x < MAX; x++)
        for(int y = 0; y < MAX; y++)
            if(field[x][y] >= 0)
                ans = min(ans, field[x][y]);
    if(ans == inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}
