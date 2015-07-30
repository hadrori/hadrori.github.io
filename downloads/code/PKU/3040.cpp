#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int inf = 1e9;
int N, C;
pii coin[32];

int main(){
    scanf("%d%d", &N, &C);
    int cnt = 0, ans = 0;
    for(int i = 0; i < N; i++){
        int v, b;
        scanf("%d%d", &v, &b);
        if(v >= C) ans += b;
        else coin[cnt++] = pii(-v, b);
    }
    N = cnt;
    sort(coin, coin+N);
    while(1){
        int res = C;
        int need[32] = {};
        for(int i = 0; i < N; i++)
            if(res >= -coin[i].first and coin[i].second > need[i]){
                need[i] = min(coin[i].second, -res/coin[i].first);
                res += need[i]*coin[i].first;
            }
        if(res > 0)
            for(int i = N-1; i >= 0; i--)
                if(res > 0 and coin[i].second >= need[i]){
                    int tmp = min(coin[i].second-need[i], -(res-coin[i].first-1)/coin[i].first);
                    need[i] += tmp;
                    res += tmp*coin[i].first;
                }
        if(res > 0) break;
        int use = inf;
        for(int i = 0; i < N; i++)
            if(need[i]) use = min(use, coin[i].second/need[i]);
        for(int i = 0; i < N; i++)
            coin[i].second -= use*need[i];
        ans += use;
    }
    printf("%d\n", ans);
    return 0;
}
