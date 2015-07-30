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
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    int a, b, d;
    while(cin>>a>>b>>d,a||b||d){
        int minxy = INF;
        pii ans = mp(INF,INF);
        rep(x,minxy+1){
            int y = INF;
            if((a*x+d)%b==0) y = min(y,(a*x+d)/b);
            if((a*x-d)>=0 && (a*x-d)%b==0) y = min(y,(a*x-d)/b);
            if((d-a*x)>=0 && (d-a*x)%b==0) y = min(y,(d-a*x)/b);
            if(x+y < minxy){
                ans = mp(x,y);
                minxy = x+y;
            }
            else if((x+y) == minxy){
                if(a*ans.first+b*ans.second > a*x+b*y) ans = mp(x,y);

            }
        }
        cout << ans.first << ' ' << ans.second << endl;
    }
}
