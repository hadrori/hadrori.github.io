#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, A;
int dp[64][65536];

bool rec(int i,int j){
    if(dp[i][j] >= 0) return dp[i][j];
    if(j == 1) return dp[i][j] = rec(i+1,0);
    dp[i][j] = 0;
    if(i) dp[i][j] |= !rec(i-1,j);
    if(j) dp[i][j] |= !rec(i,j-1);
    if(i && j) dp[i][j] |= !rec(i-1,j+1);
    if(i >= 2) dp[i][j] |= !rec(i-2,j+2+(j>0));
    return dp[i][j];
}

int main(){
    int T;
    memset(dp,-1,sizeof(dp));
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d",&N);
        int a = 0, b = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &A);
            if(A == 1) a++;
            else b += A + 1;
        }
        printf("Case #%d: ", i);
        if(rec(a,max(0,b-1))) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
