#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 250000

using namespace std;

bool primes[MAX+1];
vector<int> p;

void prime(){
    
	for(int i=0 ; i<=MAX ; i++){
		primes[i] = (i<=1)? false : true ;
	}
    
	for(int i=2 ; i<=MAX ; i++){
		if(primes[i]){
            p.push_back(i);
			for(int j=i*2 ; j<=MAX ; j+=i){
				primes[j] = false;
			}
		}
	}
    return;
}

using namespace std;

int main(){
    prime();
    int n;
    while(cin >> n, n){
        cout << upper_bound(p.begin(),p.end(),2*n) - lower_bound(p.begin(), p.end(), n+1) << endl;
    }
    
}