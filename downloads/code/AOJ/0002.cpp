#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int ans[200] = {0};
    int cnt = 0;
    int a, b;
    ios_base::iostate state;
    state = cin.rdstate();
    while(!cin.eof()){
        cin >> a >> b;
        int tmp = a + b;
        ans[cnt++] = (int)log10(a+b) + 1;
    }
    
    for( int i = 0; i < cnt - 1; i++){
        cout << ans[i] << endl;
    }
    return 0;
}