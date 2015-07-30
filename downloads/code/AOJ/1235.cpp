#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, c;

int dx[] = {-1,0,-1,1,0,1};
int dy[] = {-1,-1,0,0,1,1};

bool inrange(int y, int x){
    return (x>=0 && x<=y && y>=0 && y<n);
}

int main(){
    while(cin>>n>>c,n||c){
        vector<vi> field(n);
        rep(i,n)rep(j,i+1){
            int st;
            cin >> st;
            field[i].pb(st);
        }
        vector<vi> score(n);
        rep(i,n)rep(j,i+1) score[i] = vi(i+1,0);
        rep(i,n)rep(j,i+1)if(!field[i][j]){
            field[i][j] = c;
            bool checked[11][11] = {false};
            rep(y,n)rep(x,y+1)if(field[y][x] && !checked[y][x]){
                checked[y][x] = true;
                queue<pii> bfs;
                bfs.push(mp(y,x));
                int stone = 1;
                bool flag = false;
                while(!bfs.empty()){
                    pii p = bfs.front(); bfs.pop();
                    int ty = p.first, tx = p.second;
                    rep(k,6){
                        int ny = ty + dy[k], nx = tx + dx[k];
                        if(inrange(ny, nx) && !checked[ny][nx]){
                            if(!field[ny][nx]){
                                flag = true;
                            }else if(field[ny][nx] == field[y][x]){
                                stone++;
                                checked[ny][nx] = true;
                                bfs.push(mp(ny,nx));
                            }
                        }
                    }
                }
                if(!flag){
                    if(field[y][x] == c){
                        score[i][j] -= stone;
                    }else{
                        score[i][j] += stone;
                    }
                }

            }
            field[i][j] = 0;
        }
        int ans = -INF;
        rep(y,n)rep(x,y+1)if(!field[y][x]) ans = max(ans, score[y][x]);
        cout << ans << endl;
    }
}
