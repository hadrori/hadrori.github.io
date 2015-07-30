#include <cstdio>
#include <algorithm>

using namespace std;

#define int long long
struct cow{
    int t, d;
    cow(){}
    cow(int t, int d):t(t),d(d){}
    bool operator<(const cow &c)const{ return c.t*d > t*c.d;}
};

int N, dest;
cow C[100010];

signed main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; i++){
        int t, d; scanf("%lld%lld", &t, &d);
        C[i] = cow(t, d);
        dest += d;
    }
    sort(C, C+N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        dest -= C[i].d;
        ans += 2*dest*C[i].t;
    }
    printf("%lld\n", ans);
    return 0;
}
