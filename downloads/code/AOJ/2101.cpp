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

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

#define MAX 10000

using namespace std;

bool primes[MAX+1];
ll prm[MAX+1];

void prime(){
    int cnt = 0;
	for(int i=0 ; i<=MAX ; i++){
		primes[i] = (i<=1)? false : true ;
	}

	for(int i=2 ; i<=MAX ; i++){
		if(primes[i]){
            //if(i == 8191) cout << cnt << endl;;
            prm[cnt++] = i;
			for(int j=i*i ; j<=MAX ; j+=i){
				primes[j] = false;
			}
		}
	}
    return;
}


ll n;
ll prd;
ll ans;

int main(){
    
    prime();
    while(cin >> n, n){
        if(n == 1) cout << "deficient number" << endl;
        //else if((n < 10000 ) && primes[n]) cout << "deficient number" << endl;
        else{
            ll tmp = n;
            map<int,int> fac;
            fac.clear();
            ans = 0;
            prd = 1;
            for(int i = 0; prm[i] <= sqrt(tmp); i++){
                if(n % prm[i] == 0){
                    fac.insert(make_pair(prm[i], 0));
                    while(n % prm[i] == 0){
                        fac[prm[i]]++;
                        n /= prm[i];
                    }
                    //cout << prm[i] << ' ' << fac[prm[i]] << endl;
                }
                if(prm[i] == 9973)break;
            }

            if(n != 1) fac.insert(make_pair(n, 1));
            
            map<int, int>::iterator itr;
            itr = fac.begin();
            rep(i, 0, fac.size()){
                ll sum = 0;
                rep(j, 0, (*itr).second+1){
                    sum += pow((double)(*itr).first, (double)j);
                }
                prd *= sum;
                itr++;
            }
            
            prd -= tmp;
            //cout << prd << endl;
            if(prd < tmp) cout << "deficient number" << endl;
            else if(prd == tmp) cout << "perfect number" << endl;
            else cout << "abundant number" << endl;
        }
    }
    
    return 0;
}