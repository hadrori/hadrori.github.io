#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segtree  // RMQ
{
        int N;
        vector<int> dat;
        segtree(int n) {
                N = 1;
                while(N < n) N *= 2;
                dat.assign(2*N, 0);
        }
        // update k th element
        void update(int k, int a) {
                k += N-1; // leaf
                dat[k] = a;
                while(k > 0){
                        k = (k - 1) / 2;
                        dat[k] = max(dat[k*2+1], dat[k*2+2]);
                }
        }
        // min [a, b)
        int query(int a, int b){ return query(a, b, 0, 0, N);}
        int query(int a, int b, int k, int l, int r) {
                if(r <= a or b <= l) return 0;
                if(a <= l and r <= b) return dat[k];
                int m = (l + r) / 2;
                return max(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
        }
};


int n, w[1<<17], sh[1<<17];

int solve()
{
        int ans = 0, sum = 0;
        segtree dp(n);
        for (int i = 0; i < n; i++) {
                sum += w[i]*2;
                sh[i]--;
                dp.update(sh[i], dp.query(0,sh[i])+w[sh[i]]*2);
                ans = max(ans, dp.query(sh[i],sh[i]+1));
        }
        return sum - ans;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) cin >> w[i];
        for (int i = 0; i < n; i++) cin >> sh[i];

}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
