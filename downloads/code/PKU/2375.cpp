#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,1,-1};
int W, L, H[512][512];
bool done[512][512];

inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < L && j < W;}

int par[512*512];
int height[512*512];

void init(){ for(int i = 0; i < L*W; i++){ par[i] = i; height[i] = 0;}}

int find(int x){ if(par[x] == x) return x; else return par[x] = find(par[x]);}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(height[x] < height[y]) par[x] = y;
    else { par[y] = x; if(height[x] == height[y]) height[x]++;}
}

void unite_level(int i, int j, int h, int s){
    if(done[i][j]) return;
    done[i][j] = 1;
    unite(s, i*W+j);
    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni, nj) && H[ni][nj] == h) unite_level(ni, nj, h, s);
    }
}

int dfs(int i, int j){
    if(done[i][j]) return 0;
    done[i][j] = 1;
    int ret = 0, h = H[i][j];
    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni, nj)){
            if(H[ni][nj] == h) ret |= dfs(ni, nj);
            else if(H[ni][nj] < h) ret |= 1;
            else ret |= 2;
        }
    }
    return ret;
}

int main(){
    scanf("%d%d", &W, &L);
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++)
            scanf("%d", &H[i][j]);

    init();
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++)
            if(!done[i][j]) unite_level(i, j, H[i][j], i*W+j);

    memset(done, 0, sizeof(done));
    int top = 0, bottom = 0;
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++)
            if(!done[i][j]){
                int t = dfs(i, j);
                if(t == 1) top++;
                else if(t == 2) bottom++;
            }

    printf("%d\n", max(top, bottom));
    return 0;
}
