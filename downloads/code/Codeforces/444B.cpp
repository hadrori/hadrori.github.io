#include <bits/stdc++.h>
using namespace std;
const int D = 1000;

int n, d, a[100010], b[100010], c[100010], p[100010];
long long x;

inline long long getx()
{
        return x = (x*37+10007)%1000000007;
}

void gen()
{
        for (int i = 0; i < n; i++) {
                a[i] = i+1;
                b[i] = (i < d);
        }
        for (int i = 0; i < n; i++) {
                swap(a[i], a[getx()%(i+1)]);
        }
        for (int i = 0; i < n; i++) {
                p[a[i]] = i;
                swap(b[i], b[getx()%(i+1)]);
        }
}

void solve_s()
{
        vector<int> ok;
        for (int i = 0; i < n; i++)
                if(b[i]) ok.push_back(i);
        for (int i = 0; i < n; i++) {
                for(auto &e: ok) {
                        if(e > i) break;
                        c[i] = max(c[i], a[i-e]);
                }
        }
}

void solve_l()
{
        priority_queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        for (int i = n; i > 0; i--) {
                vector<int> next;
                while (!q.empty()) {
                        int v = q.top();
                        if(v < p[i]) break;
                        q.pop();
                        if(b[v-p[i]]) c[v] = i;
                        else next.push_back(v);
                }
                for(auto &e: next) q.push(e);
        }
}

int solve()
{
        gen();
        if(d <= D) solve_s();
        else solve_l();
        for (int i = 0; i < n; i++) printf("%d\n", c[i]);
        return 0;
}

void input()
{
        cin >> n >> d >> x;
}

int main()
{
        input();
        solve();
        return 0;
}
