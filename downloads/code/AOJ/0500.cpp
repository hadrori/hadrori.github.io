#include <iostream>


using namespace std;


int main(){
    
    int n = 1;
    int a[1000] = {0};
    int b[1000] = {0};
    int cnt = 0;
    
    cin >> n;
    while( n != 0){
        int x, y;
        for( int i = 0; i < n; i++){
            cin >> x >> y;
            if( x > y){
                a[cnt] += x + y;
            }else if( y > x){
                b[cnt] += x + y;
            }else{
                a[cnt] += x;
                b[cnt] += y;
            }
        }
        cnt++;
        cin >> n;
    }
    
    for( int i = 0; i < cnt; i++){
        cout << a[i] << ' ' << b[i] << endl;
    }
    
    return 0;
}