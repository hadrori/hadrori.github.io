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
typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, k, m;
    while(cin>>n>>k>>m,n||k||m){
          vec st(n);
        rep(i,n) st[i] = i + 1;
        m--;
        rep(i,n-1){
            st.erase(st.begin()+m);
            m += k-1;
            m %= st.size();
        }
        cout << st[0] << endl;
    }
}
