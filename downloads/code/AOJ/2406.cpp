#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>

#define ll long long int

using namespace std;

int main(){
    
    int n, t, e;
    int x[1000] = {0};
    
    cin >> n >> t >> e;
    for( int i = 0; i < n; i++){
        cin >> x[i];
    }
    for( int i = 0; i < n; i++){
        int j = 1;
        while( x[i] * j <= t + e){
            if( x[i] * j >= t - e && x[i] * j <= t + e){
                cout << i+1 << endl;
                return 0;
            }
            j++;
        }
    }
    
    cout << -1 << endl;
    return 0;
}