#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

#define int long long
using namespace std;
struct S{
    int i, j, c;
    S(){}
    S(int i, int j, int c):i(i),j(j),c(c){}
    bool operator<(const S &s)const{ return c > s.c;}
};

const int inf = 1e10;
const int di[] = {0,0,-1,1};
const int dj[] = {-1,1,0,0};
int W, H;
int bowl[310][310];
int cap[310][310];

inline bool in(int i, int j){ return i >= 0 and i < H and j >= 0 and j < W;}

signed main(){
    scanf("%lld%lld", &W, &H);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf("%lld", &bowl[i][j]);
    priority_queue<S> que;
    memset(cap, -1, sizeof(cap));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < W; j++)
            que.push(S(i*(H-1), j, bowl[i*(H-1)][j]));
    for(int j = 0; j < 2; j++)
        for(int i = 0; i < H; i++)
            que.push(S(i, j*(W-1), bowl[i][j*(W-1)]));
    int ans = 0;
    while(!que.empty()){
        int i = que.top().i, j = que.top().j, c = que.top().c;
        que.pop();
        if(cap[i][j] >= 0) continue;
        cap[i][j] = c;
        ans += c - bowl[i][j];
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(in(ni,nj)) que.push(S(ni, nj, max(c, bowl[ni][nj])));
        }
    }
    printf("%lld\n", ans);
    return 0;
}
