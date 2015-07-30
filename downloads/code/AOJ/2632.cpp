#include <bits/stdc++.h>
using namespace std;

int h, w, n, seq[200010];
pair<int,int> bs[200010];

int value(int i, int j)
{
        i %= 2*w;
        while(i) {
                int tmp;
                if((i+j)%2) tmp = min(i, w-j-1);
                else tmp = -min(i,j);
                j += tmp;
                i -= abs(tmp);
                if(i) i--;
        }
        return j;
}

void solve()
{
        sort(bs, bs+n);
        for (int i = 0; i < w; i++) seq[i] = i;
        for (int i = 0; i < n; i++) {
                int p = bs[i].first, l = bs[i].second, r = l+1;
                //cerr << "(" << p << "," << l << "," << r << ") => (" << value(p,l) << "," << value(p,r) << ")" << endl;
                swap(seq[value(p,l)], seq[value(p,r)]);
        }
        int ans[200010];
        for (int i = 0; i < w; i++) ans[seq[value(h,i)]] = i+1;
        for (int i = 0; i < w; i++) printf("%d\n", ans[i]);
}

void input()
{
        scanf("%d%d%d", &h, &w, &n);
        int a, b;
        for (int i = 0; i < n; i++) {
                scanf("%d%d", &a, &b);
                bs[i] = make_pair(a-1,b-1);
        }
}

int main()
{
        input();
        solve();
        return 0;
}
