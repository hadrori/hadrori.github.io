#include <algorithm>
#include <iostream>
#include <vector>

#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
vi X;
ll m;

bool ok(int n){
    ll cnt = 0;
    repit(itr,X)
        cnt += (ll)(X.end() - lower_bound(itr+1, X.end(), n + *itr));
    return cnt <= m / 2;
}

int main(){
    while(~scanf("%d", &N)){
        X.resize(N);
        m = N * (N - 1) / 2;
        repit(itr,X) scanf("%d", &*itr);
        sort(all(X));
        int lb = 0, ub = 1000000001;
        while(lb + 1 < ub){
            int mid = (lb + ub) / 2;
            if(ok(mid)) ub = mid;
            else lb = mid;
        }
        cout << ub - 1 << endl;
    }
    return 0;
}
