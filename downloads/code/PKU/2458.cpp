#include <cstdio>
#include <set>

using namespace std;

const int N = 5;
const int M = 7;
const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};
inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < N && j < N;}

char table[8][8];
set<int> done;
int ans;

int seq[8];

void dfs(int k, int cnt, int S){
    if(done.count(S)) return;
    done.insert(S);
    if(cnt >= 4) return;
    if(k == M){
        ans++;
        return;
    }
    for(int p = 0; p < k; p++){
        int i = seq[p]/N, j = seq[p]%N;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(in(ni,nj) && !(S&(1<<(ni*N+nj)))){
                seq[k] = ni*N+nj;
                dfs(k+1, cnt+(table[ni][nj]=='H'), S|(1<<(ni*N+nj)));
            }
        }
    }
}

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%c", &table[i][j]);
        scanf("%c", &table[i][N]);
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            seq[0] = i*N+j;
            dfs(1,table[i][j]=='H',1<<(i*N+j));
        }
    printf("%d\n", ans);
    return 0;
}
