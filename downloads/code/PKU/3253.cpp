#include <queue>
#include <cstdio>

using namespace std;
#define int long long

int N, L;
signed main(){
    scanf("%lld", &N);
    priority_queue<int> que;
    for(int i = 0; i < N; i++){
        scanf("%lld", &L);
        que.push(-L);
    }
    int ans = 0;
    while(que.size() > 1){
        int l = -que.top(); que.pop();
        l -= que.top(); que.pop();
        ans += l;
        que.push(-l);
    }
    printf("%lld\n", ans);
    return 0;
}
