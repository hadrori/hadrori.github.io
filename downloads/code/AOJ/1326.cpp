#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
using namespace std;

int main(){
    int p, q;
    while(cin >> p >> q, p || q){
        vector<string> P, Q;
        vector<int> Pind;
        cin.ignore();
        rep(i,p){
            string str; cin >> str;
            P.pb(str);
            int indent = 0;
            rep(j,str.size()){
                if(str[j] != '.') break;
                indent++;
            }
            Pind.pb(indent);
        }
        rep(i,q){
            string str; cin >> str;
            Q.pb(str);
        }
        vector<int> ans(q,-2);
        repi(R,1,21) repi(C,1,21) repi(S,1,21){
            int r = 0, c = 0, s = 0;
            bool ok = true;
            rep(i,p){
                if(R*r+C*c+S*s != Pind[i]){
                    ok = false;
                    break;
                }
                rep(j,P[i].size()){
                    switch (P[i][j]){
                    case '(': r++; break;
                    case ')': r--; break;
                    case '{': c++; break;
                    case '}': c--; break;
                    case '[': s++; break;
                    case ']': s--; break;
                    }
                }
            }
            if(!ok) continue;
            r = 0; c = 0; s = 0;
            rep(i,q){
                int tmp = R*r+C*c+S*s;
                if(ans[i] == -2) ans[i] = tmp;
                else if(ans[i] != tmp) ans[i] = -1;
                rep(j,Q[i].size()){
                    switch (Q[i][j]){
                    case '(': r++; break;
                    case ')': r--; break;
                    case '{': c++; break;
                    case '}': c--; break;
                    case '[': s++; break;
                    case ']': s--; break;
                    }
                }
            }
        }
        rep(i,q) cout << ans[i] << (i==q-1? '\n': ' ');
    }
    return 0;
}
