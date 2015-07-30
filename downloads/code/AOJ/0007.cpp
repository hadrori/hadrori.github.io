#include <iostream>

#define ll long long int
#define NUM 100000

using namespace std;

int main(){
    
    int n;
    ll money = NUM;
    
    cin >> n;
    
    for( int i = 0; i < n; i++){
        money *= 1.05;
        if( money % 1000 > 0){
            money /= 1000;
            money++;
            money *= 1000;
        }
    }
    
    cout << money << endl;
    
    return 0;
}