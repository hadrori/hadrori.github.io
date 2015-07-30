#include <bits/stdc++.h>
using namespace std;

int w, h, n, f[3010][3010];
const int di[] = {0,1,1,1}, dj[] = {1,1,0,-1};
inline void chmax(int &a, int b){a=max(a,b);}
inline bool in(int i, int j){ return i >= 0 and i < h and j >=0 and j < w;}

long long solve()
{
        long long ans = 0;
        for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                        for (int k = 0; k < 4; k++) {
                                int ni = i+di[k], nj = j+dj[k];
                                if(in(ni,nj)) chmax(f[ni][nj], f[i][j]-1);
                        }

        for (int i = h-1; i >= 0; i--)
                for (int j = w-1; j >= 0; j--){
                        ans += f[i][j];
                        for (int k = 0; k < 4; k++) {
                                int ni = i-di[k], nj = j-dj[k];
                                if(in(ni,nj)) chmax(f[ni][nj], f[i][j]-1);
                        }
                }
        return ans;
}

void input()
{
        cin >> w >> h >> n;
        for (int i = 0; i < n; i++) {
                int x, y, z; cin >> x >> y >> z;
                chmax(f[y][x], z);
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
