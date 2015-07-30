#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n;

int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        vector<string> str;
        string tmp;
        getline(cin,tmp);
        stringstream ss;
        ss << tmp;
        while(ss >> tmp) str.pb(tmp);
        int a = 0, b = 0;
        rep(i,str.size())if(str[i].size() == 4){
            repi(j,3,26*26)if(__gcd(j,26) == 1){
                rep(k,26){
                    string s = "this", t = "that";
                    rep(u,4){
                        s[u] = (j * (s[u]-'a') + k) % 26 + 'a';
                        t[u] = (j * (t[u]-'a') + k) % 26 + 'a';
                    }
                    if(s == str[i] || t == str[i]){
                        a = j; b = k;
                        break;
                    }
                }
                if(a) break;
            }
            if(a) break;
        }
        string abc = "abcdefghijklmnopqrstuvwxyz";
        rep(i,26) abc[i] = (a * i + b) % 26 + 'a';
        rep(i,str.size()){
            rep(j,str[i].size()) cout << (char)(abc.find(str[i][j]) + 'a');
            cout << (i==str.size()-1? '\n': ' ');
        }
    }
    return 0;
}
