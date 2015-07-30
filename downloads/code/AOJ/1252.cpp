#include <bits/stdc++.h>
using namespace std;

int n, d;
string s[256];
set<string> t[256];

void gen(int id)
{
        t[id].clear();
        string f = s[id];
        const int m = f.size();
        // delete
        string head = "", tail = f.substr(1);
        char ch = f[0];
        for (int i = 0; i < m; i++) {
                t[id].insert(head+tail);
                if(i < m-1) {
                        head.push_back(ch);
                        ch = tail[0];
                        tail = tail.substr(1);
                }
        }
        // insert
        head = ""; tail = f;
        for (int i = 0; i <= m; i++) {
                for (char j = 'a'; j <= 'z'; j++) t[id].insert(head+string(1,j)+tail);
                if(i < m) {
                        head.push_back(tail[0]);
                        tail = tail.substr(1);
                }
        }
        // replace
        for (int i = 0; i < m; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                        if(f[i] == j) continue;
                        f[i] = j;
                        t[id].insert(f);
                }
                f[i] = s[id][i];
        }
        // swap
        for (int i = 0; i < m; i++) {
                if(i and f[i] != f[i-1]) {
                        swap(f[i], f[i-1]);
                        t[id].insert(f);
                        swap(f[i], f[i-1]);
                }
                if(i < m-1 and f[i] != f[i+1]) {
                        swap(f[i], f[i+1]);
                        t[id].insert(f);
                        swap(f[i], f[i+1]);
                }
        }
}

void solve()
{
        sort(s, s+n);
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; i++) gen(i);
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        if(t[j].count(s[i]) or t[i].count(s[j])) ans.push_back(make_pair(i,j));
                        else if(d == 2) {
                                auto it = begin(t[i]), jt = begin(t[j]);
                                while(it != end(t[i]) and jt != end(t[j])) {
                                        int cmp = strcmp(it->c_str(), jt->c_str());
                                        if(!cmp) {
                                                ans.push_back(make_pair(i,j));
                                                break;
                                        }
                                        else if(cmp > 0) jt++;
                                        else it++;
                                }
                        }
                }
        }
        for(auto &e: ans) cout << s[e.first] << "," << s[e.second] << endl;
        cout << ans.size() << endl;
}

bool input()
{
        cin >> n;
        if(!n) return 0;
        cin >> d;
        for (int i = 0; i < n; i++) cin >> s[i];
        return 1;
}

int main()
{
        while(input()) solve();
        return 0;
}
