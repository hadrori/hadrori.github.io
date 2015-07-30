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

int n;
int sc[51][32];
bool scj[51][31];

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 31; j++){
                scj[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            int t;
            cin >> sc[i][0];
            for(int j = 0; j < sc[i][0]; j++){
                cin >> sc[i][j+1];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= sc[i][0]; j++){
                scj[i][sc[i][j]] = true;
            }
        }
        bool have[51][51];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    have[i][j] = true;
                }else{
                    have[i][j] = false;
                }
            }
        }
        int d;
        for(d = 1; d < 31; d++){
            int sum[51] = {false};
            for(int i = 0; i < n; i++){
                if(scj[i][d]){
                    for(int j = 0; j < n; j++) sum[j] |= have[i][j];
                }
            }
            for(int i = 0; i < n; i++){
                if(scj[i][d]){
                    for(int j = 0; j < n; j++) have[i][j] = sum[j];
                }
            }
            
            bool flag = true;
            for(int i = 0; i < n; i++) {
                if(!sum[i]){
                    flag = false;
                }
            }
            if(flag) break;

        }
        if(d < 31) cout << d << endl;
        else cout << -1 << endl;
    }
    return 0;
}