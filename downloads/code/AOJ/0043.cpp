#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> s, int k)
{
        s.push_back(k);
        sort(begin(s),end(s));
        if(upper_bound(begin(s),end(s),k)-lower_bound(begin(s),end(s),k) > 4) return 0;
        for (int head = 1; head < 10; head++) {
                vector<int> t = s;
                auto ub = upper_bound(begin(t),end(t),head), lb = lower_bound(begin(t),end(t),head);
                if(ub - lb < 2) continue;
                ub = lb+2;
                t.erase(lb, ub);
                int res = 12;
                for (int i = 1; i < 10 and res; i++) {
                        auto ub = upper_bound(begin(t),end(t), i), lb = lower_bound(begin(t),end(t), i);
                        if(ub - lb > 2) {
                                t.erase(lb, lb+3);
                                res -= 3;
                                ub = upper_bound(begin(t),end(t), i);
                                lb = lower_bound(begin(t),end(t), i);
                        }
                        while(ub - lb > 0) {
                                auto a = lower_bound(begin(t),end(t),i+1), b = lower_bound(begin(t),end(t),i+2);
                                if(a == end(t) or b == end(t) or *a != i+1 or *b != i+2) break;
                                t.erase(b);
                                t.erase(a);
                                t.erase(lb);
                                res -= 3;
                                ub = upper_bound(begin(t),end(t), i);
                                lb = lower_bound(begin(t),end(t), i);
                        }
                }
                if(!res) return 1;
        }
        return 0;
}

void solve(string s)
{
        vector<int> ans, seq;
        for(auto &c: s) seq.push_back(c-'0');
        for (int i = 1; i < 10; i++)
                if(valid(seq, i)) ans.push_back(i);
        if(!ans.size()) cout << 0 << endl;
        else {
                for (int i = 0; i < (int)ans.size()-1; i++) {
                        cout << ans[i] << " ";
                }
                cout << ans.back() << endl;
        }
}
int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        string s;
        while(cin >> s) solve(s);
        return 0;
}
