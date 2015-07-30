#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

#define MAX 102000

bool primes[MAX+1];

void prime(){
	for(int i=0 ; i<=MAX ; i++){
		primes[i] = (i<=1)? false : true ;
	}
    
	for(int i=2 ; i*i<=MAX; i++){
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
    int n, p;
    while(cin >> n >> p, (n != -1) || (p != -1)){
        vector<int> m;
        vector<int> prm;
        int i = n;
        rep(cnt, 0, 100){
            i++;
            while(!primes[i]){
                i++;
            }
            prm.push_back(i);
            //cout << prm[cnt] << ' ';
        }
        //cout  << endl;
        rep(i, 0, 100){
            rep(j, i, 100){
                m.push_back(prm[i]+prm[j]);
                    //cout << prm[i] + prm[j] << endl;
            }
        }
        sort(m.begin(),m.end());
        cout << m[p-1] << endl;
    }
}