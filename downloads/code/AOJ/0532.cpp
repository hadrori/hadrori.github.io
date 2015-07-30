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

vi stohms(int time){
    vi t(3);
    rep(i,3){
        t[2-i] = time % 60;
        time /= 60;
    }
    return t;
}

int hmstos(vi t){
    int ret = 0;
    rep(i,3) ret += t[2-i] * pow(60.0,i); 
    return ret;
}

int main(){
    rep(i,3){
        vector<vi> t(2,vi(3));
        rep(i,2)rep(j,3) cin >> t[i][j];
        vi ans = stohms(hmstos(t[1]) - hmstos(t[0]));
        rep(i,3) cout << ans[i] << (i==2? '\n': ' ');
    }
}
