#include <bits/stdc++.h>
using namespace std;
 
long long n, fact[32], cnt[32];
string s;
 
void gen()
{
        fact[0] = 1;
        for (int i = 0; i < n; i++) {
                fact[i+1] = fact[i]*(i+1);
                cnt[s[i]-'A']++;
        }
}

long long comb(int n, int k){ return fact[n]/fact[k]/fact[n-k];}
 
long long perm(int c, int res)
{
        long long ret = 0;
        for (int i = 0; i < c; i++) {
                long long tmp = 1, r = res;
                if(!cnt[i]) continue;
                cnt[i]--;
                for (int j = 0; j < 26; j++)
                        if(cnt[j]) {
                                tmp *= comb(r,cnt[j]);
                                r -= cnt[j];
                        }
                ret += tmp;
                cnt[i]++;
        }
        return ret;
}
 
long long solve()
{
        n = s.size();
        gen();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
                int c = s[i] - 'A';
                ans += perm(c, n-i-1);
                cnt[c]--;
        }
        return ans+1;
}
 
void input()
{
        cin >> s;
}
 
int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
