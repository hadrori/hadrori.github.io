#include <iostream>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
typedef long long ll;

ll Q, N, M;

inline ll calc(ll i, ll j){ return i*i+100000*i+j*j-100000*j+i*j;}

bool lower(ll n){
    ll cnt = 0;
    repi(j,1,N+1){
        int lb = 0, ub = N + 1;
        while(lb + 1 < ub){
            int i = (lb + ub) / 2;
            if(calc(i,j) < n) lb = i;
            else ub = i;
        }
        cnt += lb;
    }
    return cnt >= M;
}

int main(){
    scanf("%lld", &Q);
    while(Q--){
        scanf("%lld %lld", &N, &M);
        ll lb = -1000000000000, ub = 1000000000000;
        while(lb + 1 < ub){
            ll mid = (lb + ub) / 2;
            if(lower(mid)) ub = mid;
            else lb = mid;
        }
        printf("%lld\n", lb);
    }
    return 0;
}
