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

#define MAX 100000

bool pr[MAX];
vec p;

void pcalc(){
    rep(i,MAX) pr[i] = (i<2)? false: true;
    for(int i = 0; i < MAX/2; i++){
        if(pr[i]){
            p.pb(i);
            for(int j = 2*i; j < MAX; j+=i) pr[j] = false;
        }
    }
}
int main(){
    pcalc();
    int m, a, b;
    while(cin>>m>>a>>b,m||a||b){
        double mi = (double)a/b;
        int w, h, maxa = 0;
        for(int i = 0; i<p.size() && p[i]*p[i]<=m; i++){
            for(int j = i; j<p.size() &&  p[i]*p[j]<=m; j++){
                if(mi <= (double)p[i]/p[j] && maxa < p[i]*p[j]){
                    maxa = p[i]*p[j];
                    w = p[i];
                    h = p[j];
                }
            }
        }
        cout << w << ' ' << h << endl;
    }
}
