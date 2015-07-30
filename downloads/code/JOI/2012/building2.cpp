#include <bits/stdc++.h>
using namespace std;
inline void chmax(int &a, int b){ a=max(a,b);}
inline void chmin(int &a, int b){ a=min(a,b);}
 
int n, h[1<<17];
vector<int> G[1<<17], dp[2][1<<17];
 
void merge_vec(vector<int> &a, vector<int> &b)
{
        if(a.size() < b.size()) swap(a,b);
        for (auto i = a.begin(), j = b.begin(); j != b.end(); i++, j++) chmin(*i, *j);
        b.clear();
}
 
int update(vector<int> &a, vector<int> &b, int l)
{
        if(a.size() < b.size()) swap(a,b);
        else l = -l;
        int ret = 0, len = 1;
        for(auto &x: b) {
                int k = lower_bound(begin(a),end(a),-x)-begin(a);
                chmax(ret, len+k);
                if(x < l) {
                        k = lower_bound(begin(a),end(a),-l)-begin(a);
                        chmax(ret,len+k+1);
                }
                len++;
        }
        if(l > 0) swap(a,b);
        return ret;
}
 
int dfs(int v, int u)
{
        int ret = 0; 
        for(auto &w: G[v]) {
                if(w == u) continue;
                chmax(ret, dfs(w,v));
                chmax(ret, update(dp[0][v], dp[1][w], h[v]));
                chmax(ret, update(dp[0][w], dp[1][v], h[v]));
                merge_vec(dp[0][v], dp[0][w]);
                merge_vec(dp[1][v], dp[1][w]);
        }
        
        for (int i = 0; i < 2; i++) {
                auto it = lower_bound(begin(dp[i][v]),end(dp[i][v]),(1-2*i)*h[v]);
                if(it == end(dp[i][v])) dp[i][v].push_back((1-2*i)*h[v]);
                else *it = (1-2*i)*h[v];
                chmax(ret, dp[i][v].size());
        }
 
        return ret;
}
 
int solve()
{
        return dfs(0,-1);
}
 
void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", h+i);
        int a, b;
        for (int i = 0; i < n-1; i++) {
                scanf("%d%d", &a, &b);
                a--; b--;
                G[a].push_back(b);
                G[b].push_back(a);
        }
}
 
int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
