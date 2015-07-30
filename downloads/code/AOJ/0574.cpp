#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<vector<int>> f;
 
 
int solve()
{
        int ans = 0;
        for (int i = 0; i < n; i++)
                for (int j = 0; j <= i; j++)
                        f[i][j+1] += f[i][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j <= i; j++)
                        f[i+1][j] += f[i][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j <= i; j++)
                        f[i+1][j+1] += f[i][j];
 
        for (int i = 0; i < n; i++)
                for (int j = 0; j <= i; j++)
                        if(f[i][j]) ans++;
 
        return ans;
}
 
void input()
{
        scanf("%d%d", &n, &m);
        f.resize(n+2);
        for (int i = 0; i < n+2; i++) f[i].assign(i+2,0);
        int a, b, x;
        for (int i = 0; i < m; i++) {
                scanf("%d%d%d", &a, &b, &x);
                a--; b--;
                f[a][b] += 1;
                f[a][b+1] -= 1;
                f[a+x+1][b] -=1;
                f[a+x+2][b+1] += 1;
                f[a+x+1][b+x+2] += 1;
                f[a+x+2][b+x+2] -= 1;
        }
}
 
int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}