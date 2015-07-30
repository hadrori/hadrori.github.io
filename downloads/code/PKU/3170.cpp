#include <cstdio>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int W, H, ans;
int table[1024][1024];
pii s, t;
int fromS[1024][1024];
int toT[1024][1024];

inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < H && j < W;}

int main(){
    scanf("%d%d", &W, &H);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++){
            scanf("%d", &table[i][j]);
            if(table[i][j] == 2) s = pii(i, j);
            else if(table[i][j] == 3) t = pii(i, j);
        }
    queue<pair<pii,int> > bfs;
    bfs.push(make_pair(s, 0));
    memset(fromS, -1, sizeof(fromS));
    while(!bfs.empty()){
        int i = bfs.front().first.first;
        int j = bfs.front().first.second;
        int dist = bfs.front().second;
        bfs.pop();
        if(fromS[i][j] >= 0) continue;
        fromS[i][j] = dist;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(in(ni, nj) && table[ni][nj] != 1)
                bfs.push(make_pair(pii(ni,nj), dist+1));
        }
    }
    ans = 1000000000;
    bfs.push(make_pair(t, 0));
    memset(toT, -1, sizeof(toT));
    while(!bfs.empty()){
        int i = bfs.front().first.first;
        int j = bfs.front().first.second;
        int dist = bfs.front().second;
        bfs.pop();
        if(toT[i][j] >= 0) continue;
        toT[i][j] = dist;
        if(table[i][j] == 4) ans = min(ans, fromS[i][j] + toT[i][j]);
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(in(ni, nj) && table[ni][nj] != 1)
                bfs.push(make_pair(pii(ni,nj), dist+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}
