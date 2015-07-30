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

#define MAX 10001

bool p[MAX];

void pcalc(){
    rep(i,MAX) p[i] = (i<2)? false: true;
    rep(i,sqrt(MAX)+1) if(p[i]) for(int j=i*2; j<MAX; j+=i) p[j] = false;
}

int main(){
    pcalc();
    int n;
    while(~scanf("%d",&n)){
        int ans = 0;
        rep(i,n) if(p[i+1] && p[n-i]) ans++;
        cout << ans << endl;
    }
}
