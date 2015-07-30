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
    int h, w;
    while(cin >> h >> w, h || w){
        vector<vector<char> > field(h,vector<char>(w));
        vector<vector<bool> > visited(h,vector<bool>(w,false));
        rep(i,h) rep(j,w) cin >> field[i][j];
        
        int ans = 0;
        rep(i,h) rep(j,w) if(!visited[i][j]){
            ans++;
            char t = field[i][j];
            queue<P> q;
            q.push(P(i,j));
            visited[i][j] = true;
            while(!q.empty()){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                if(a>0 && !visited[a-1][b] && field[a-1][b] == t){
                    visited[a-1][b] = true;
                    q.push(P(a-1,b));
                }
                if(b>0 && !visited[a][b-1] && field[a][b-1] == t){
                    visited[a][b-1] = true;
                    q.push(P(a,b-1));
                }
                if(a<h-1 && !visited[a+1][b] && field[a+1][b] == t){
                    visited[a+1][b] = true;
                    q.push(P(a+1,b));
                }
                if(b<w-1 && !visited[a][b+1] && field[a][b+1] == t){
                    visited[a][b+1] = true;
                    q.push(P(a,b+1));
                }
            }
        }
        cout << ans << endl;
    }
}
