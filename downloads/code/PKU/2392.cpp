#include <algorithm>
#include <cstdio>

using namespace std;

struct S{
    int h, a, c;
    S(){}
    S(int h, int a, int c):h(h),a(a),c(c){}
    bool operator<(const S &s) const{ return a < s.a;}
};

int K;
int h, a, c;
S block[512];
bool dp[40000];

int main(){
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d%d%d", &h, &a, &c);
        block[i] = S(h, a, c);
    }
    sort(block, block+K);

    dp[0] = 1;
    for(int i = 0; i < K; i++){
        for(int k = 1; k <= block[i].c; k++)
            for(int j = block[i].a; j >= block[i].h; j--)
                dp[j] |= dp[j-block[i].h];
    }
    int ans = 0;
    for(int i = block[K-1].a; i >= 0; i--)
        if(dp[i]) {
            ans = i;
            break;
        }
    printf("%d\n", ans);
    return 0;
}
