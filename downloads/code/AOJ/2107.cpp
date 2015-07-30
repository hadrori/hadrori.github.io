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

#define rep(i, a, b) for(ll i = a; i < b; i++)

typedef long long ll;

using namespace std;

ll n, m, z;
bool pass[51][51][51];

int main(){
    
    while(cin >> n >> m >> z, n || m || z){
        rep(i, 0, 50){
            rep(j, 0, 50){
                rep(l, 0, 50) {
                    pass[i][j] = false;
                }
            }
        }
        
        rep(i, 0, m){
            int t1, t2;
            cin >> ti >> t2;
            rep(j, 0, m)pass[j][t1][t2] = true;
            rep(j, 0, m)pass[j][t2][t1] = true;
            pass[t2][t1][t2] = false;
            pass[t1][t1][t2] = false;
            pass[t2][t2][t1] = false;
            pass[t1][t2][t1] = false;
        }
        
        
    }
    
}