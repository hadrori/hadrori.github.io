#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int N, price[5010];
int dp1[5010], dp2[5010];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", price + i);
        dp1[i] = dp2[i] = 1;
    }
    int len = 1;
    for(int i = N-1; i >= 0; i--){
        int mlen = 1, sum = 1;
        for(int j = i+1; j < N; j++)
            if(price[j] < price[i]){
                if(dp1[j] + 1 > mlen) {
                    mlen = dp1[j] + 1;
                    sum = dp2[j];
                }
                else if(dp1[j] + 1 == mlen) sum += dp2[j];
            }
            else if(price[i] == price[j])
                dp1[j] = dp2[j] = 0;
        dp1[i] = mlen;
        dp2[i] = sum;
        len = max(len, mlen);
    }
    int cnt = 0;
    for(int i = 0; i < N; i++)
        if(dp1[i] == len)
            cnt += dp2[i];
    printf("%d %d\n", len, cnt);
    return 0;
}
