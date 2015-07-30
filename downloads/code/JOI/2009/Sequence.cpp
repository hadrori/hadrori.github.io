#include <bits/stdc++.h>
using namespace std;

int m, a, b, t, sum[(1<<24)+32];
long long p, q;

inline void nexta(int &x) {
        int c = (1&x)^(1&(x>>(m-1)));
        x = (x>>1)|(c<<(m-1));
}

void find_loop()
{
        b = a;
        for (int i = 0; i < m; i++) sum[i+1] = sum[i]+((b>>i)&1);

        int cur = 0;
        do {
                nexta(b);
                sum[cur+m+1] = sum[cur+m]+((b>>(m-1))&1);
                cur++;
        } while(b != a);
        t = cur;
}

long long solve()
{
        if(!a) return 0;
        find_loop();

        long long ans = 0;
        long long d = q-p;
        ans += d/t*sum[t];
        d %= t;
        p %= t;
        q = p+d;
        if(q > t) ans += sum[t]-sum[p]+sum[q%t];
        else ans += sum[q]-sum[p];
        return ans;
}

void input()
{
        cin >> m >> p >> q;
        p--;
        for (int i = 0; i < m; i++){
                int t; cin >> t; t%=2;
                a |= (t<<i);
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
