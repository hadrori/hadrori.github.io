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

bool dfs(queue<int> ball, int l, int r){
    if(ball.empty()) return true;
    int ne = ball.front();
    ball.pop();
    if(ne<l && ne<r) return false;
    else if(ne<l) return dfs(ball,l,ne);
    else if(ne<r) return dfs(ball,ne,r);
    else return dfs(ball,ne,r) || dfs(ball,l,ne);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        queue<int> ball;
        rep(i,10){
            int t;
            cin >> t;
            ball.push(t);
        }
        if(dfs(ball,0,0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
