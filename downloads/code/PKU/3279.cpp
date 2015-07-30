#include <cstdio>
#include <cstring>

using namespace std;

int N, M, ma, sum;
int table[16][16], ttable[16][16];
int ans[16][16], tans[16][16];

void flip(int i, int j){
    ttable[i][j] ^= 1;
    if(i) ttable[i-1][j] ^= 1;
    if(j) ttable[i][j-1] ^= 1;
    if(i<M-1) ttable[i+1][j] ^= 1;
    if(j<N-1) ttable[i][j+1] ^= 1;
}

void copy_table(){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            ttable[i][j] = table[i][j];
}

void flip_one(int S){
    for(int j = N-1; S > 0 and j >= 0; j--, S >>= 1)
        if(S&1) {
            tans[0][j] = 1;
            flip(0, j);
        }
}

bool ok(){
    for(int j = 0; j < N; j++)
        if(ttable[M-1][j]) return 0;
    return 1;
}

bool solve(){
    ma = 10000;
    for(int S = 0; S < (1<<N); S++){
        memset(tans, 0, sizeof(tans));
        sum = __builtin_popcount(S);
        copy_table();
        flip_one(S);
        
        for(int i = 1; i < M; i++)
            for(int j = 0; j < N; j++)
                if(ttable[i-1][j]){
                    tans[i][j] = 1;
                    sum++;
                    flip(i,j);
                }
        if(ok() and sum < ma){
            ma = sum;
            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                    ans[i][j] = tans[i][j];
        }
    }
    return ma < 1000;
}

int main(){
    scanf("%d%d", &M, &N);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &table[i][j]);
    if(solve()){
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++){
                printf("%d", ans[i][j]);
                if(j < N-1) printf(" ");
                else printf("\n");
            }
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}
