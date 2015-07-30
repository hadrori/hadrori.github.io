#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> tr;

int pow3(int k)
{
        int ret = 1, x = 3;
        for (int i = 0; i < k; i++) ret *= x;
        return ret;
}

long long solver(vector<int> st)
{
        long long ret = 0;
        for (int i = 0; i < n; i++) {
                if(st == tr) return ret;
                int np = 0, p = 0, mp = 0;
                for (int j = 0; j < 3; j++) {
                        if(st[j]&(1<<i)) p = j;
                        if(tr[j]&(1<<i)) np = j;
                }
                if(p == np) continue;
                mp = (7^(1<<p|1<<np))>>1;
                int up = st[p]&(~((1<<(i+1))-1));
                st[p] ^= 1<<i;
                if(abs(np-p)==1){
                        st[mp] |= up;
                        st[p] ^= up;
                }
                st[np] |= 1<<i;
                ret += abs(np-p)*pow3(__builtin_popcount(up));
                if(ret > m) return ret;
        }
        return ret;
}

int solve()
{
        vector<int> st(3);
        st[0] = (1<<n)-1;
        long long ans = solver(st);
        swap(st[0],st[2]);
        ans = min(ans, solver(st));
        return ans > m? -1: ans;
}

bool input()
{
        cin >> n >> m;
        if(!n and !m) return 0;
        tr.clear();
        tr.resize(3);
        for (int i = 0; i < 3; i++) {
                int k; cin >> k;
                for (int j = 0; j < k; j++) {
                        int t; cin >> t;
                        tr[i] |= 1<<(t-1);
                }
        }

        return 1;
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
