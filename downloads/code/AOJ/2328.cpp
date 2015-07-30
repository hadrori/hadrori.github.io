#include <bits/stdc++.h>
using namespace std;

struct capacity
{
        int pl[64];
        capacity() { memset(pl,0,sizeof(pl));}
        capacity(int v) { memset(pl,0,sizeof(pl)); pl[0] = v;}
        capacity(const string &s) {
                memset(pl,0,sizeof(pl));
                int p = 0, n = s.size();
                while(p < n) {
                        int a = 0, b = 0;
                        while(p < n and s[p] != 'x') a = 10*a+s[p++]-'0';
                        if(p == n) {
                                pl[0] = a;
                                break;
                        }
                        p++;
                        if(!a) a++;
                        if(p == n or s[p] != '^') pl[1] = a;
                        else {
                                p++;
                                while(p < n and s[p] != '+') b = 10*b+s[p++]-'0';
                                pl[b] = a;
                        }
                        p++;
                }
        }

        string to_s()
        {
                string ret = "";
                for (int i = 51; i > 1; i--)
                        if(pl[i]) ret += (pl[i]>1? to_string(pl[i]): "") + "x^" + to_string(i) + "+";
                if(pl[1]) ret += (pl[1]>1? to_string(pl[1]): "") + "x+";
                if(pl[0]) ret += to_string(pl[0])+"+";
                if(ret.size()) return ret.substr(0,ret.size()-1);
                return "0";
        }

        capacity operator-=(const capacity &c) { for (int i = 0; i < 52; i++) pl[i] -= c.pl[i]; return *this; }
        capacity operator-(const capacity &c) const { return capacity(*this) -= c; }
        capacity operator+=(const capacity &c) { for (int i = 0; i < 52; i++) pl[i] += c.pl[i]; return *this; }
        capacity operator+(const capacity &c) const { return capacity(*this) += c; }

        bool operator<(const capacity &c) const {
                int k = 51;
                while(k and pl[k] == c.pl[k]) k--;
                return pl[k] < c.pl[k];
        }
        bool operator>(const capacity &c) const {
                int k = 51;
                while(k and pl[k] == c.pl[k]) k--;
                return pl[k] > c.pl[k];
        }
};

const capacity inf("x^51"), zero;

struct max_flow
{
        struct edge
        {
                int to, rev;
                capacity cap;
                edge(int to, int rev, capacity cap) : to(to), rev(rev), cap(cap) {}
        };
        int V;
        vector<vector<edge>> G;
        vector<int> itr, level;

        max_flow(){}
        max_flow(int V) : V(V) { G.assign(V,vector<edge>());}

        void add_edge(int from, int to, capacity cap)
        {
                G[from].push_back(edge(to, G[to].size(), cap));
                G[to].push_back(edge(from, G[from].size()-1, 0));
        }

        void bfs(int s)
        {
                level.assign(V,-1);
                queue<int> q;
                level[s] = 0; q.push(s);
                while (!q.empty()) {
                        int v = q.front(); q.pop();
                        for(auto &e: G[v]){
                                if (e.cap > zero and level[e.to] < 0) {
                                        level[e.to] = level[v] + 1;
                                        q.push(e.to);
                                }
                        }
                }
        }

        capacity dfs(int v, int t, capacity f)
        {
                if (v == t) return f;
                for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
                        edge& e = G[v][i];
                        if (e.cap > zero and level[v] < level[e.to]) {
                                auto d = dfs(e.to, t, min(f, e.cap));
                                if (d > 0) {
                                        e.cap -= d;
                                        G[e.to][e.rev].cap += d;
                                        return d;
                                }
                        }
                }
                return zero;
        }

        capacity run(int s, int t)
        {
                capacity ret = 0, f;
                while (bfs(s), level[t] >= 0) {
                        itr.assign(V,0);
                        while ((f = dfs(s, t, inf)) > zero) ret += f;
                }
                return ret;
        }
};

int n, m;
max_flow mf;

bool input()
{
        cin >> n >> m;
        mf = max_flow(n);
        for (int i = 0; i < m; i++) {
                int a, b; string s;
                cin >> a >> b >> s;
                a--; b--;
                capacity c(s);
                mf.add_edge(a,b,c);
                mf.add_edge(b,a,c);
        }
        return n or m;
}

int main()
{
        while(input()) cout << mf.run(0,n-1).to_s() << endl;
        return 0;
}
