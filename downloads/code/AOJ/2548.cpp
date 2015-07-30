#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define INF 1e8

using namespace std;

typedef vector<int> vi;

int m, s, g;
inline bool inrange(int cur){ return (cur >= 0 && cur < m);}

int main(){
    cin >> m;
    int a[6];
    vi n(m);
    rep(i,6) cin >> a[i];
    cin >> s >> g;
    s--; g--;
    rep(i,m) cin >> n[i];
    vi path[310];
    rep(i,m)rep(j,6){
        int l = i - a[j], r = i + a[j];
        if(inrange(l)) path[l+n[l]].pb(i);
        if(inrange(r)) path[r+n[r]].pb(i);
    }

    int dist[310];
    rep(i,310) dist[i] = INF;
    queue<int> bfs;
    bfs.push(g);
    dist[g] = 0;
    while(!bfs.empty()){
        int cur = bfs.front(); bfs.pop();
        rep(i,path[cur].size()){
            if(dist[path[cur][i]] == INF){
                dist[path[cur][i]] = dist[cur] + 1;
                bfs.push(path[cur][i]);
            }
        }
    }
    int cur = s;
    while(cur != g){
        int di;
        cin >> di;
        di--;
        int l = cur - a[di], r = cur + a[di];
        if(inrange(l) && dist[l+n[l]] < dist[cur]){
            cout << -1 << endl;
            cur = l + n[l];
        }else if(inrange(r) && dist[r+n[r]] < dist[cur]){
            cout << 1 << endl;
            cur = r + n[r];
        }else cout << 0 << endl;
    }
}
