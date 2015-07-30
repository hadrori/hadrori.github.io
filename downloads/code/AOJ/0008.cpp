#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int cnt[100] = {0};
    int a = 0;
    
    while(cin){
        if( n > 36){
            cnt[a] = 0;
        }else{
            for( int i = 0; i < 10; i++){
                for( int j = 0; j < 10; j++){
                    for( int k = 0; k < 10; k++){
                        int l = n - i - j - k;
                        if( l >= 0 && l < 10){
                            cnt[a]++;
                        }
                    }
                }
            }
        }
        cin >> n;
        a++;
    }
    
    for( int i = 0; i < a; i++){
        cout << cnt[i] << endl;
    }
    
    return 0;
}