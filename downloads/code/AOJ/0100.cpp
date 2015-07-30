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

typedef long long ll;

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        ll sale[4096] = {0};
        bool ok = true;
        rep(i,n){
            ll s, h, u;
            cin >> s >> h >> u;
            if(sale[s] < 1000000){
                sale[s] += h * u;
                if(sale[s] >= 1000000){
                    cout << s << endl;
                    ok = false;
                }
            }
        }

        if(ok) cout << "NA" << endl;
    }
}
