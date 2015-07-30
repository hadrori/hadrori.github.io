#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[100010], y[100010];

bool chk(int s[], int k, int &res)
{
        int pv = -1e9-1;
        for (int i = 0; i < m; i++) {
                if(s[i]-pv > k) {
                        res--;
                        pv = s[i];
                }
                if(res<0) return 0;
        }
        return 1;
}

bool ok(int k)
{
        int res = n;
        return chk(x,k,res) and chk(y,k,res);
}

int solve()
{
        sort(x,x+m);
        sort(y,y+m);
        int lb = -1, ub = max(x[m-1]-x[0],y[m-1]-y[0]), mid;
        while(ub-lb>1){
                mid = (lb+ub)/2;
                if(ok(mid)) ub = mid;
                else lb = mid;
        }
        return ub;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < m; i++)
                cin >> x[i] >> y[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
