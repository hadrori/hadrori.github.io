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

#define INF 100000000

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

struct S{
    int id, dis, w;
    S(int id, int dis, int w):id(id),dis(dis),w(w){
    }
};

int n;
vector<S> kura;

int main(){
    int n;
    while(cin>>n,n){
        kura.clear();
        rep(i,n){
            int a, b, c;
            cin >> a >> b >> c;
            kura.pb(S(a,b,20*c));
        }

    }
}
