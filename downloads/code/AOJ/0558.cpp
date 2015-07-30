#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;


int main(){
    int h, w, n;
    cin >> h >> w >> n;

    int area[1001][1001] = {0};
    vector<string> field(h);

    rep(i,h) cin >> field[i];
   
    int ans = 0;
    int x, y;

    rep(i,h) rep(j,w) if(field[i][j] == 'S'){
        x = i;
        y = j;
        break;
    }

    rep(i,n){
        char ob = i + '0' + 1;
        rep(a,h) rep(b,w) area[a][b] = 0;
        queue<P> bfs;
        bfs.push(P(x,y));
        while(1){
            int u = bfs.front().first;
            int v = bfs.front().second;
            bfs.pop();
            if(field[u][v] == ob){
                ans += area[u][v];
                x = u;
                y = v;
                break;
            }
            if(u>0 && !area[u-1][v] && field[u-1][v] != 'X'){
                bfs.push(P(u-1,v));
                area[u-1][v] = area[u][v]+1;
            }
            if(v>0 && !area[u][v-1] && field[u][v-1] != 'X'){
                bfs.push(P(u,v-1));
                area[u][v-1] = area[u][v]+1;
            }
            if(u<h-1 && !area[u+1][v] && field[u+1][v] != 'X'){
                bfs.push(P(u+1,v));
                area[u+1][v] = area[u][v]+1;
            }
            if(v<w-1 && !area[u][v+1] && field[u][v+1] != 'X'){
                bfs.push(P(u,v+1));
                area[u][v+1] = area[u][v]+1;
            }
        }
    }
    cout << ans << endl;
}
