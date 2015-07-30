#include <bits/stdc++.h>
using namespace std;

int p, n, powc[10010];

int pow_mod(int x, int k, int p)
{
        if(!k) return 1;
        if(k%2) return x*pow_mod(x,k-1,p)%p;
        else return pow_mod(x*x%p,k/2,p);
}

int solve()
{
        for (int i = 0; i < p; i++)
                powc[pow_mod(i,n,p)]++;
        int ans = 0;
        for (int i = 0; i < p; i++){
                ans += powc[i]*powc[i]*powc[(i+i)%p];
                for (int j = i+1; j < p; j++)
                        ans += 2*powc[i]*powc[j]*powc[(i+j)%p];
        }
        return ans;
}

void input()
{
        cin >> p >> n;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
