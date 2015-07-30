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
int n;
string al = "abcdefghijklmnopqrstuvwxyz";
string solve(){
    string code;
    cin >> code;
    stack<pii> pass;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--; b--;
        pass.push(mp(a,b));
    }
    rep(i,n){
        int a = pass.top().first, b = pass.top().second; 
        pass.pop();
        int d = abs(a-b);
        code[a] = (code[a] + d - 'a') % 26 + 'a';
        code[b] = (code[b] + d - 'a') % 26 + 'a';
        swap(code[a],code[b]);
    }
    return code;
}
int main(){
    while(cin >> n, n){
        cout << solve() << endl;
    }
}
