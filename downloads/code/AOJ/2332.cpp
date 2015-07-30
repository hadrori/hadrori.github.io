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

const int MAX = 100001;

int main(){
    int n;
    cin >> n;
    vi road(n);
    rep(i,n) cin >> road[i];
    vi path(n,INF);
    rep(i,n)if(path[i]==INF){
        bool visited[MAX] = {false};
        int cur = i;
        queue<int> masu;
        masu.push(cur);
        while(road[cur] && !visited[cur]){
            visited[cur] = true;
            cur += road[cur];
            masu.push(cur);
        }
        if(visited[cur]){
            while(!masu.empty()){
                int t = masu.front();
                masu.pop();
                path[t] = -1;
            }    
        }
        else {
            while(!masu.empty()){
                int t = masu.front();
                masu.pop();
                path[t] = cur;
            }    
        }
    }
    queue<pii> bfs;
    bool visited[MAX] = {false};
    bfs.push(mp(0,0));
    visited[0] = true;
    while(!bfs.empty()){
        int cur = bfs.front().first;
        int turn = bfs.front().second;
        bfs.pop();
        if(cur==n-1){
            cout << turn << endl;
            break;
        }
        repi(i,1,7)if(cur+i<n){
            int next = path[cur+i];
            if(next==-1 || visited[next]) continue;
            if(!visited[next]){
                bfs.push(mp(next,turn+1));
                visited[next] = true;
            }
        }
    }
}
