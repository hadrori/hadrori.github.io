#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
using namespace std;

int main(){
    string a;
    cin >> a;
    int ans = 0;
    rep(i,a.size()){
        if(i == 0){
            int s = atoi(a.c_str());
            if(s % 2 == 0) ans++;
        }
        else{
            int s = atoi(a.substr(0,i).c_str());
            if(a.substr(i)[0] == '0') continue;
            int t = atoi(a.substr(i).c_str());
            if(s > t) break;
            if((s + t) % 2 == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
