#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, k[32];
pii ans[1<<20], tmp[1<<20];

void merge_odd(int sz, int idx)
{
        vector<pii> ret;
        int cur = 0;
        for (int i = 0; i < k[idx]-1; i+=2) {
                for(int i = 0; i < sz-2; i++) tmp[cur++] = ans[i];
                tmp[cur++] = pii(idx,1);
                for (int i = sz-3; i >= 0; i--) tmp[cur++] = pii(ans[i].first,-ans[i].second);
                tmp[cur++] = pii(idx,1);
        }
        for (int i = 0; i < sz-1; i++) tmp[cur++] = ans[i];
        for (int i = 0; i < k[idx]-1; i++) tmp[cur++] = pii(idx,-1);
        tmp[cur++] = ans[sz-1];
        for (int i = 0; i < sz*k[idx]; i++) ans[i] = tmp[i];
}

int merge(int sz, int idx)
{
        if(k[idx]%2) {
                merge_odd(sz,idx);
                return sz*k[idx];
        }
        int cur = 0;
        for (int i = 0; i < k[idx]; i+=2) {
                for(int i = 0; i < sz-1; i++) tmp[cur++] = ans[i];
                tmp[cur++] = pii(idx,1);
                for (int i = sz-2; i >= 0; i--) tmp[cur++] = pii(ans[i].first,-ans[i].second);
                tmp[cur++] = pii(idx,1);
        }
        for (int i = 0; i < sz*k[idx]; i++) ans[i] = tmp[i];
        return sz*k[idx];
}

void solve()
{
        for (int i = 0; i < k[0]; i++) ans[i] = pii(0,1);
        int sz = k[0];
        for (int i = 1; i < n; i++) sz = merge(sz,i);
        for (int i = 0; i < sz; i++) printf("%d %d\n", ans[i].first+1,ans[i].second);
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", k+i);
}

int main()
{
        input();
        solve();
        return 0;
}
