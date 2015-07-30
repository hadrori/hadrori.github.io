#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int C, L;
int used[2510];
pii cows[2510], loti[2510];

int main(){
    scanf("%d%d", &C, &L);

    for(int i = 0; i < C; i++){
        int l, u; scanf("%d%d", &l, &u);
        cows[i] = pii(l,u);
    }
    sort(cows, cows+C);

    for(int i = 0; i < L; i++){
        int s, n; scanf("%d%d", &s, &n);
        loti[i] = pii(s, n);
    }
    sort(loti, loti+L);

    int ans = 0;
    for(int i = 0; i < L; i++){
        int spf = loti[i].first, res = loti[i].second, cnt = 0;
        pii cand[2510];
        for(int j = 0; j < C; j++){
            if(used[j]) continue;
            if(cows[j].first > spf) break;
            if(cows[j].first <= spf and spf <= cows[j].second) cand[cnt++] = pii(cows[j].second, j);
        }
        sort(cand, cand+cnt);
        ans += min(cnt, res);
        for(int j = 0; j < min(cnt, res); j++)
            used[cand[j].second] = 1;
    }

    printf("%d\n", ans);
    return 0;
}
