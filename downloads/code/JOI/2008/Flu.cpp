#include <bits/stdc++.h>
using namespace std;
const int pn[] = {1,-1};

int n, m, d, k;
int f[1024][1024], x[100010], y[100010], done[100010];
vector<int> G[100010];

inline bool in(int i, int j){ return i >= 0 and i < 1024 and j >= 0 and j < 1024;}

void near(int v)
{
        int oj = x[v], oi = y[v];
        for (int i = 0; i <= d; i++) {
                for (int j = 0; i*i+j*j <= d*d; j++) {
                        if(i == 0 and j == 0) continue;
                        for (int a = 0; a < 2-(i==0); a++) {
                                for (int b = 0; b < 2-(j==0); b++) {
                                        int ni = oi+i*pn[a], nj = oj+j*pn[b];
                                        if(in(ni,nj) and f[ni][nj]) G[v].push_back(f[ni][nj]);
                                }
                        }
                }
        }
}

int solve()
{
        for (int i = 1; i <= n; i++) near(i);
        int ans = 0;
        queue<pair<int,int>> q;
        q.push(pair<int,int>(1,0));
        while(!q.empty()){
                int v = q.front().first, dep = q.front().second;
                q.pop();
                if(done[v]) continue;
                done[v] = 1;
                if(dep <= k and k < dep+m) ans++;
                for(auto &e: G[v]) q.push(pair<int,int>(e,dep+1));
        }
        
        return ans;
}

void input()
{
        cin >> n >> m >> d >> k;
        for (int i = 1; i <= n; i++) {
                cin >> x[i] >> y[i];
                f[y[i]][x[i]] = i;
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
