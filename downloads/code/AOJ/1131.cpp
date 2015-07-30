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
int p, q, a, n;
int ans;

void dfs(int num, int den, int dep, int cur){
    /*
    if(den * p == num * q){
	ans++;
	return;
    }
    */
//    cout << num << "/" << den << endl;
    if(dep == n) return;
    for(int i = cur; i * den <= a; i++){
	if(i*den*p < (num*i+den)*q) continue;
	if(i*den*p == (num*i+den)*q){
	    ans++;
	    continue;
	}
	dfs((num*i+den), i*den, dep+1, i);
    }
    return;
}

int main(){
    while(cin >> p >> q >> a >> n, p||q||a||n){
	ans = 0;
	dfs(0,1,0,1);
	cout << ans << endl;
    }
    return 0;
}
