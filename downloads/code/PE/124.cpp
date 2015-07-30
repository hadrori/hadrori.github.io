#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAX = 100000;

bool p[MAX+1];
vi primes;

void prime_sieve(){
    memset(p,-1,sizeof(p));
    p[0] = p[1] = false;
    primes.pb(2);
    for(int j = 4; j < MAX + 1; j += 2) p[j] = false;
    for(int i = 3; i < MAX; i += 2)if(p[i]){
            primes.pb(i);
            for(int j = i * 2; j < MAX + 1; j += i)
                p[j] = false;
        }
}

int main(){
    prime_sieve();
    vector<pii> rad;
    rad.pb(pii(1,1));
    repi(i,2,MAX+1){
        cerr << i << endl;
        if(p[i]) rad.pb(pii(i,i));
        else{
            int prd = 1;
            int n = i;
            for(int j = 0; n != 1; j++)
                if(i % primes[j] == 0){
                    prd *= primes[j];
                    while(n % primes[j] == 0) n /= primes[j];
                }
            rad.pb(pii(prd,i));
        }
    }
    sort(all(rad));
    cout << rad[9999].second << endl;
    return 0;
}
