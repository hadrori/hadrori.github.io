#include <algorithm>
#include <cstdio>

#define int long long
using namespace std;

struct cow{
    int s, t, v;
    cow(){}
    cow(int s, int t, int v):s(s),t(t),v(v){}
    bool operator<(const cow &c)const{ return s < c.s;}
};

const int inf = 1e16;
int N, M, E, MA;
cow C[10010];

struct ST{
    int dp[300010];
    ST(){
        for(int i = 0; i < 2*MA-1; i++)
            dp[i] = inf;
    }
    void update(int k, int val){
        k += MA-1;
        dp[k] = val;
        while(k > 0){
            k = (k-1) / 2;
            dp[k] = min(dp[2*k+1], dp[2*k+2]);
        }
    }
    int query(int a, int b){ return query(a, b, 0, 0, MA);}
    int query(int a, int b, int k, int l, int r){
        if(a >= r or b <= l) return inf;
        if(a <= l and r <= b) return dp[k];
        int m = (l + r) / 2;
        return min(query(a,b,2*k+1,l,m), query(a,b,2*k+2,m,r));
    }
};

signed main(){
    scanf("%lld%lld%lld", &N, &M, &E);
    E -= M-1;
    for(int i = 0; i < N; i++){
        int s, t, v; scanf("%lld%lld%lld", &s, &t, &v);
        C[i] = cow(s-M, t-M+1, v);
    }
    //    printf("%lld %lld %lld\n", N, M, E);
    sort(C, C+N);
    MA = 1LL;
    while(E > MA) MA <<= 1LL;
    ST st = ST();
    st.update(0,0);
    for(int i = 0; i < N; i++)
        st.update(C[i].t, min(st.dp[C[i].t+MA-1], st.query(C[i].s, C[i].t) + C[i].v));

    int ans = st.dp[E+MA-1];
    if(ans == inf) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
