#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, c[1024][1024], p[1024], type[4], done[1024];

void type1()
{
        int cnt = 0, cst = 0;
        for (int i = 0; i < n; i++)
                if(p[i] == 1)
                        for (int j = 0; j < n; j++)
                                if(j != i and c[i][j] >= 0) {
                                        cst += c[i][j];
                                        cnt++;
                                        c[i][j] = c[j][i] = -1;
                                }
        cout << cnt << " " << cst << endl;
}

void type2()
{
        int cst = 1e9;
        for (int i = 0; i < n; i++){
                int tmp = 0;
                for (int j = 0; j < n; j++) tmp += c[i][j];
                cst = min(cst , tmp);
        }
        if(type[2] == 2) {
                int v[2] = {}, k = 0;
                for (int i = 0; i < n; i++) if(p[i] == 2) v[k++] = i;
                assert(k==2);
                int tmp = c[v[0]][v[1]];
                for (int i = 0; i < n; i++)
                        if(i != v[0] and i != v[1])
                                tmp += min(c[v[0]][i], c[v[1]][i]);
                cst = min(cst, tmp);
        }
        cout << n-1 << " " << cst << endl;
}

void type3()
{
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.push(pii(0,0));
        int cst = 0;
        while(!q.empty()){
                int cs = q.top().first, v = q.top().second;
                q.pop();
                if(done[v]) continue;
                done[v] = 1;
                cst += cs;
                for(int i = 0; i < n; i++)
                        if(!done[i]) q.push(pii(c[v][i], i));
        }
        cout << n-1 << " " << cst << endl;
}

void solve()
{
        if(type[1]) type1();
        else if(type[2]) type2();
        else type3();
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> p[i];
                type[p[i]]++;
        }
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        cin >> c[i][j];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
