#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef vector<vec> mat;

#define MAX 110000

bool p[MAX+1];
vec primes(15001);

void pcalc(){
    for(int i=0 ; i<=MAX ; i++){
        p[i] = (i<=1)? false : true ;
    }
    int cnt = 0;
    primes[0] = 0;
    for(int i=2 ; i<MAX+1 ; i++){
        if(p[i]){
            primes[++cnt] = primes[cnt-1] + i;
            for(int j=i*2 ; j<=MAX ; j+=i){
                p[j] = false;
            }
        }
    }
    return;
}

int main(){
    int n;
    pcalc();
    while(cin>>n,n){
        cout << primes[n] << endl;
    }
}
