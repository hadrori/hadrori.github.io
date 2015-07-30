#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
typedef pair<int,int> pii;
int N, M;
pii dem[100010], shp[100010];
multiset<int> C;

int solve(){
    int ret = 0, j = M-1;
    for(int i = N-1; i >= 0; i--){
        while(j >= 0 and dem[i].first <= shp[j].first)
            C.insert(shp[j--].second);
        multiset<int>::iterator itr = C.lower_bound(dem[i].second);
        if(itr == C.end()) return -1LL;
        ret += *itr;
        C.erase(itr);
    }
    return ret;
}

signed main(){
    scanf("%lld%lld", &N, &M);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%lld%lld", &a, &b);
        dem[i] = pii(b, a);
    }
    sort(dem, dem+N);
    for(int i = 0; i < M; i++){
        int c, d;
        scanf("%lld%lld", &c, &d);
        shp[i] = pii(d, c);
    }
    sort(shp, shp+M);
    printf("%lld\n", solve());
    return 0;
}
