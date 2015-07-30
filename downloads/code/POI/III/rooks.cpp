#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> ac[1<<12], bd[1<<12];
int n, x[1<<12], y[1<<12];

bool calc(vector<pii> lr[], int w[])
{
        priority_queue<pii, vector<pii>, greater<pii> >  q;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < (int)lr[i].size(); j++) q.push(lr[i][j]);
                if(q.empty()) return 0;
                pii p = q.top(); q.pop();
                if(p.first <= i) return 0;
                w[p.second] = i;
        }
        return 1;
}

void solve()
{
        if(!calc(ac,x) or !calc(bd,y)) puts("NIE");
        else {
                for (int i = 0; i < n; i++)
                        printf("%d %d\n", x[i]+1, y[i]+1);
        }
        return;
}

void input()
{
      scanf("%d", &n);
      int a, b, c, d;
      for (int i = 0; i < n; i++) {
              scanf("%d%d%d%d", &a, &b, &c, &d);
              ac[a-1].push_back(pii(c,i));
              bd[b-1].push_back(pii(d,i));
      }
      
}

int main()
{
        input();
        solve();
        return 0;
}
