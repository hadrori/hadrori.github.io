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
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int rec(int a, int b, int k, int borrow){
    if(!a) return 0;
    int ret = 0;
    int c = a%10 - b%10;
    if(c >= borrow) ret = rec(a/10,b/10,k,0)*10 + c - borrow;
    else            ret = rec(a/10,b/10,k,1)*10 + 10 + c - borrow;
    if(k && borrow){
	if(c >= 0) ret = max(ret, rec(a/10,b/10,k-1,0)*10 + c);
	else       ret = max(ret, rec(a/10,b/10,k-1,1)*10 + 10 + c);
    }
    return ret;
}

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    cout << rec(a,b,k,0) << endl;
    return 0;
}
