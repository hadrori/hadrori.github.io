#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    
    int n, m;
    string ans[10000];
    int cnt = 0;
    
    cin >> n;
    
    while( n != 0){
        map<char,char> change;
        for( int i = 0; i < n; i++){
            char a, b;
            cin >> a >> b;
            change.insert( make_pair( a, b));
        }
        
        int m;
        cin >> m;
        for( int i = 0; i < m; i++){
            char a;
            cin >> a;
            if( change.count(a)){
                ans[cnt].append( 1, change[a]);
            }else{
                ans[cnt].append( 1, a);
            }
        }
        cnt++;
        
        cin >> n;
    }
    
    for( int i = 0; i < cnt; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}