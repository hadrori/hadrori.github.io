#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    
    int n = 0;
    cin >> n;
    
    string ans[1000];
    int cnt = 0;
    
    for( int i = 0; i < n; i++){
        int a[3] = {0};
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        if( a[0] * a[0] + a[1] * a[1] != a[2] * a[2]){
            ans[cnt++] = "NO";
        }else{
            ans[cnt++] = "YES";
        }
    }
    
    for( int i = 0; i < cnt; i++){
        cout << ans[i] << endl;
    }
    return 0;
}