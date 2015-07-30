#include <bits/stdc++.h>
using namespace std;

int n, l[8][2], h[8][2];
vector<int> nfa[64][16], fin;
vector<long long> dp;
vector<vector<int>> rdfa;
map<vector<int>,int> id;

void dfa_rec(int &st, vector<int> &nsts)
{
        int cur = st-1;
        id.insert(make_pair(nsts,cur));
        vector<int> next[10];
        for(auto &s: nsts) {
                if(fin[s]) fin[cur] = 1;
                for (int i = 0; i < 10; i++) {
                        for(auto &t: nfa[s][i]) {
                                next[i].push_back(t);
                        }
                }
        }
        for (int i = 0; i < 10; ++i) {
                sort(begin(next[i]),end(next[i]));
                next[i].erase(unique(begin(next[i]),end(next[i])), end(next[i]));
                auto it = id.find(next[i]);
                if(it == end(id)) {
                        rdfa.push_back(vector<int>());
                        fin.push_back(0);
                        rdfa.back().push_back(cur);
                        dfa_rec(++st, next[i]);
                }
                else rdfa[it->second].push_back(cur);
        }
}

int build_dfa()
{
        int st = 4*n+1;
        rdfa.assign(st,vector<int>());
        fin.assign(st,0);
        fin[st-1] = 1;
        for (int i = 0; i < 4*n+1; i++) {
                for (int j = 0; j < 10; j++) {
                        auto it = id.find(nfa[i][j]);
                        if(it == end(id)) {
                                rdfa.push_back(vector<int>());
                                fin.push_back(0);
                                rdfa.back().push_back(i);
                                dfa_rec(++st, nfa[i][j]);
                        }
                        else rdfa[it->second].push_back(i);
                }
        }
        return st;
}

void build_nfa()
{
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) id.insert(make_pair(vector<int>(1,4*i+j),4*i+j));
                int p = 4*i, q = p+1, r = q+1, s = r+1, np = s+1;
                if(h[i][1] == l[i][1]) {
                        if(h[i][1]) {
                                nfa[p][h[i][1]].push_back(s);
                                for (int j = l[i][0]; j <= h[i][0]; j++) nfa[s][j].push_back(np);
                        }
                        else for (int j = l[i][0]; j <= h[i][0]; j++) nfa[p][j].push_back(np);
                }
                else {
                        if(l[i][1]) {
                                nfa[p][l[i][1]].push_back(q);
                                for (int j = l[i][0]; j < 10; j++) nfa[q][j].push_back(np);
                        }
                        else for (int j = l[i][0]; j < 10; j++) nfa[p][j].push_back(np);
                        
                        nfa[p][h[i][1]].push_back(s);
                        for (int j = 0; j <= h[i][0]; j++) nfa[s][j].push_back(np);
                        
                        if(l[i][1] < h[i][1]-1) {
                                for (int j = l[i][1]+1; j < h[i][1]; j++) nfa[p][j].push_back(r);
                                for (int j = 0; j < 10; j++) nfa[r][j].push_back(np);
                        }
                }
        }
}

void init()
{
        for (int i = 0; i < 64; i++) {
                for (int j = 0; j < 16; j++) {
                        nfa[i][j].clear();
                }
        }
        rdfa.clear();
        dp.clear();
        fin.clear();
        id.clear();
}

long long rec(int cur)
{
        long long &ret = dp[cur];
        if(ret > 0) return ret;
        
        for(auto &s: rdfa[cur]) {
                ret += rec(s);
        }
        return ret;
}

long long solve()
{
        init();
        build_nfa();
        int st = build_dfa();
        dp.assign(st,0);
        dp[0] = 1;
        long long ans = 0;
        for (int i = 0; i < st; i++) {
                if(fin[i]) ans += rec(i); 
        }

        return ans;
}

bool input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> l[i][0] >> h[i][0];
                l[i][1] = l[i][0]/10;
                l[i][0] %= 10;
                h[i][1] = h[i][0]/10;
                h[i][0] %= 10;
        }
        return n;
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
