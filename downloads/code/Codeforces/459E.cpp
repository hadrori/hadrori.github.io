#include <bits/stdc++.h>
using namespace std;

struct edge
{
        int w, u, v;;
        edge(){}
        edge(int w, int u, int v):w(w),u(u),v(v){}
        bool operator<(const edge &e)const{ return w < e.w;}
};

int n, m, dp[300010][2], pw[300010];
vector<edge> E;

void update(int v, int w){
        if(pw[v] >= w) return;
        dp[v][1] = max(dp[v][1], dp[v][0]);
        dp[v][0] = 0;
        pw[v] = w;
}

int solve()
{
        sort(begin(E),end(E));
        for(auto &e: E) {
                update(e.u, e.w);
                update(e.v, e.w);
                dp[e.v][0] = max(dp[e.v][0], dp[e.u][1]+1);
        }
        int ret = 0;
        for (int i = 0; i < n; i++)
                ret = max(ret, max(dp[i][0], dp[i][1]));

        return ret;
}

void input()
{
        scanf("%d%d", &n, &m);
        int u, v, w;
        for (int i = 0; i < m; i++) {
                scanf("%d%d%d", &u, &v, &w);
                E.push_back(edge(w,u-1,v-1));
        }
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
