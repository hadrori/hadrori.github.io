#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

#define int long long

using namespace std;

typedef pair<int,int> pii;

int N, bit[2][20010];
pii cow[20010];

void add(int i, int x, int m){
    while(i <= 20000){
        bit[m][i] += x;
        i += i & -i;
    }
}

int sum(int i, int m){
    int ret = 0;
    while(i > 0){
        ret += bit[m][i];
        i -= i & -i;
    }
    return ret;
}

signed main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; i++){
        int v, x; scanf("%lld%lld", &v, &x);
        cow[i] = pii(v,x);
    }
    sort(cow, cow+N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        int lc = sum(cow[i].second, 0), ld = sum(cow[i].second, 1);
        int rc = sum(20000, 0) - lc, rd = sum(20000, 1) - ld;
        ans += cow[i].first * (cow[i].second*lc - ld + rd - cow[i].second*rc);
        add(cow[i].second, 1, 0);
        add(cow[i].second, cow[i].second, 1);
    }
    printf("%lld\n", ans);
    return 0;
}
