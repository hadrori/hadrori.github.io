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

int main(){
    int n;
    while(cin>>n,n){
        bool islogin[1000] = {false};
        int times[1000] = {0};
        int sum[1000] = {0}; 
        while(n--){
            int a, b, h, m, id;
            char c;
            scanf("%d/%d %d:%d %c %d", &a, &b, &h, &m, &c, &id);
            if(c == 'I'){
                islogin[id] = true;
                times[id] = h*60 + m;
                if(id==0) repi(i,1,1000) times[i] = times[0];
            }else{
                islogin[id] = false;
                if(id==0){
                    repi(i,1,1000)if(islogin[i]){
                        sum[i] += h*60 + m - times[i];
                    }
                }
                if(islogin[0]) sum[id] += h*60 + m - times[id];
            }
        }
        int ans = 0;
        repi(i,1,1000) ans = max(ans, sum[i]);
        cout << ans << endl;
    }
}
