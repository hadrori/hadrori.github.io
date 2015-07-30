#include <bits/stdc++.h>
using namespace std;

int n, d;

int solve()
{
        int ans = 0;
        for (int i = 2; i <= n; i++) ans = (ans+d%i)%i;
        return ans+1;
}

bool input()
{
        cin >> n >> d;
        return n or d;
}

int main()
{
        while(input()) cout << n << ' ' << d << ' ' << solve() << endl;
        return 0;
}
