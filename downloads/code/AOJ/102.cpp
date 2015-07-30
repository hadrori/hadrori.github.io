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
    int n;
    while(cin>>n,n){
        mat d(n+1,vec(n+1,0));
        rep(i,n)rep(j,n){
            cin >> d[i][j];
            if(i==n-1) rep(k,n) d[i+1][j] += d[k][j];
            if(j==n-1) rep(k,n) d[i][j+1] += d[i][k];
        }
        rep(k,n) d[n][n] += d[n-1][k];
        rep(i,n+1) rep(j,n+1) cout << d[i][j] << ((j==n)?'\n':' ');
    }
}
