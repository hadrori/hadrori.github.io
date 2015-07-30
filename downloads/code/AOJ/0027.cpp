#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int m, d;
    string ans[1000];
    int n = 0;
    cin >> m >> d;
    
    while( m != 0){
        int count = 0;
        
        count = ( m - 1) * 31 + d;
        if( m >= 3){
            count -= 2;
            if( m >= 5){
                count--;
                if( m >= 7){
                    count--;
                    if( m >= 10){
                        count--;
                        if( m == 12){
                            count--;
                        }
                    }
                }
            }
        }
        int s = count % 7;
        switch(s){
            case 0:
                ans[n++] = "Wednesday";
                break;
            case 1:
                ans[n++] = "Thursday";
                break;
            case 2:
                ans[n++] = "Friday";
                break;
            case 3:
                ans[n++] = "Saturday";
                break;
            case 4:
                ans[n++] = "Sunday";
                break;
            case 5:
                ans[n++] = "Monday";
                break;
            case 6:
                ans[n++] = "Tuesday";
                break;
            
        }
        
        cin >> m >> d;
    }
    
    for( int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    
    
    
    
    return 0;
}