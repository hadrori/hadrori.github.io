#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct S{
    int i, j, h;
    S(int i, int j, int h):i(i),j(j),h(h){}
    bool operator<(const S &s) const{ return h > s.h;}
};

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};
int N, ans;
int field[128][128];
int low[128][128];

inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < N && j < N;}

#include <iostream>

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &field[i][j]);
    ans = 128;
    for(int t = min(field[0][0], field[N-1][N-1]); t >= 0; t--){
        priority_queue<S> que;
        que.push(S(0,0,field[0][0]));
        memset(low, -1, sizeof(low));
        while(!que.empty()){
            S s = que.top(); que.pop();
            if(low[s.i][s.j] >= 0) continue;
            low[s.i][s.j] = s.h;
            for(int d = 0; d < 4; d++){
                int ni = s.i + di[d], nj = s.j + dj[d];
                if(in(ni,nj) && field[ni][nj] >= t)
                    que.push(S(ni,nj,max(s.h, field[ni][nj])));
            }
        }
        if(low[N-1][N-1] >= 0) ans = min(ans, low[N-1][N-1]-t);
    }
    printf("%d\n", ans);
    return 0;
}
