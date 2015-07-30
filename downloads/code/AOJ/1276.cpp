#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,a) for(int i = 0; i < a; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)

#define pb push_back

#define MAX 1300000
#define pMAX 100000

using namespace std;

vector<bool> p(MAX,true);

void calc_p(){
    p[0] = false;
    p[1] = false;

    rep(i,MAX) if(p[i]) for(int j = i*2; j < MAX; j += i) p[j] = false;
    
}

using namespace std;

int main(){
    int k;
    calc_p();

    while(cin >> k, k){
        int rp, lp, i = 0;
        while(!p[k+i]) i++;
        rp = k + i;
        i = 0;
        while(!p[k-i]) i++;
        lp = k - i;

        int ans = rp - lp;
        cout << ans << endl;
    }
}
