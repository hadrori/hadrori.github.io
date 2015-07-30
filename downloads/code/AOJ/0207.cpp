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

typedef long long ll;

using namespace std;

int main(){
    int w, h;
    while(cin >> w >> h, w || h){
        int xs, ys, xg, yg, n;
        cin >> xs >> ys >> xg >> yg >> n;
        int maze[128][128] = {0};
        rep(i,n){
            int c, d, x, y;
            cin >> c >> d >> x >> y;
            if(d){
                rep(j,4)maze[x][y+j] = c,  maze[x+1][y+j] = c;
            }else{
                rep(j,4)maze[x+j][y] = c,  maze[x+j][y+1] = c;
            }
        }

        int c = maze[xs][ys];
        if(maze[xg][yg] != c){
            cout << "NG" << endl;
        }else{
            bool visited[128][128] = {false};
            queue<pair<int,int> > st;
            
            st.push(mp(xs,ys));
            visited[xs][ys] = true;
            while(!st.empty()){
                int x = st.front().first;
                int y = st.front().second;
                st.pop();
                if(!visited[x+1][y] && maze[x+1][y] == c){
                    st.push(mp(x+1,y));
                    visited[x+1][y] = true;
                }
                if(!visited[x-1][y] && maze[x-1][y] == c){
                    st.push(mp(x-1,y));
                    visited[x-1][y] = true;
                }
                if(!visited[x][y+1] && maze[x][y+1] == c){
                    st.push(mp(x,y+1));
                    visited[x][y+1] = true;
                }
                if(!visited[x][y-1] && maze[x][y-1] == c){
                    st.push(mp(x,y-1));
                    visited[x][y-1] = true;
                }
            }
            
            if(visited[xg][yg])cout << "OK" << endl;
            else {
                cout << "NG" << endl;
            }
        }
    }
}
