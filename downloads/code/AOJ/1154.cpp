#include <iostream>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

bool smprm[300001];

int main(){
    rep(i,300001){
        if((i%7==1)||(i%7==6))smprm[i] = true;
        else smprm[i] = false;
    }
    smprm[1] = false;
    rep(i,300001){
        if(smprm[i]){
            for(int j = i*2; j < 300001;j += i){
                smprm[j] = false;
            }
        }
    }
    int n;
    while(cin >> n, n != 1){
        cout << n << ':';
        rep(i,n+1){
            if(smprm[i] && n % i == 0) cout << ' ' << i;
        }
        cout << endl;
    }
}