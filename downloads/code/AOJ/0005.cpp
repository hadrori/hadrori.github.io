#include <iostream>

#define ll long long int

using namespace std;

ll Euclid( ll m, ll n){
    if( m % n == 0){
        return n;
    }
    m %= n;
    if( m > n){
        return Euclid( m, n);
    }else{
        return Euclid( n, m);
    }
}

int main(){
    
    ll ans[1000][2] = {0};
    int cnt = 0;
    ll m , n;
    
    while(!cin.eof()){
        cin >> m >> n;
        if( m > n){
            ans[cnt][0] = Euclid( m, n);
        }else{
            ans[cnt][0] = Euclid( n, m);
        }
        ans[cnt++][1] = m / ans[cnt][0] * n;
        
    }
    
    for( int i = 0; i < cnt - 1; i++){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    return 0;
}