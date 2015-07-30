#include <algorithm>
#include <cstdio>

using namespace std;

struct S{
    int s, t, e;
    S(){}
    S(int s, int t, int e):s(s),t(t),e(e){}
    bool operator<(const S &a) const{ return s < a.s;}
};

int N, M, R;
S inter[1024];
int dp[1024];

int main(){
    scanf("%d%d%d", &N, &M, &R);
    N += R;
    for(int i = 0; i < M; i++){
        int s, t, e; scanf("%d%d%d", &s, &t, &e);
        inter[i] = S(s,t+R,e);
    }
    sort(inter, inter+M);

    int ans = 0;
    for(int i = 0; i < M; i++){
        dp[i] = inter[i].e;
        for(int j = 0; j < i; j++)
            if(inter[i].s >= inter[j].t)
                dp[i] = max(dp[i], dp[j]+inter[i].e);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
