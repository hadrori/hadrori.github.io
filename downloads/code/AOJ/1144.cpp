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

#define INF 10000000
#define EPS 10e-8

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int w, h;
int si, sj, gi, gj;

int area[25][25];;
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int ans;
bool insize(int i, int j){
    if(i>=0 && i<h && j>=0 && j<w) return true;
    else return false;
}

void dfs(int i, int j, int cnt){
    if(cnt == 10) return;

    rep(d,4){
        int ti = i;
        int tj = j;
        bool ok = true;
        if(area[ti+di[d]][tj+dj[d]] == 1) continue;
        while(1){
            if(!insize(ti,tj)){
                ok = false;
                break;
            }
            if(area[ti][tj] == 3){
                ans = min(ans,cnt+1);
                return;
            }
            if(area[ti][tj] == 1) break;
            ti += di[d];
            tj += dj[d];
        }
        if(ok){
            area[ti][tj] = 0;
            dfs(ti-di[d],tj-dj[d],cnt+1);
            area[ti][tj] = 1;
        }
    }
}

int main(){

    while(cin >> w >> h, w || h){
        rep(i,h)rep(j,w) area[i][j] = 0;
        ans = INF;
        rep(i,h) rep(j,w){
            cin >> area[i][j];
            if(area[i][j] == 2){
                area[i][j] = 0;
                si = i;
                sj = j;
            }
        }
        dfs(si,sj,0);
        cout << (ans==INF?-1:ans) << endl;
    }

}
