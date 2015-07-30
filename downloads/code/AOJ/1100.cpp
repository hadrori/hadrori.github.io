#include <iostream>
#include <iomanip>

#define ll long long int

using namespace std;

int main(){
    
    double ans[1000] = {0};
    int cnt = 0;
    ll n = 0;
    
    cin >> n;
    
    while( n != 0){
        ll x[100] = {0};
        ll y[100] = {0};
        
        double area = 0;
        
        cin >> x[0] >> y[0];
        for( int i = 1; i < n; i++){
            cin >> x[i] >> y[i];
            area += ( x[i-1] - x[i]) * ( y[i-1] + y[i]);
        }
        area += ( x[n-1] - x[0]) * ( y[n-1] + y[0]);
        if( area < 0){
            area *= -1;
        }
        ans[cnt++] = area * 0.5;
        
        cin >> n;
    }
    
    for( int i = 0; i < cnt; i++){
        cout << setprecision(1);
        cout << setiosflags(ios::fixed);
        cout << i+1 << ' ' << ans[i] << endl;
    }
    
    return 0;
}