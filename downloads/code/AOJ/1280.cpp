#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) (u).begin(),(u).end()
#define pb push_back
#define INF 1e9
using namespace std;
struct edge{
    int from, to, w;
    edge(int from, int to, int w):from(from),to(to),w(w){}
    bool operator < (const edge &e)const{
        return w < e.w;
    }
};

int n, m;
int parent[128];

int root(int x){
    if(parent[x] == x) return x;
    else return parent[x] = root(parent[x]);
}

int main(){
    while(cin >> n >> m, n || m){
        vector<edge> E;
        rep(i,m){
            int a, b, w; cin >> a >> b >> w;
            a--; b--;
            E.pb(edge(a,b,w));
        }
        int ans = INF;
        sort(all(E));
        rep(i,m){
            int k = 0;
            rep(j,n) parent[j] = j;
            repi(j,i,m){
                int p = root(E[j].from), q = root(E[j].to);
                if(p != q){
                    parent[q] = p;
                    k++;
                    if(k == n-1){
                        ans = min(ans, E[j].w - E[i].w);
                        break;
                    }
                }
            }
        }
        cout << (ans==INF? -1: ans) << endl;
    }
    return 0;
}
