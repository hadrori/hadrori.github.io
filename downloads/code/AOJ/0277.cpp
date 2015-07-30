#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, a[] = {6000,4000,3000,2000};
    for(int i = 0; i < 4; i++){
        cin >> t >> n; t--;
        cout << a[t]*n << endl;
    }
    return 0;
}
