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
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, w;
    while(cin>>n>>w,n||w){
        int h = 0;
        int tail = 0;
        vec f(100/w+1,0);
        rep(i,n){
            int v;
            cin >> v;
            f[v/w]++;
            if(f[v/w] == 1) tail = max(tail,v/w);
            h = max(h,f[v/w]);
        }
        int cur = tail;
        double ans = 0.01;
        rep(i,tail+1){
            if(f[i]){
                ans += (double)f[i]/h * (double)cur/tail;
            }
            cur--;
        }
        printf("%.10f\n",ans);
    }
}
