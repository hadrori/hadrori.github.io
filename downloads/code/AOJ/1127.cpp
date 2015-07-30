#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define INF 1e9

struct Sphere{ double x, y, z, r;};

inline double sq(double a){ return a*a;}
inline double center_distance(Sphere a, Sphere b){ return sqrt(sq(a.x-b.x)+sq(a.y-b.y)+sq(a.z-b.z));}
inline bool overrap(Sphere a, Sphere b){ return center_distance(a,b) <= (a.r + b.r);}
inline double distanceSS(Sphere a, Sphere b){
    if(overrap(a,b)) return 0.0;
    return center_distance(a,b)-(a.r+b.r);
}

int main(){
    int n;
    while(cin>>n,n){
        vector<Sphere> cell;
        rep(i,n){
            Sphere s;
            cin >> s.x >> s.y >> s.z >> s.r;
            cell.pb(s);
        }
        vector<vector<double> > cost(n,vector<double>(n,0));
        rep(i,n)rep(j,i){
            cost[i][j] = distanceSS(cell[i],cell[j]);
            cost[j][i] = cost[i][j];
        }
        vector<bool> used(n,false);
        vector<double> d(n,INF);
        double ans = 0;
        d[0] = 0;

        while(1){
            int v = -1;
            rep(u,n) if(!used[u] && (v == -1 || d[u] < d[v])) v = u;

            if(v==-1) break;
            used[v] = true;
            ans += d[v];
            rep(u,n) d[u] = min(d[u], cost[v][u]);
        }
        printf("%.3f\n", ans);
    }
}


