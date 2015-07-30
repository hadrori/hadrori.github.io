#include <bits/stdc++.h>
using namespace std;

int n, c, sc[4096], cnt[4096];
vector<int> s[3];

int solve()
{

        for (int i = 0; i < n; i++) if(cnt[i] and i != c) s[cnt[i]].push_back(sc[i]);
        for (int i = 0; i < 3; i++) sort(begin(s[i]),end(s[i]));
        while(cnt[c] < 2) {
                sc[c] += s[0].back();
                cnt[c]++;
                s[0].pop_back();
        }

        int ans = n, b = sc[c];
        for(auto &e: s[2]) if(b >= e) ans--;
        for(auto &e: s[1]) {
                int d = b-e;
                auto it = upper_bound(begin(s[0]),end(s[0]),d);
                if(it == begin(s[0])) {
                        s[0].pop_back();
                        continue;
                }
                it--;
                s[0].erase(it);
                ans--;
        }
        
        for (auto it = begin(s[0]); it != end(s[0])-1; it++) {
                if(s[0].size() < 2) break;
                int d = b-*it;
                auto jt = upper_bound(it+1,end(s[0]),d);
                jt--;
                if(it==jt) {
                        s[0].pop_back();
                        continue;
                }
                s[0].erase(jt);
                ans--;
        }
        return ans;
}

void input()
{
        cin >> n >> c;
        c--;
        for (int i = 0; i < 2*n; i++) {
                int a, b; cin >> a >> b;
                if(b) sc[b-1] += a, cnt[b-1]++;
                else s[0].push_back(a);
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
