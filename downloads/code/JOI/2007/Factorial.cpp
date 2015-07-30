#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n;
vector<pii> p;

void gen_p()
{
        int nn = n;
        for (int i = 2; i < sqrt(n)+1; i++) {
                int k = 0;
                while(nn%i==0) {
                        ++k;
                        nn /= i;
                }
                if(k) p.push_back(pii(i,k));
        }
        if(nn > 1) p.push_back(pii(nn,1));
}

int solve()
{
        gen_p();
        int ans = 0;
        for(auto &e: p) {
                int q = e.first, k = e.second, tmp = 0;
                while(k > 0) {
                        tmp += q;
                        int t = tmp;
                        while(t%q==0) {
                                t /= q;
                                k--;
                        }
                }
                ans = max(ans, tmp);
        }

        return ans;
}

void input()
{
        cin >> n;  
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
