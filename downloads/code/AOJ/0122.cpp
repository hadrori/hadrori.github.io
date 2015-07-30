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

int dx[12] = {-1,0,1,2,2,2,1,0,-1,-2,-2,-2};
int dy[12] = {2,2,2,1,0,-1,-2,-2,-2,-1,0,1};

int main(){
    int sx, sy;
    while(cin >> sx >> sy, sx || sy){
        int n;
        cin >> n;
        vector<P> sp;
        rep(i,n){
            int x, y;
            cin >> x >> y;
            sp.pb(P(x,y));
        }
        queue<pair<P,int> > bfs;
        bfs.push(mp(P(sx,sy),0));
        bool ok = false;

        while(!bfs.empty()){
            int x = bfs.front().first.first;
            int y = bfs.front().first.second;
            int turn = bfs.front().second;
            int a = sp[turn].first;
            int b = sp[turn].second;
            bfs.pop();
            rep(i,12){
                if(x+dx[i]>=0 && x+dx[i]<10 && x+dx[i]<=a+1 && x+dx[i]>=a-1
                   && y+dy[i]>=0 && y+dy[i]<10 && y+dy[i]<=b+1 && y+dy[i]>=b-1){
                    bfs.push(mp(P(x+dx[i],y+dy[i]),turn+1));
                    if(turn == n-1){
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) break;
        }
        if(ok) cout << "OK\n";
        else cout << "NA\n";
    }
}
