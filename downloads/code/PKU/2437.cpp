#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, L;
pii mud[10010];

int main(){
    scanf("%d%d", &N, &L);
    for(int i = 0; i < N; i++){
        int s, t;
        scanf("%d%d", &s, &t);
        mud[i] = pii(s,t);
    }
    sort(mud, mud+N);
    int tail = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(tail >= mud[i].second) continue;
        tail = max(mud[i].first, tail);
        int res = mud[i].second - tail;
        int num = res / L;
        if(res % L) num++;
        tail += num * L;
        ans += num;
    }
    printf("%d\n", ans);
    return 0;
}
