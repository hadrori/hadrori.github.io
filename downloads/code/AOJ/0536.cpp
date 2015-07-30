#include <bits/stdc++.h>
using namespace std;

int n, m, o, p, q, x[5010], y[5010];
vector<pair<int,int>> sp;

vector<pair<int,int>> get_sect(int l, int r)
{
        auto lb = lower_bound(begin(sp),end(sp),make_pair(l,l)), ub = upper_bound(begin(sp),end(sp),make_pair(r,r));
        if(lb != begin(sp) and (lb-1)->second > l) lb--;
        vector<pair<int,int>> ret;
        for (auto it = lb; it != ub; it++) {
                pair<int,int> s;
                if(it->first < l) s.first = l;
                else s.first = it->first;
                if(it->second > r) s.second = r;
                else s.second = it->second;
                ret.push_back(s);
        }
        return ret;
}

void dump(vector<pair<int,int>> s)
{
        for(auto &e: s) cerr << "[" << e.first << "," << e.second << ") , "; cerr << endl;
}

int solve()
{
        sp.clear();
        sp.push_back(make_pair(0,q));
        for (int i = 0; i < m; i++) {
                auto a = get_sect(0, x[i]), b = get_sect(x[i], y[i]), c = get_sect(y[i],n);
                for(auto &e: a) {
                        e.first += n-x[i];
                        e.second += n-x[i];
                }
                for(auto &e: b) {
                        e.first += n-y[i]-x[i];
                        e.second += n-y[i]-x[i];
                }
                for(auto &e: c) {
                        e.first -= y[i];
                        e.second -= y[i];
                }
                sp = c;
                sp.insert(end(sp),begin(b),end(b));
                sp.insert(end(sp),begin(a),end(a));
        }
        auto a = get_sect(o,p);
        int ans = 0;
        for(auto &e: a) ans += e.second-e.first;
        return ans;
}

bool input()
{
        scanf("%d", &n);
        if(!n) return 0;
        scanf("%d%d%d%d", &m, &o, &p, &q);
        o--;
        for (int i = 0; i < m; i++) scanf("%d%d", x+i, y+i);
        return 1;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
