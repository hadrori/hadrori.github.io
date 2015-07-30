#include <bits/stdc++.h>
using namespace std;
 
int p[1<<20];
vector<long long> ps;
long long n;
 
long long solve()
{
        long long ans = 1;
        for(auto &e: ps) {
                if(n == 1) break;
                long long cnt = 0;
                while(n%e==0) {
                        cnt++;
                        n /= e;
                }
                ans *= cnt*2+1;
        }
        if(n > 1) ans *= 3;
        return (ans+1)/2;
}
 
void genp()
{
        p[0] = p[1] = 1;
        for (int i = 0; i < 1<<20; i++)
                if(!p[i]) {
                        ps.push_back(i);
                        for (int j = i+i; j < 1<<20; j+=i) p[j] = 1;
                }
}
 
int main()
{
        genp();
        while(cin >> n, n) cout << solve() << endl;
        return 0;
}