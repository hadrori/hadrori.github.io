#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int,int> pii;
struct S{
    int i, j, h;
    S(){}
    S(int i, int j, int h):i(i),j(j),h(h){}
    bool operator<(const S &s) const{ return h < s.h;}
};

const int di[] = {1,2,1,2,-1,-2,-1,-2};
const int dj[] = {2,1,-2,-1,2,1,-2,-1};
int N;
int num[512][512];
int memo[512][512];
pii from[512][512];

inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < N && j < N;}

int rec(int i, int j){
    if(memo[i][j] >= 0) return memo[i][j];
    int ret = 1, cnt = 0;
    S srt[8];
    for(int d = 0; d < 8; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni,nj) && num[i][j] < num[ni][nj])
            srt[cnt++] = S(ni,nj,num[ni][nj]);
    }
    sort(srt, srt+cnt);
    for(int k = 0; k < cnt; k++){
        int ni = srt[k].i, nj = srt[k].j;
        int tmp = rec(ni,nj);
        if(tmp+1 > ret){
            ret = tmp+1;
            from[i][j] = pii(ni,nj);
        }
    }
    return memo[i][j] = ret;
}

int main(){
    scanf("%d", &N);
    S srt[200000];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &num[i][j]);
            srt[i*N+j] = S(i,j,num[i][j]);
        }
    sort(srt,srt+N*N);
    memset(memo,-1,sizeof(memo));
    int ans = -1;
    pii s;
    for(int k = 0; k < N*N; k++){
        int ni = srt[k].i, nj = srt[k].j;
        rec(ni,nj);
        if(ans < memo[ni][nj]){
            ans = memo[ni][nj];
            s = pii(ni,nj);
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++){
        printf("%d\n", num[s.first][s.second]);
        s = from[s.first][s.second];
    }
    return 0;
}
