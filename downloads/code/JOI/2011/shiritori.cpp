#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, deg[128], itr[128];
vector<string> words, ans;
vector<pii> G[128];

int find_start()
{
        vector<int> hs, ts;
        for (int i = 0; i < 100; i++) {
                if(deg[i] > 1) return -1;
                if(deg[i] == 1) hs.push_back(i);
                if(deg[i] == -1) ts.push_back(i);
        }
        if(hs.size() == 0 and ts.size() == 0) return stoi(words[0].substr(0,2));
        if(hs.size() != 1 or ts.size() != 1) return -1;
        return hs[0];
}

void build_graph()
{
        int i = 0;
        for(auto &w: words) {
                int u = stoi(w.substr(0,2)), v = stoi(w.substr(8,2));
                G[u].push_back(pii(v,i++));
        }
}

void euler(int v)
{
        for (int &i = itr[v]; i < (int)G[v].size();) {
                int j = i++;
                euler(G[v][j].first);
                ans.push_back(words[G[v][j].second]);
        }
}

int solve()
{
        sort(begin(words),end(words));
        int s = find_start();
        if(s < 0) return 0;
        build_graph();
        euler(s);
        if((int)ans.size() != n) return 0;
        reverse(begin(ans),end(ans));
        for(auto &e: ans) cout << e << endl;
        return 1;
}

void input()
{
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
                cin >> s;
                words.push_back(s);
                deg[stoi(s.substr(0,2))]++;
                deg[stoi(s.substr(8,2))]--;
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        if(!solve()) cout << "impossible" << endl;
        return 0;
}
