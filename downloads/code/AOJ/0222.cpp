#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef vector<int> vec;

#define MAX 10010000

bool p[MAX+1];

void pcalc(){
    for(int i=0 ; i<=MAX ; i++){
        p[i] = (i<=1)? false : true ;
    }

    for(int i=2 ; i<=MAX/2 ; i++){
        if(p[i]){
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
        int i = n;
        while(1){
            if( p[i-8] && p[i-6] && p[i-2] && p[i] ){
                cout << i << endl;
                break;
            }
            i--;
        }
    }
}
