#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    bool cflag = true;
    int cnt = 0;
    for( int i = 0; i < n; i++){
        char p;
        int x;
        
        cin >> p >> x;
        if( cflag){
            if( p == '('){
                cnt += x;
            }else{
                cnt -= x;
            }
            if( cnt < 0){
                cflag = false;
            }
        }
    }
    
    if( cflag && (cnt == 0)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
