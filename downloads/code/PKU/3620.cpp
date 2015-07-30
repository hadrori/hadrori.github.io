#include <algorithm>
#include <cstdio>

using namespace std;

int h, w, K;
bool rect[128][128];
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

inline bool in(int x, int y){ return x >= 0 && x < w && y >= 0 && y < h;}

int dfs(int x, int y){
    rect[x][y] = 0;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(in(nx, ny) && rect[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

int main(){
    scanf("%d%d%d", &w, &h, &K);
    for(int i = 0; i < K; i++){
        int x, y; scanf("%d%d", &x, &y);
        rect[x-1][y-1] = 1;
    }
    int ans = 0;
    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            if(rect[x][y]) ans = max(ans, dfs(x, y));
    printf("%d\n", ans);
    return 0;
}
