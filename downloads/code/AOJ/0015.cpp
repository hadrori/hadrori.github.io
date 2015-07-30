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
#include <set>

#define ll long long int

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for( int i = 0; i < n; i++){
        string a;
        string b;
        
        cin >> a;
        cin >> b;

        if( a.size() > 80 || b.size() > 80){
            cout << "overflow" << endl;
        }else{
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            
            int l = ( a.size() > b.size()) ? b.size():a.size();
            string c = ( a.size() > b.size()) ? a:b;
            string d = ( a.size() > b.size()) ? b:a;
            
            for( int j = 0; j < c.size(); j++){
                if( j < d.size()){
                    int t1 = c[j] - '0';
                    int t2 = d[j] - '0';
                    int sum = t1 + t2 + '0';
                    c[j] = sum;
                    if( c[j] - '0' > 9){
                        c[j] -= 10;
                        if( j == c.size() - 1){
                            c += '1';
                        }else{
                            c[j+1] += 1;
                        }
                    }
                }else{
                    if( c[j] - '0' > 9){
                        c[j] -= 10;
                        if( j == c.size() - 1){
                            c += '1';
                        }else{
                            c[j+1] += 1;
                        }
                    }
                }
            }
            
            if( c.size() > 80){
                cout << "overflow" << endl;
            }else{
                reverse(c.begin(), c.end());
                cout << c << endl;
            }
        }
    }
    
    return 0;
}