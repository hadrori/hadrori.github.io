#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const string ad = "AADINNUY", az = "AIZUNYAN";
string s, t;

int main(){
    cin >> s;
    rep(i,s.size()-7){
        t = s.substr(i,8);
        sort(begin(t),end(t));
        if(t == ad){
            s = s.substr(0,i)+az+s.substr(i+8);
            i += 7;
        }
    }
    cout << s << endl;
    return 0;
}


