#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
#define pb push_back
typedef vector<int> vi;

vi primes;
bool p[60000];

const int MAX_N = 60000;
int main(){
    memset(p,-1,sizeof(p));
    p[0] = p[1] = false;
    rep(i,MAX_N)if(p[i]){
        primes.pb(i);
        for(int j = 2 * i; j < MAX_N; j += i)
            p[j] = false;
    }
    int n;
    while(cin >> n){
        vi::iterator itr = lower_bound(all(primes),n);
        if(p[n]) cout << *(itr-1) << ' ' << *(itr+1) << endl;
        else cout << *(itr-1)<< ' ' << *itr<< endl;
    }
    return 0;
}
