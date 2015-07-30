#include <bits/stdc++.h>
using namespace std;
 
int n, m, s, g;
vector<pair<int,string>> G[64];
string dp[64];
 
string solve()
{
        int lim = 6*n;
        for (int lp = 0; lp < 7*n; lp++) {
                bool updated = 0;
                for (int i = 0; i < n; i++) {
                        if(i != g and dp[i] == "") continue;
                        for(auto &e: G[i]) {
                                if((e.first != g and dp[e.first] == "") or
                                   dp[e.first] > e.second+dp[i]) {
                                        dp[e.first] = e.second+dp[i];
                                        updated = 1;
                                }
                        }
                }
                if(!updated) break;
                if((int)dp[s].size() > lim) return "NO";
        }
        if(dp[s].size()) return dp[s];
        return "NO";
}
 
bool input()
{
        for (int i = 0; i < 64; i++) G[i].clear(), dp[i].clear();
        cin >> n >> m >> s >> g;
        for (int i = 0; i < m; i++) {
                int u, v; string s;
                cin >> u >> v >> s;
                G[v].push_back(make_pair(u,s));
        }
        return n or m or s or g;
}
 
int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}