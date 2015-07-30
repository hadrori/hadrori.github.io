#include <iostream>
#include <cmath>

#define ll long long int
#define MAX 1000000

using namespace std;

bool primes[MAX+1];


bool prime_judge( ll n);


void prime(){
    
	for(int i=0 ; i<=MAX ; i++){
		primes[i] = (i<=1)? false : true ;
	}
    
	for(int i=2 ; i<=sqrt(MAX)+1 ; i++){
		if(primes[i]){
			for(int j=i*2 ; j<=MAX ; j+=i){
				primes[j] = false;
			}
		}
	}

    return;
}


int main(){
    
    int n, ans;
    prime();
    while( cin >> n){
        ans = 0;
        for( int i = 2; i <= n; i++){
            if(primes[i]){
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
