#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 1e9;
int N;
bool tile[5010], flip[5010];

void solve(){
    int M = inf, K;
    for(int k = 1; k <= N; k++){
        int m = 0;
        bool sum = 0;
        memset(flip, 0, sizeof(flip));
        for(int i = 0; i <= N-k; i++){
            flip[i] = !(sum^tile[i]);
            m += flip[i];
            sum ^= flip[i];
            if(i >= k-1) sum ^= flip[i-k+1];
        }
        for(int i = N-k+1; i < N; i++){
            if(!(sum^tile[i])) m = inf;
            sum ^= flip[i-k+1];
        }        
        if(M > m){
            M = m;
            K = k;
        }
    }
    printf("%d %d\n", K, M);
}

int main(){
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++){
        char c; scanf("%c\n", &c);
        tile[i] = (c == 'F');
    }
    solve();
    return 0;
}
