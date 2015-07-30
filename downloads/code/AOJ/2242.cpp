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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

struct S{
    string name;
    int by, wy;
};

int main(){
    int n, q;
    while(cin>>n>>q,n||q){
        vector<S> era;
        int i = n;
        while(i--){
            S e;
            cin >> e.name >> e.by >> e.wy;
            era.pb(e);
        }
        while(q--){
            int qu;
            cin >> qu;
            bool unk = true;
            rep(i,n){
                if(qu > era[i].wy-era[i].by && qu <= era[i].wy){
                    cout << era[i].name << ' ' << qu - era[i].wy + era[i].by<< endl;
                    unk = false;
                    break;
                }
            }
            if(unk) cout << "Unknown\n";
        }
    }
}

