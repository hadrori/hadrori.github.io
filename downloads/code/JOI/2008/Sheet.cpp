#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, w, h, s[128][128], done[1024];
pii lt[1024], rb[1024];
vector<int> under[1024], ans;

inline void chmin(int &a, int b){ a = min(a, b);}
inline void chmax(int &a, int b){ a = max(a, b);}

void dfs(int v)
{
        if(done[v]) return;
        done[v] = 1;
        for(auto &e: under[v]) dfs(e);
        ans.push_back(v);
}

void solve()
{
        for (int i = 0; i <= n; i++) {
                lt[i] = pii(h,w);
                rb[i] = pii(0,0);
        }
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        chmin(lt[s[i][j]].first, i);
                        chmin(lt[s[i][j]].second, j);
                        chmax(rb[s[i][j]].first, i+1);
                        chmax(rb[s[i][j]].second, j+1);
                }
        }
        for (int k = 1; k <= n; k++) {
                memset(done,0,sizeof(done));
                done[0] = done[k] = 1;
                for (int i = lt[k].first; i < rb[k].first; i++) {
                        for (int j = lt[k].second; j < rb[k].second; j++) {
                                int &id = s[i][j];
                                if(done[id]) continue;
                                under[id].push_back(k);
                                done[id] = 1;
                        }
                }
        }

        memset(done,0,sizeof(done));
        for (int i = 1; i <= n; i++) dfs(i);
        for (int i = 0; i < n; i++)
                cout << ans[i] << (i==n-1? '\n': ' ');
        cout << endl;
}

void input()
{
        cin >> n >> w >> h;
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        cin >> s[i][j];
                }
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
