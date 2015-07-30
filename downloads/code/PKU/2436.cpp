#include <algorithm>
#include <cstdio>

using namespace std;

int N, D, K;
int cows[1024];

int main(){
    scanf("%d%d%d", &N, &D, &K);
    for(int i = 0; i < N; i++){
        int t; scanf("%d", &t);
        while(t--){
            int d; scanf("%d", &d);
            d--;
            cows[i] |= 1 << d;
        }
    }
    int ans = 0;
    for(int S = 0; S < (1 << D); S++){
        int cnt = 0;
        if(__builtin_popcount(S) <= K)
            for(int i = 0; i < N; i++)
                if((S | cows[i]) == S) cnt++;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
