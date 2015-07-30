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

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

int maup, madw;

int t, n;

int block[110];
vector<int> gap;

int main(){
    
    cin >> t;
    rep(k, 0, t){
        cin >> n;
        rep(i, 0, n){
            cin >> block[i];
        }
        gap.clear();
        rep(i, 0, n-1){
            gap.push_back(block[i+1] - block[i]);
        }
        sort(gap.begin(), gap.end());
        maup = gap[gap.size()-1];
        madw = gap[0] * (-1);
        
        if(maup < 0) maup = 0;
        if(madw < 0) madw = 0;
        
        cout << maup << ' ' << madw << endl;
    }
    
    return 0;
}