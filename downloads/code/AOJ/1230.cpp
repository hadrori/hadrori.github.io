#include <cstdio>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

int n, S;
int M[21];

int main(){
    while(scanf("%d", &n), n){
        scanf("%d", &S);
        rep(i,2*n) scanf("%d", M+i);
        int dp[21][(1<<13)+1] = {-1};
        repi(j, 1, S+1)
            rep(i, 2*n)
                if(j == 1) dp[i][j] = 0;
                else{
                    repi(k, 1, M[i]+1)
                        if(j - k < 1) break;
                        else if(dp[(i+1)%(2*n)][j-k] == 0)
                            dp[i][j] = 1;
                    if(dp[i][j] == -1) dp[i][j] = 0;
                }
        printf("%d\n", dp[0][S]);
    }
    return 0;
}
