#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000000

bool primes[MAX+1];

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
    prime();
    int a, d, n;
    while(cin >> a >> d >> n, a || d || n){
        int cnt = 0;
        int i = 0;
        while(cnt < n){
            if(primes[a+i*d]){
                cnt++;
            }
            i++;
        }
        cout << a + (i-1) * d << endl;
    }
}