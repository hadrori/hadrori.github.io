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

ll maisu, kaisu, ques;
ll nums[300010];

int main(){
    
    cin >> maisu >> kaisu;
    
    rep(i, 0, maisu){
        ll t;
        cin >> t;
        nums[t] = t;
    }
    rep(t, 1, 300010) nums[t] = (nums[t] == 0)? nums[t-1]: nums[t];
    
    rep(i, 0, kaisu){

        cin >> ques;
        
        ll maxa = 0;
        for(int j = ques - 1; j < 300001; j += ques){
            maxa = max(maxa, nums[j] % ques);
        }
        cout << maxa << endl;
        
    }
}