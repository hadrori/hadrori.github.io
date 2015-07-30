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

int s, n, t, p, m;
string wd, ti;
pii strangew;
bool strange(int time){
    int w = time % (7*24*60);
    int z = time % (24*60);
    bool ret = false;

    if(wd == "All") ret = true;
    else if(wd == "Sun" && w >= 0*24*60 && w < 1*24*60) ret = true;
    else if(wd == "Mon" && w >= 1*24*60 && w < 2*24*60) ret = true;
    else if(wd == "Tue" && w >= 2*24*60 && w < 3*24*60) ret = true;
    else if(wd == "Wed" && w >= 3*24*60 && w < 4*24*60) ret = true;
    else if(wd == "Thu" && w >= 4*24*60 && w < 5*24*60) ret = true;
    else if(wd == "Fri" && w >= 5*24*60 && w < 6*24*60) ret = true;
    else if(wd == "Sat" && w >= 6*24*60 && w < 7*24*60) ret = true;
    if(!ret) return false;

    if(ti == "All") return true;
    if(ti == "Day" && z >= 6*60 && z < 18*60) return true;
    if(ti == "Night" && ((z >= 0 && z < 6*60) || (z >= 18*60 && z < 24*60))) return true;
    return false;
}

int main(){
    while(cin >> s >> n >> t >> wd >> ti >> p >> m, n){
        double ans = 0;
        rep(i,7*24*60){
            int cnt = 0;
            rep(j,m){
                int start = i + j*t;
                if(strange(start) && strange(start + s)) cnt += n;
            }
            ans = max(ans, 1-pow(1.0*(p-1)/p,cnt));
        }
        printf("%.10f\n", ans);
    }
}
